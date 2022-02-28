//Author: Hong Trinh-438443
// Date 11/03/2021.
//

#include <cmath>
#include <iostream>
#include <iomanip>

#include "Rational.h"

//default constructor
Rational::Rational():
    Rational{1,1}
{}

Rational::Rational(int num, int den):
    m_num{num},
    m_den{den}
{}

Rational::Rational(int num):
    m_num{num},
    m_den{1}
{}

//The parameter is a rational number as string type
//split the string into numerator and denominator
Rational::Rational(const std::string& str) {
    size_t pos = str.find('/');
    m_num = std::stoi(str.substr(0,pos));
    m_den = std::stoi(str.substr(pos+1));
}

//getter
int Rational::num() {
    return m_num;
}

int Rational::den() {
    return m_den;
}

//setter
void Rational::set_num(int num) {
    m_num = num;
    simplify();
}

void Rational::set_den(int den) {
    m_den = den;
    simplify();
}

//convert rational number to string  (numerator/denominator)
std::string Rational::to_str() {
    if (m_den < 0)
    {
        m_num= -m_num;
        m_den = -m_num;
    }
    return std::to_string(m_num) + '/' + std::to_string(m_den);
}

//calculating the greatest common divisor of two number
int Rational::gcd(int x, int y) {
    //make both number are positive
    x = abs(x);
    y = abs(y);
    if (y < 0) y = -y;
    if(x == 0 && y !=0){return y;}
    else if( y == 0 && x != 0 ){return x;}
    while(x != y){
        if(x > y){
            x = x - y;
        }
        else y = y - x;
    }
    return x;
}

double Rational::to_double() const {
    double res = double(m_num)/double(m_den);
    res = std::ceil(res * 10.0)/10.0;
    return res;
}

bool Rational::is_positive() const {
    if((m_num > 0 && m_den > 0) | (m_num < 0 && m_den < 0)){
        return true;
    }
    return false;
}

//check if rational number is negative
bool Rational::is_negative() const {
    if(m_num < 0 || m_den < 0){
        return true;
    }
    return false;
}

bool Rational::is_inf() const {
    if(m_den == 0 && m_num!=0){
        return true;
    }
    return false;
}

bool Rational::is_nan() const {
    if(m_num == 0 && m_den ==  0){
        return true;
    }
    return false;
}





