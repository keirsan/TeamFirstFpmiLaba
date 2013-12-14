#pragma once
#include <iostream>

class Rational
{
    friend Rational operator+(Rational, Rational);
    friend Rational operator-(Rational, Rational);
    friend Rational operator*(Rational, Rational);
    friend Rational operator^(Rational, int);
    friend std::ostream& operator<<(std::ostream&, Rational);
public:
    Rational(int, int);
    int getA() const;
    int getB() const;
    ~Rational();
    
private:
    bool sign;
    int a;
    int b;
    void normalView();
};

int LCM(int, int);
int GCD(int, int);

