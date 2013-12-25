#pragma once
#include <iostream>
#include "BigInt.h"
#include "Rational.h"

using namespace std;

template <class type1>
class Complex
{
    type1 re;
    type1 im;
    Complex add(Complex &c);
    Complex add1(Complex &c);
    Complex add2(Complex &c);
public:
    Complex();
    Complex(type1 r, type1 i);
    Complex(type1 r);
    Complex(Complex &c);
    ~Complex();

    template<class type1> friend ostream & operator<<(std::ostream & os, Complex<type1> & number);

    friend Complex<double> operator+(Complex<int> c1, Complex<double> c2);
    friend Complex<double> operator+(Complex<double> c1, Complex<int> c2);
    friend Complex<double> operator+(Complex<BigInt> c1, Complex<double> c2);
    friend Complex<double> operator+(Complex<double> c1, Complex<BigInt> c2);
    friend Complex<double> operator+(Complex<Rational> c1, Complex<double> c2);
    friend Complex<double> operator+(Complex<double> c1, Complex<Rational> c2);
    friend Complex<double> operator+(Complex<double> c1, Complex<double> c2);
    friend Complex<Rational> operator+(Complex<BigInt> c1, Complex<Rational> c2);
    friend Complex<Rational> operator+(Complex<Rational> c1, Complex<BigInt> c2);
    friend Complex<Rational> operator+(Complex<int> c1, Complex<Rational> c2);
    friend Complex<Rational> operator+(Complex<Rational> c1, Complex<int> c2);
    friend Complex<Rational> operator+(Complex<Rational> c1, Complex<Rational> c2);
    friend Complex<BigInt> operator+(Complex<int> c1, Complex<BigInt> c2);
    friend Complex<BigInt> operator+(Complex<BigInt> c1, Complex<int> c2);
    friend Complex<BigInt> operator+(Complex<BigInt> c1, Complex<BigInt> c2);
    friend Complex<int> operator+(Complex<int> c1, Complex<int> c2);

    friend Complex<double> operator-(Complex<int> c1, Complex<double> c2);
    friend Complex<double> operator-(Complex<double> c1, Complex<int> c2);
    friend Complex<double> operator-(Complex<BigInt> c1, Complex<double> c2);
    friend Complex<double> operator-(Complex<double> c1, Complex<BigInt> c2);
    friend Complex<double> operator-(Complex<Rational> c1, Complex<double> c2);
    friend Complex<double> operator-(Complex<double> c1, Complex<Rational> c2);
    friend Complex<double> operator-(Complex<double> c1, Complex<double> c2);
    friend Complex<Rational> operator-(Complex<BigInt> c1, Complex<Rational> c2);
    friend Complex<Rational> operator-(Complex<Rational> c1, Complex<BigInt> c2);
    friend Complex<Rational> operator-(Complex<int> c1, Complex<Rational> c2);
    friend Complex<Rational> operator-(Complex<Rational> c1, Complex<int> c2);
    friend Complex<Rational> operator-(Complex<Rational> c1, Complex<Rational> c2);
    friend Complex<BigInt> operator-(Complex<int> c1, Complex<BigInt> c2);
    friend Complex<BigInt> operator-(Complex<BigInt> c1, Complex<int> c2);
    friend Complex<BigInt> operator-(Complex<BigInt> c1, Complex<BigInt> c2);
    friend Complex<int> operator-(Complex<int> c1, Complex<int> c2);

    friend Complex<double> operator*(Complex<int> c1, Complex<double> c2);
    friend Complex<double> operator*(Complex<double> c1, Complex<int> c2);
    friend Complex<double> operator*(Complex<BigInt> c1, Complex<double> c2);
    friend Complex<double> operator*(Complex<double> c1, Complex<BigInt> c2);
    friend Complex<double> operator*(Complex<Rational> c1, Complex<double> c2);
    friend Complex<double> operator*(Complex<double> c1, Complex<Rational> c2);
    friend Complex<double> operator*(Complex<double> c1, Complex<double> c2);
    friend Complex<Rational> operator*(Complex<BigInt> c1, Complex<Rational> c2);
    friend Complex<Rational> operator*(Complex<Rational> c1, Complex<BigInt> c2);
    friend Complex<Rational> operator*(Complex<int> c1, Complex<Rational> c2);
    friend Complex<Rational> operator*(Complex<Rational> c1, Complex<int> c2);
    friend Complex<Rational> operator*(Complex<Rational> c1, Complex<Rational> c2);
    friend Complex<BigInt> operator*(Complex<int> c1, Complex<BigInt> c2);
    friend Complex<BigInt> operator*(Complex<BigInt> c1, Complex<int> c2);
    friend Complex<BigInt> operator*(Complex<BigInt> c1, Complex<BigInt> c2);
    friend Complex<int> operator*(Complex<int> c1, Complex<int> c2);
};

template <class type1>
ostream & operator<<(ostream&  out, Complex<type1> & number)
{
    bool isPrinted = false;
    if (number.re > 0 || number.re < 0)
    {
        isPrinted = true;
        out << number.re;
        if (number.im > 0)
            out << "+";
    }
    if (number.im > 0 || number.im < 0)
    {
        isPrinted = true;
        out << number.im << "i";
    }
    if (!isPrinted)
        out << 0;
    return out;
}
//---------------------------------------------------------------------------------------
//operator -

inline Complex<double> operator-(Complex<int> c1, Complex<double> c2)
{
    Complex<double> temp((double)c1.re, (double)c1.im);
    return temp.add1(c2);
}

inline Complex<double> operator-(Complex<double> c1, Complex<int> c2)
{
    Complex<double> temp((double)c2.re, (double)c2.im);
    return temp.add1(c1);
}

inline Complex<double> operator-(Complex<Rational> c1, Complex<double> c2)
{
    Complex<double> temp(c1.re.getDouble(), c1.im.getDouble());
    return temp.add1(c2);
}

inline Complex<double> operator-(Complex<double> c1, Complex<Rational> c2)
{
    Complex<double> temp(c2.re.getDouble(), c2.im.getDouble());
    return temp.add1(c1);
}

inline Complex<double> operator-(Complex<BigInt> c1, Complex<double> c2)
{
    Complex<double> temp((double)c1.re.getLongLong(), (double)c1.im.getLongLong());
    return temp.add1(c2);
}

inline Complex<double> operator-(Complex<double> c1, Complex<BigInt> c2)
{
    Complex<double> temp((double)c2.re.getLongLong(), (double)c2.im.getLongLong());
    return temp.add1(c1);
}

inline Complex<double> operator-(Complex<double> c1, Complex<double> c2)
{
    return c1.add1(c2);
}

inline Complex<Rational> operator-(Complex<BigInt> c1, Complex<Rational> c2)
{
    Rational temp1(c1.re.getInt(), 1);
    Rational temp2(c1.im.getInt(), 1);
    Complex<Rational> temp(temp1, temp2);
    return temp.add1(c2);
}

inline Complex<Rational> operator-(Complex<Rational> c1, Complex<BigInt> c2)
{
    Rational temp1(c2.re.getInt(), 1);
    Rational temp2(c2.im.getInt(), 1);
    Complex<Rational> temp(temp1, temp2);
    return temp.add1(c1);
}

inline Complex<Rational> operator-(Complex<int> c1, Complex<Rational> c2)
{
    Rational temp1(c1.re);
    Rational temp2(c1.im);
    Complex<Rational> temp(temp1, temp2);
    return temp.add1(c2);
}

inline Complex<Rational> operator-(Complex<Rational> c1, Complex<int> c2)
{
    Rational temp1(c2.re);
    Rational temp2(c2.im);
    Complex<Rational> temp(temp1, temp2);
    return temp.add1(c1);
}

inline Complex<Rational> operator-(Complex<Rational> c1, Complex<Rational> c2)
{
    return c1.add1(c2);
}

inline Complex<BigInt> operator-(Complex<int> c1, Complex<BigInt> c2)
{
    BigInt temp1(c1.re);
    BigInt temp2(c1.im);
    Complex<BigInt> temp(temp1, temp2);
    return temp.add1(c2);
}

inline Complex<BigInt> operator-(Complex<BigInt> c1, Complex<int> c2)
{
    BigInt temp1(c2.re);
    BigInt temp2(c2.im);
    Complex<BigInt> temp(temp1, temp2);
    return temp.add1(c1);
}

inline Complex<BigInt> operator-(Complex<BigInt> c1, Complex<BigInt> c2)
{
    return c1.add1(c2);
}

inline Complex<int> operator-(Complex<int> c1, Complex<int> c2)
{
    return c1.add1(c2);
}
//---------------------------------------------------------------------------------------
//operator +

inline Complex<double> operator+(Complex<int> c1, Complex<double> c2)
{
    Complex<double> temp((double)c1.re, (double)c1.im);
    return temp.add(c2);
}

inline Complex<double> operator+(Complex<double> c1, Complex<int> c2)
{
    Complex<double> temp((double)c2.re, (double)c2.im);
    return temp.add(c1);
}

inline Complex<double> operator+(Complex<Rational> c1, Complex<double> c2)
{
    Complex<double> temp(c1.re.getDouble(), c1.im.getDouble());
    return temp.add(c2);
}

inline Complex<double> operator+(Complex<double> c1, Complex<Rational> c2)
{
    Complex<double> temp(c2.re.getDouble(), c2.im.getDouble());
    return temp.add(c1);
}

inline Complex<double> operator+(Complex<BigInt> c1, Complex<double> c2)
{
    Complex<double> temp((double)c1.re.getLongLong(), (double)c1.im.getLongLong());
    return temp.add(c2);
}

inline Complex<double> operator+(Complex<double> c1, Complex<BigInt> c2)
{
    Complex<double> temp((double)c2.re.getLongLong(), (double)c2.im.getLongLong());
    return temp.add(c1);
}

inline Complex<double> operator+(Complex<double> c1, Complex<double> c2)
{
    return c1.add(c2);
}

inline Complex<Rational> operator+(Complex<BigInt> c1, Complex<Rational> c2)
{
    Rational temp1(c1.re.getInt(), 1);
    Rational temp2(c1.im.getInt(), 1);
    Complex<Rational> temp(temp1, temp2);
    return temp.add(c2);
}

inline Complex<Rational> operator+(Complex<Rational> c1, Complex<BigInt> c2)
{
    Rational temp1(c2.re.getInt(), 1);
    Rational temp2(c2.im.getInt(), 1);
    Complex<Rational> temp(temp1, temp2);
    return temp.add(c1);
}

inline Complex<Rational> operator+(Complex<int> c1, Complex<Rational> c2)
{
    Rational temp1(c1.re);
    Rational temp2(c1.im);
    Complex<Rational> temp(temp1, temp2);
    return temp.add(c2);
}

inline Complex<Rational> operator+(Complex<Rational> c1, Complex<int> c2)
{
    Rational temp1(c2.re);
    Rational temp2(c2.im);
    Complex<Rational> temp(temp1, temp2);
    return temp.add(c1);
}

inline Complex<Rational> operator+(Complex<Rational> c1, Complex<Rational> c2)
{
    return c1.add(c2);
}

inline Complex<BigInt> operator+(Complex<int> c1, Complex<BigInt> c2)
{
    BigInt temp1(c1.re);
    BigInt temp2(c1.im);
    Complex<BigInt> temp(temp1, temp2);
    return temp.add(c2);
}

inline Complex<BigInt> operator+(Complex<BigInt> c1, Complex<int> c2)
{
    BigInt temp1(c2.re);
    BigInt temp2(c2.im);
    Complex<BigInt> temp(temp1, temp2);
    return temp.add(c1);
}

inline Complex<BigInt> operator+(Complex<BigInt> c1, Complex<BigInt> c2)
{
    return c1.add(c2);
}

inline Complex<int> operator+(Complex<int> c1, Complex<int> c2)
{
    return c1.add(c2);
}

//---------------------------------------------------------------------------------------
//operator *

inline Complex<double> operator*(Complex<int> c1, Complex<double> c2)
{
    Complex<double> temp((double)c1.re, (double)c1.im);
    return temp.add2(c2);
}

inline Complex<double> operator*(Complex<double> c1, Complex<int> c2)
{
    Complex<double> temp((double)c2.re, (double)c2.im);
    return temp.add2(c1);
}

inline Complex<double> operator*(Complex<Rational> c1, Complex<double> c2)
{
    Complex<double> temp(c1.re.getDouble(), c1.im.getDouble());
    return temp.add2(c2);
}

inline Complex<double> operator*(Complex<double> c1, Complex<Rational> c2)
{
    Complex<double> temp(c2.re.getDouble(), c2.im.getDouble());
    return temp.add2(c1);
}

inline Complex<double> operator*(Complex<BigInt> c1, Complex<double> c2)
{
    Complex<double> temp((double)c1.re.getLongLong(), (double)c1.im.getLongLong());
    return temp.add2(c2);
}

inline Complex<double> operator*(Complex<double> c1, Complex<BigInt> c2)
{
    Complex<double> temp((double)c2.re.getLongLong(), (double)c2.im.getLongLong());
    return temp.add2(c1);
}

inline Complex<double> operator*(Complex<double> c1, Complex<double> c2)
{
    return c1.add2(c2);
}

inline Complex<Rational> operator*(Complex<BigInt> c1, Complex<Rational> c2)
{
    Rational temp1(c1.re.getInt(), 1);
    Rational temp2(c1.im.getInt(), 1);
    Complex<Rational> temp(temp1, temp2);
    return temp.add2(c2);
}

inline Complex<Rational> operator*(Complex<Rational> c1, Complex<BigInt> c2)
{
    Rational temp1(c2.re.getInt(), 1);
    Rational temp2(c2.im.getInt(), 1);
    Complex<Rational> temp(temp1, temp2);
    return temp.add2(c1);
}

inline Complex<Rational> operator*(Complex<int> c1, Complex<Rational> c2)
{
    Rational temp1(c1.re);
    Rational temp2(c1.im);
    Complex<Rational> temp(temp1, temp2);
    return temp.add2(c2);
}

inline Complex<Rational> operator*(Complex<Rational> c1, Complex<int> c2)
{
    Rational temp1(c2.re);
    Rational temp2(c2.im);
    Complex<Rational> temp(temp1, temp2);
    return temp.add2(c1);
}

inline Complex<Rational> operator*(Complex<Rational> c1, Complex<Rational> c2)
{
    return c1.add2(c2);
}

inline Complex<BigInt> operator*(Complex<int> c1, Complex<BigInt> c2)
{
    BigInt temp1(c1.re);
    BigInt temp2(c1.im);
    Complex<BigInt> temp(temp1, temp2);
    return temp.add2(c2);
}

inline Complex<BigInt> operator*(Complex<BigInt> c1, Complex<int> c2)
{
    BigInt temp1(c2.re);
    BigInt temp2(c2.im);
    Complex<BigInt> temp(temp1, temp2);
    return temp.add2(c1);
}

inline Complex<BigInt> operator*(Complex<BigInt> c1, Complex<BigInt> c2)
{
    return c1.add2(c2);
}

inline Complex<int> operator*(Complex<int> c1, Complex<int> c2)
{
    return c1.add2(c2);
}
//---------------------------------------------------------------------------------------
template <class type1>
Complex <type1> ::Complex()
{
    re = 0;
    im = 0;
}

template <class type1>
Complex <type1> ::Complex(type1 r, type1 i)
{
    re = r;
    im = i;
}

template <class type1>
Complex <type1> ::Complex(type1 i)
{
    re = i;
    im = 0;
}

template <class type1>
Complex <type1> :: ~Complex()
{

}

template <class type1>
Complex <type1> ::Complex(Complex &c)
{
    re = c.re;
    im = c.im;
}

template <class type1>
Complex <type1> Complex <type1> ::add(Complex &c)
{
    Complex temp;
    temp.re = re + c.re;
    temp.im = im + c.im;
    return temp;
}

template <class type1>
Complex <type1> Complex <type1> ::add1(Complex &c)
{
    Complex temp;
    temp.re = re - c.re;
    temp.im = im - c.im;
    return temp;
}

template <class type1>
Complex <type1> Complex <type1> ::add2(Complex &c)
{
    Complex temp;
    temp.re = re * c.re - im * c.im;
    temp.im = re * c.im + im * c.re;
    return temp;
}
