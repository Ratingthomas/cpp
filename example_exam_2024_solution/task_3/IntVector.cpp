#include "IntVector.h"

#include <algorithm>
#include <stdexcept>

namespace exam
{
    static const std::size_t INITIAL_CAPACITY = 16;

    IntVector::IntVector()
        : size_{0}, capacity_{INITIAL_CAPACITY}, data_{new long[capacity_]}
    {
    }

    // copy constructor: allocates memory & copies contents of other into it
    IntVector::IntVector(const IntVector &other)
        : size_{other.size_}, capacity_{other.capacity_},
        data_{new long[capacity_]}
    {
        // if you don't know `copy`, then use a plain old for loop:
//        for (size_t i = 0; i < other.size_; ++i) {
//            data_[i] = other.data_[i];
//        }
        // using std::copy:
        std::copy(&other.data_[0], &other.data_[size_], data_);
    }

    void IntVector::push_back(long value)
    {
        ensure_capacity(size_ + 1);
//        if (size_ == capacity_)
//        {
//           throw std::runtime_error("IntVector::push_back: capacity exceeded");
//        }
        data_[size_++] = value;
    }

    std::size_t IntVector::size() const
    {
        return size_;
    }

    long IntVector::operator[](std::size_t index) const
    {
        return data_[index];
    }

    long* IntVector::begin()
    {
        return data_;
    }

    long* IntVector::end()
    {
        return data_ + size_;
    }

    const long* IntVector::begin() const
    {
        return data_;
    }

    const long* IntVector::end() const
    {
        return data_ + size_;
    }

    void IntVector::sort()
    {
        std::sort(begin(), end());
    }

    void IntVector::unique()
    {
        // an ugly quadratic, manual implementation of unique. but hey, it's at least stable!
        auto current = begin();
        auto last = end();
        while (current != last)
        {
            auto next = current + 1;
            while (next != last)
            {
                if (*current == *next)
                {
                    std::copy(next + 1, last, next);
                    --last;
                }
                else
                {
                    ++next;
                }
            }
            ++current;
        }
        size_ = last - begin();
    }

    IntVector::~IntVector() {
        delete[] data_;
    }

    IntVector &IntVector::operator=(const IntVector &other) {
        // TODO:
        //  1) allocate new memory to hold a copy of other
        //  2) copy contents of other to new memory
        //  3) free "old" contents, replace with new
        if (this != &other) {
            // option 1: use copy-ctor and swap
            IntVector copy{other};
            std::swap(data_, copy.data_);
            std::swap(size_, copy.size_);
            std::swap(capacity_, copy.capacity_);

            // option 2: manual steps, repeating code
//            auto ptr = new long[other.capacity_];
//            std::copy(&other.data_[0], &other.data_[other.size_], ptr);
//            delete[] data_;
//            data_ = ptr;
//            size_ = other.size_;
//            capacity_ = other.capacity_;
        }
        return *this;
    }

    void IntVector::ensure_capacity(size_t min_cap) {
        if (min_cap <= capacity_) return;    // nothing to do if we already have enough capacity
        size_t new_capacity = capacity_;

        // we could do this:
        //    new_capacity = min_cap
        // but this is not a good way to grow a dynamic array
        // instead, this loop ensures that capacity grows at a rate of about 1.5
        while (new_capacity < min_cap) new_capacity = (new_capacity + 1) * 3 / 2;

        // first allocate memory, before throwing away our current memory
        // (how else are we supposed to move contents from old to new?)
        auto ptr = new long[new_capacity];

        // technically, we're moving data instead of copying it
        //  (the detail does not matter much for `long`s, but still)
        std::move(&data_[0], &data_[size_], ptr);

        // clean up old memory
        delete[] data_;

        // point to new memory
        data_ = ptr;

        // don't forget to update our capacity_ to the new capacity!
        capacity_ = new_capacity;
    }

}