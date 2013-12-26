#pragma once
#include "Complex.h"
using namespace std;
class Polynom
{
private:
    Complex<int> * coefI;
    Complex<BigInt> * coefB;
    Complex<Rational> * coefR;
    Complex<double>  * coefD;
    int degree;
public:
    Polynom(Complex<int>, int);
    Polynom(Complex<BigInt>, int);
    Polynom(Complex<Rational>, int);
    Polynom(Complex<double>, int);
    Polynom(Complex<int>, int, int);
    Polynom(Complex<BigInt>, int, int);
    Polynom(Complex<Rational>, int, int);
    Polynom(Complex<double>, int, int);
    Polynom(const Polynom&);

    Polynom operator+(Polynom);
    Polynom operator-(Polynom);
    Polynom operator*(Polynom);
    Polynom operator^(Polynom);

    Polynom();
    Polynom(int deg, int val);
    Polynom substitution(Polynom);

    friend std::ostream& operator<<(std::ostream&, const Polynom&);
};