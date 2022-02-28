//Author: Hong Trinh
// Date 12/03/2021.
//

#ifndef ASSIGNMENT3_RATIONAL_CALC_H
#define ASSIGNMENT3_RATIONAL_CALC_H


#include "Rational.h"

class Rational_Calc {
public:
    static Rational add(Rational& rat1, Rational& rat2);
    static Rational subtract(Rational& rat1, Rational& rat2);
    static Rational multiply(Rational& rat1, Rational& rat2);
    static Rational division(Rational& rat1, Rational& rat2);

    static Rational pow(Rational &rat, int p);
    static Rational sqrt(Rational rat);

    static Rational calculate(const std::string& expression);
};


#endif //ASSIGNMENT3_RATIONAL_CALC_H
