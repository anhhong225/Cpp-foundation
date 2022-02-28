//Author: Hong Trinh
// Date 11/03/2021.
//

#ifndef ASSIGNMENT3_RATIONAL_H
#define ASSIGNMENT3_RATIONAL_H


#include <string>

class Rational {
public:
    // constructors:
    Rational(); //default constructor
    Rational(int num , int den);
    Rational(int num);
    Rational(const std::string& str);

// accessors(getter)
    int num(); //return value of numerator
    int den(); //return value of denominator

    // modifiers(setter)
    void set_num(int num);
    void set_den(int den);

    std::string to_str();
    double to_double() const;
    static int gcd(int x, int y);

    bool is_positive() const;
    bool is_negative() const;
    bool is_inf() const;
    bool is_nan() const;



private:
    // data members
    int m_num;
    int m_den;
    void simplify() {
        int ra_gcd{gcd(m_num,m_den)};
        if (m_den < 0)
        {
            m_num = - m_num;
            m_den = - m_den;
        }
        m_num /= ra_gcd;
        m_den /= ra_gcd;
    }
};


#endif //ASSIGNMENT3_RATIONAL_H
