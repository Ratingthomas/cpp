//
// Created by Thomas Levels on 08/03/2024.
//
#include <sstream>
#include "Complex.h"



namespace Complex {
    Complex::Complex(double real, double imag) :
    real_{real},
    imag_{imag}
    {}

    Complex::Complex(std::string number) {
        std::istringstream iss{number.substr(0, number.length() - 1)};
        char sign;
        std::string word;
        iss >> real_ >> sign >> imag_;
        if (sign == '-')
            imag_ = -imag_;

    }

    double Complex::real() const {
        return real_;
    }

    double Complex::imag() const {
        return imag_;
    }

    Complex Complex::add(Complex other) const {
        return (Complex){real() + other.real_, imag() + other.imag_};
    }

    Complex Complex::sub(Complex other) const {
        return (Complex){real() - other.real_, imag() - other.imag_};
    }

    Complex Complex::mul(Complex other) const{
        return (Complex){real() * other.real_ - imag() * other.imag_, real() * other.imag_ + imag() * other.real_};
    }

    Complex Complex::div(Complex other) const{
        double denominator = other.real_ * other.real_ + other.imag_ * other.imag_;
        return (Complex){(real() * other.real_ + imag() * other.imag_) / denominator, (imag() * other.real_ - real() * other.imag_) / denominator};
    }

    double Complex::modulus(Complex other) const{
        return sqrt(other.real_ * other.real_ + other.imag_ * other.imag_);
    }

    double Complex::argument(Complex other) const{
        return atan2(other.imag_, other.real_);
    }
} // Complex