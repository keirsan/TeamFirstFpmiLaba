#pragma once
#include "Complex.h"
using namespace std;
class Polynom
{
private:
    int/*double*/ coeff[1000];
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

    Polynom operator+(Polynom);
    Polynom operator-(Polynom);
    Polynom operator*(Polynom);

    /*Polynom();
    Polynom(const Polynom&);*/
    Polynom(double);
    Polynom(int deg, int val);
    /*void getPolynom();
    void setPolynom(int);
    double polValue(double);
    void mult(const Polynom&,  const Polynom& );
    void operator=(const Polynom&);
    Polynom operator+(const Polynom&);
    void operator+=(const Polynom&);
    Polynom operator-(const Polynom&);
    void operator-=(const Polynom&);
    Polynom operator*(const Polynom&);
    void operator*=(const Polynom&);
    Polynom substitution(Polynom);
    int& operator[](int);*/
    friend std::ostream& operator<<(std::ostream&, const Polynom&);//how to do this weird function?
    /*friend std::istream& operator>>(std::istream&, Polynom&);*/
};