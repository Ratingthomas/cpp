//
// Created by Thomas Levels on 08/03/2024.
//

#ifndef PR_WEEK_3_COMPLEX_H
#define PR_WEEK_3_COMPLEX_H
#include <iostream>

namespace Complex {
    class Complex {
        public:
            Complex(double real, double imag);
            Complex(std::string);

            Complex add(Complex other) const;
            Complex sub(Complex other) const;
            Complex mul(Complex other) const;
            Complex div(Complex other) const;
            double modulus(Complex other) const;
            double argument(Complex other) const;

            double real() const;
            double imag() const;

        private:
            double real_;
            double imag_;
    };

    inline std::ostream& operator<<(std::ostream& out, Complex const& c)
    {
        return out << c.real() << (c.imag() < 0.0? "-" : "+") << std::abs(c.imag()) << "i";
    }

} // Complex




#endif //PR_WEEK_3_COMPLEX_H
