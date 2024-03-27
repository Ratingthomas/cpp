#include "numbers.h"

#include <algorithm>
#include <stdexcept>
#include <iostream>

namespace numeric
{
    static constexpr std::size_t INITIAL_CAPACITY = 16;

    Numbers::Numbers() : 
        array_(new double[INITIAL_CAPACITY]{}), 
        size_(0), 
        capacity_(INITIAL_CAPACITY)
    {
    }

    Numbers::Numbers(numeric::Numbers &other) :
        array_(other.array_),
        size_(other.size_),
        capacity_(other.capacity_)
    {}

    Numbers::~Numbers()
    {
        delete[] array_;
    }

    std::size_t Numbers::size() const
    {
        return size_;
    }

    void Numbers::push_back(double value)
    {
        if (size_ == capacity_)
        {
            capacity_ *= 2;
            double * temp = new double[capacity_];
            std::copy(begin(), end(), temp);
            delete[] array_;
            array_ = temp;
        }
        array_[size_++] = value;
    }

    double Numbers::pop_back()
    {
        if (size_ == 0)
        {
            throw std::out_of_range("pop_back() called on empty Numbers object");
        }
        return array_[--size_];
    }

    double Numbers::front() const
    {
        if (size_ == 0)
        {
            throw std::out_of_range("front() called on empty Numbers object");
        }
        return array_[0];
    }

    double& Numbers::front()
    {
        if (size_ == 0)
        {
            throw std::out_of_range("front() called on empty Numbers object");
        }
        return array_[0];
    }

    double Numbers::back() const
    {
        if (size_ == 0)
        {
            throw std::out_of_range("back() called on empty Numbers object");
        }
        return array_[size_ - 1];
    }

    double& Numbers::back()
    {
        if (size_ == 0)
        {
            throw std::out_of_range("back() called on empty Numbers object");
        }
        return array_[size_ - 1];
    }

    double * Numbers::begin()
    {
        return array_;
    }

    double * Numbers::end()
    {
        return array_ + size_;
    }

    const double * Numbers::begin() const
    {
        return array_;
    }

    const double * Numbers::end() const
    {
        return array_ + size_;
    }

    double Numbers::at(std::size_t index) const
    {
        if (index >= size_)
        {
            throw std::out_of_range("at() called with index out of range");
        }
        return array_[index];
    }

    double& Numbers::at(std::size_t index)
    {
        if (index >= size_)
        {
            throw std::out_of_range("at() called with index out of range");
        }
        return array_[index];
    }

    double Numbers::operator[](std::size_t index) const
    {
        return array_[index];
    }

    double& Numbers::operator[](std::size_t index)
    {
        return array_[index];
    }

    void Numbers::swap(numeric::Numbers &other) {
        std::swap(array_, other.array_);
        std::swap(size_, other.size_);
        std::swap(capacity_, other.capacity_);
    }

    Numbers Numbers::clone() const {
        Numbers tmp{};

        tmp.array_ = array_;
        tmp.size_ = size_;
        tmp.capacity_ = capacity_;

        return tmp;
    }

    std::ostream& operator==(std::ostream& os, const Numbers& numbers){

    }


    std::ostream& operator<<(std::ostream& os, const Numbers& numbers)
    {
        os << "Numbers {capacity: " << numbers.capacity_ << ", size: " << numbers.size_ << "}: ";
        os << "[";
        if (numbers.size() > 0)
        {
            os << numbers[0];
            // if size is greater than 20 only print the first 10 and last 10
            if (numbers.size() > 20)
            {
                for (std::size_t i = 1; i < 10; ++i)
                {
                    os << ", " << numbers[i];
                }
                os << ", ...";
                for (std::size_t i = numbers.size() - 10; i < numbers.size(); ++i)
                {
                    os << ", " << numbers[i];
                }
            }
            else{
                for (std::size_t i = 1; i < numbers.size(); ++i)
                {
                    os << ", " << numbers[i];
                }
            }
        }
        os << "]";
        return os;
    }

}