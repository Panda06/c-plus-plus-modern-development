#include <cmath>
#include <exception>
#include <iostream>

int GreatestCommonDivisor(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return GreatestCommonDivisor(b, a % b);
    }
}

class Rational {
public:
    Rational() {
        numerator = 0;
        denominator = 1;
    }
    Rational(int _numerator, int _denominator) {
        if (_denominator == 0) {
            throw std::invalid_argument("");
        }
        int gcd = GreatestCommonDivisor(_numerator, _denominator);
        numerator = _numerator / gcd;
        denominator = _denominator / gcd;
        if (denominator < 0) {
            denominator = -denominator;
            numerator = -numerator;
        }
    }

    int Numerator() const {
        return numerator;
    }

    int Denominator() const {
        return denominator;
    }
private:
    int numerator;
    int denominator;
};

bool operator== (const Rational& lhs, const Rational& rhs) {
    return lhs.Numerator() == rhs.Numerator() &&
           lhs.Denominator() == rhs.Denominator();
}

Rational operator+ (const Rational& lhs, const Rational& rhs) {
    int denominator = lhs.Denominator() * rhs.Denominator();
    int numerator = lhs.Denominator() * rhs.Numerator();
    numerator += rhs.Denominator() * lhs.Numerator();
    return Rational(numerator, denominator);
}

Rational operator- (const Rational& lhs, const Rational& rhs) {
    int denominator = lhs.Denominator() * rhs.Denominator();
    int numerator = rhs.Denominator() * lhs.Numerator();
    numerator -= lhs.Denominator() * rhs.Numerator();
    return Rational(numerator, denominator);
}

Rational operator* (const Rational& lhs, const Rational& rhs) {
    return Rational(lhs.Numerator()*rhs.Numerator(),
                    lhs.Denominator()*rhs.Denominator());
}
Rational operator/ (const Rational& lhs, const Rational& rhs) {
    if (rhs.Numerator() == 0) {
        throw std::domain_error("");
    }
    return lhs * Rational(rhs.Denominator(), rhs.Numerator());
}
std::istream& operator>>(std::istream& stream, Rational& r) {
    int n, d;
    char c;
    stream >> n >> c >> d;
    if (stream && c == '/') {
        r = Rational(n, d);
    }
    return stream;
}
std::ostream& operator<<(std::ostream& stream, const Rational& r) {
    stream << r.Numerator() << "/" << r.Denominator();
    return stream;
}

bool operator<(const Rational& lhs, const Rational& rhs) {
    return (double(lhs.Numerator())/lhs.Denominator()) <
           (double(rhs.Numerator())/rhs.Denominator());

}
int main() {
    Rational r = Rational(1, 2) + Rational(1, 3) - Rational(1, 4);
    if (r == Rational(7, 12)) {
        std::cout << "equal";
    }
    std::cout << r.Numerator() << '/' << r.Denominator();
    std::cout << "OK" << std::endl;
    r = Rational(1, 2) * Rational(1, 3) / Rational(1, 4);
    if (r == Rational(2, 3)) {
        std::cout << "equal";
    }
    return 0;
}
