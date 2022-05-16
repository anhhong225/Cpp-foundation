#ifndef ASSIGNMENT7_RATIONAL_H
#define ASSIGNMENT7_RATIONAL_H


#include <string>

class rational {
public:
    rational();
    rational(int numerator, int denominator);
    explicit rational(int numerator);

    rational(const std::string& str);

    int num() const;
    int den() const;
    int num();
    int den();

    std::string to_str();
    double to_double() const;
    static int gcd(int x, int y);

    bool is_positive() const;
    bool is_negative() const;

    bool is_inf() const;
    bool is_nan() const;

    rational& operator+=(const rational& other);
    rational& operator-=(const rational& other);
    rational& operator*=(const rational& other);
    rational& operator/=(const rational& other);

    bool operator==(const rational& rhs);
    bool operator!=(const rational& rhs);
    bool operator>(const rational& rhs);
    bool operator<(const rational& rhs);
    bool operator>=(const rational& rhs);
    bool operator<=(const rational& rhs);

    friend rational operator+(const rational& lhs, const rational& rhs);
private:
    int m_numerator;
    int m_denominator;
    void simplify() {
        int ra_gcd{gcd(m_numerator,m_denominator)};
        if (m_denominator < 0)
        {
            m_numerator = - m_numerator;
            m_denominator = - m_denominator;
        }
        m_numerator /= ra_gcd;
        m_denominator /= ra_gcd;
    }
};

rational operator+(const rational& lhs, const rational& rhs);
rational operator-(const rational& lhs, const rational& rhs);
rational operator*(const rational& lhs, const rational& rhs);
rational operator/(const rational& lhs, const rational& rhs);
std::ostream & operator<<(std::ostream& out, rational r);
#endif //ASSIGNMENT7_RATIONAL_H
