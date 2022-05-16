
#include <cmath>
#include <iostream>
#include "rational.h"

rational::rational():rational{1,1}{}

rational::rational(int numerator, int denominator):m_numerator{numerator},m_denominator{denominator}{

}

rational::rational(int numerator):m_numerator{numerator},m_denominator{1}{

}

rational::rational(const std::string &str) {
    size_t pos = str.find('/');
    m_numerator = std::stoi(str.substr(0,pos));
    m_denominator = std::stoi(str.substr(pos+1));
}

int rational::num() const {
    return m_numerator;
}

int rational::den() const {
    return m_denominator;
}

int rational::num() {
    return m_numerator;
}

int rational::den() {
    return m_denominator;
}

std::string rational::to_str() {
    if(is_inf()) return "infinity";
    else if(is_nan()) return "NaN";
    else if(m_denominator < 0){
        m_numerator = -m_numerator;
        m_denominator = -m_numerator;
    }
    return std::to_string(m_numerator) + '/' + std::to_string(m_denominator);
}

double rational::to_double() const {
    if(!is_inf() && !is_nan()){
        double res = double(m_numerator)/double(m_denominator);
        res = std::ceil(res * 10.0)/10.0;
        return res;
    }
}

int rational::gcd(int x, int y) {
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

bool rational::is_positive() const {
    if((m_numerator > 0 && m_denominator > 0) | (m_numerator < 0 && m_denominator < 0)){
        return true;
    }
    return false;
}

bool rational::is_negative() const {
    if(m_numerator < 0 || m_denominator < 0){
        return true;
    }
    return false;
}

bool rational::is_inf() const {
    if(m_denominator == 0 && m_numerator!=0){
        return true;
    }
    return false;
}

bool rational::is_nan() const {
    if(m_numerator == 0 && m_denominator ==  0){
        return true;
    }
    return false;
}

rational &rational::operator+=(const rational &other) {
    if(this->is_nan() && other.is_nan()) std::cout << "(NaN)";
    else if(this->is_inf() || other.is_inf()) std::cout << "(inf)";
    else{
        this->m_numerator = (this->num()*other.den()+this->den()*other.num());
        this->m_denominator = (this->den()*other.den());
    }
    this->simplify();
    return *this;
}

rational &rational::operator-=(const rational &other) {
    if(this->is_nan() && other.is_nan()) std::cout << "(NaN)";
    else if(this->is_inf() || other.is_inf()) std::cout << "(inf)";
    else{
        this->m_numerator = (this->num()*other.den()-this->den()*other.num());
        this->m_denominator = (this->den()*other.den());
    }
    this->simplify();
    return *this;
}

rational &rational::operator*=(const rational &other) {
    if(this->is_nan() || other.is_nan()) std::cout << "(NaN)";
    else if(this->is_inf() || other.is_inf()) std::cout << "(inf)";
    else{
        this->m_numerator = (this->num()*other.num());
        this->m_denominator = (this->den()*other.den());
    }
    this->simplify();
    return *this;
}

rational &rational::operator/=(const rational &other) {
    if(this->is_nan() || other.is_nan()) std::cout << "(NaN)";
    else if(this->is_inf() || other.is_inf()) std::cout << "(inf)";
    else{
        this->m_numerator = (this->num()*other.den());
        this->m_denominator = (this->den()*other.num());
    }
    this->simplify();
    return *this;
}

bool rational::operator==(const rational &rhs) {
    if(this->is_nan() || rhs.is_nan()) return false;
    else if(this->is_inf() || rhs.is_inf()) return false;
    else if((this->m_numerator * rhs.m_numerator) && (this->m_denominator * rhs.m_denominator))
        return true;
    else
        return false;
}

bool rational::operator!=(const rational &rhs) {
    if(this->is_nan() || rhs.is_nan()) return true;
    else if(this->is_inf() || rhs.is_inf()) return true;
    else if((this->m_numerator * rhs.m_numerator) && (this->m_denominator * rhs.m_denominator))
        return false;
    else
        return true;
}

bool rational::operator>(const rational &rhs) {
    if(this->is_nan() || rhs.is_nan()) return false;
    else if(this->is_inf() || rhs.is_inf()) return false;
    else if((this->m_numerator * rhs.m_denominator) > (rhs.m_numerator*this->m_denominator))
        return true;
    else return false;
}

bool rational::operator<(const rational &rhs) {
    if(this->is_nan() || rhs.is_nan()) return false;
    else if(this->is_inf() || rhs.is_inf()) return false;
    else if((this->m_numerator * rhs.m_denominator) < (rhs.m_numerator*this->m_denominator))
        return true;
    else return false;
}

bool rational::operator>=(const rational &rhs) {
    if(this->is_nan() || rhs.is_nan()) return false;
    else if(this->is_inf() || rhs.is_inf()) return false;
    else if((this->m_numerator * rhs.m_denominator) >= (rhs.m_numerator*this->m_denominator))
        return true;
    else return false;
}

bool rational::operator<=(const rational &rhs) {
    if(this->is_nan() || rhs.is_nan()) return false;
    else if(this->is_inf() || rhs.is_inf()) return false;
    else if((this->m_numerator * rhs.m_denominator) <= (rhs.m_numerator*this->m_denominator))
        return true;
    else return false;
}

rational operator+(const rational& lhs, const rational& rhs){
    int num{},den{};
    if(lhs.is_nan() && rhs.is_nan()) std::cout << "(NaN)";
    else if(lhs.is_inf() || rhs.is_inf()) std::cout << "(inf)";
    else{
        num = (lhs.num()*rhs.den()+lhs.den()*rhs.num());
        den = (lhs.den()*rhs.den());
    }
    return rational{num,den};
}
rational operator-(const rational& lhs, const rational& rhs){
    int num{},den{};
    if(lhs.is_nan() && rhs.is_nan()) std::cout << "(NaN)";
    else if(lhs.is_inf() || rhs.is_inf()) std::cout << "(inf)";
    else{
        num = (lhs.num()*rhs.den()-lhs.den()*rhs.num());
        den = (lhs.den()*rhs.den());
    }
    return rational{num,den};
}
rational operator*(const rational& lhs, const rational& rhs){
    int num{},den{};
    if(lhs.is_nan() && rhs.is_nan()) std::cout << "(NaN)";
    else if(lhs.is_inf() || rhs.is_inf()) std::cout << "(inf)";
    else{
        num = (lhs.num()*rhs.num());
        den = (lhs.den()*rhs.den());
    }
    return rational{num,den};
}
rational operator/(const rational& lhs, const rational& rhs){
    int num{},den{};
    if(lhs.is_nan() && rhs.is_nan()) std::cout << "(NaN)";
    else if(lhs.is_inf() || rhs.is_inf()) std::cout << "(inf)";
    else{
        num = (lhs.num()*rhs.den());
        den = (lhs.den()*rhs.num());
    }
    return rational{num,den};
}
std::ostream & operator<<(std::ostream& out, rational r){
    out << r.to_str();
    return out;
}