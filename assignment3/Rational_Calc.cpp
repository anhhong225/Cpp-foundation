//Author: Hong Trinh-438443
//Date 12/03/2021.
//The class includes functions to calculate the expression
#include <cmath>
#include <algorithm>
#include <iostream>
#include <sstream>

#include "Rational_Calc.h"

Rational Rational_Calc::add(Rational& rat1, Rational& rat2) {
    Rational result;
    if(rat1.is_nan() && rat2.is_nan()) std::cout << "(NaN)";
    else if(rat1.is_inf() || rat2.is_inf()) std::cout << "(inf)";
    else{
        result.set_num(rat1.num()*rat2.den()+rat1.den()*rat2.num());
        result.set_den(rat1.den()*rat2.den());
    }
    return result;
}

Rational Rational_Calc::subtract(Rational& rat1, Rational& rat2) {
    Rational result;
    if(rat1.is_nan() && rat2.is_nan()) std::cout << "(NaN)";
    else if(rat1.is_inf() || rat2.is_inf()) std::cout << "(inf)";
    else{
        result.set_num(rat1.num()*rat2.den() - rat1.den()*rat2.num());
        result.set_den(rat1.den()*rat2.den());
    }
    return result;
}

Rational Rational_Calc::multiply(Rational& rat1, Rational& rat2) {
    Rational result;
    if(rat1.is_nan() || rat2.is_nan()) std::cout << "(NaN)";
    else if(rat1.is_inf() || rat2.is_inf()) std::cout << "(inf)";
    else{
        result.set_num(rat1.num()*rat2.num());
        result.set_den(rat1.den()*rat2.den());
    }
    return result;
}

Rational Rational_Calc::division(Rational& rat1, Rational& rat2) {
    Rational result;
    if(rat1.is_nan() || rat2.is_nan()) std::cout << "(NaN)";
    else if(rat1.is_inf() || rat2.is_inf()) std::cout << "(inf)";
    else{
        result.set_num(rat1.num()*rat2.den());
        result.set_den(rat1.den()*rat2.num());
    }
    return result;
}

Rational Rational_Calc::pow(Rational &rat, int p) {
    Rational result{rat};
    Rational temp{rat};
    if(rat.is_nan()) std::cout << "(NaN)";
    else if(rat.is_inf()) std::cout << "(inf)";
    else if (p == 0)
    {
        result = 1;
    }
    else
    {
        for (auto i = 1; i < p; i++)
        {
            result.set_num(result.num()*temp.num());
            result.set_den(result.den()*temp.den());
        }
    }
    return result;
}

Rational Rational_Calc::sqrt(Rational rat) {
    Rational result;
    if (isdigit(rat.den()) && isdigit(rat.num())) {
        if(rat.is_nan() || rat.is_negative() || rat.is_inf()){
            std::cout << "NaN\n";
        } else{
            result = std::sqrt(rat.to_double());
        }
    } else std::cout << "NaN\n";
    return result;
}

//The function calculation have a string parameter
//The parameter expression is a line from input file or typing by user
//split the expression into string type rational numbers and character type operator
//pass the string rational numbers to the constructor with string type
Rational Rational_Calc::calculate(const std::string& expression) {
    Rational rat1, rat2, result;
    std::string str[2];
    char op;
    int p;
    std::stringstream ss{expression}; //create a stream for string
    ss >> str[0] >> op >> str[1];
    if(op == '^'){                  //checking if the operator is power
        rat1 = Rational(str[0]);//the first element is base and the second is exponent
        p = std::stoi(str[1]);//convert string to integer
    }else {
        rat1 = Rational(str[0]);//if not a power operator both elements is rational number
        rat2 = Rational(str[1]);//passing to the constructor of Rational
    }
    //Checking the which type of constructor and calculating the expression
    switch (op) {
        case '+':
            result = add(rat1,rat2);
            break;
        case '-':
            result = subtract(rat1,rat2);
            break;
        case '*':
            result = multiply(rat1,rat2);
            break;
        case '/':
            result = division(rat1, rat2);
            break;
        case '^':
            result = pow(rat1, p);
            break;
        default:
            break;
    }
    return result;
}



