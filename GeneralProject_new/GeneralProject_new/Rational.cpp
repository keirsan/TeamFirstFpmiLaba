#include <iostream>
#include <math.h>

#include "Rational.h"

Rational::Rational(int x, int y) :a(x), b(y)
{
    normalView();
}

Rational operator+(Rational num1, Rational num2)
{
    int c = LCM(num1.getB(), num2.getB());
    int d = (c / num1.getB())*num1.getA() + (c / num2.getB())*num2.getA();
    return Rational(d, c);
}

Rational operator-(Rational num1, Rational num2)
{
    int c = LCM(num1.getB(), num2.getB());
    int d = (c / num1.getB())*num1.getA() - (c / num2.getB())*num2.getA();
    return Rational(d, c);
}

Rational operator*(Rational num1, Rational num2)
{
    int c = num1.getB() * num2.getB();
    int d = num1.getA() * num2.getA();
    return Rational(d, c);
}

Rational operator^(Rational num1, int power)
{
    int c = pow(num1.getB(), power);
    int d = pow(num1.getA(), power);
    return Rational(d, c);
}

std::ostream& operator<<(std::ostream& out, Rational num)
{
    out << num.getA() << "/" << num.getB() << std::endl;
    return out;
}

void Rational::normalView()
{
    if ((a < 0 || b < 0)&&!(a < 0 && b < 0))
    {
        sign = true;
        a = abs(a);
        b = abs(b);
    }
    while (GCD(a, b) != 1)
    {
        int gcd = GCD(a, b);
        a /= gcd;
        b /= gcd;
    }
    if (sign)
    {
        a *= -1;
    }
}

int Rational::getA() const
{
    return a;
}

int Rational::getB() const
{
    return b;
}

int LCM(int x, int y)
{
    return x / GCD(x, y) * y;
}

int GCD(int x, int y)
{
    while ((x != 0) && (y != 0))
    {
        if (x >= y)
        {
            x = x%y;
        }
        else
        {
            y = y%x;
        }
    }

    return x + y;
}

Rational::~Rational()
{
}
