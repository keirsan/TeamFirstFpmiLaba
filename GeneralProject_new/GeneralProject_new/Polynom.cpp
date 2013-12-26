#include <iostream>
#include "Polynom.h"
#include "BigInt.h"

inline int max(int x, int y)
{
    if (x > y) return x;
    else return y;
}

Polynom::Polynom(const Polynom& ist)
{
    degree = ist.degree;
    if (ist.coefI)
    {
        coefB = 0;
        coefR = 0;
        coefD = 0;
        coefI = new Complex<int>[1000];
        for (int i = 0; i <= degree; i++)
            coefI[i] = ist.coefI[i];
        //return;
    }
    if (ist.coefB)
    {
        coefI = 0;
        coefR = 0;
        coefD = 0;
        coefB = new Complex<BigInt>[1000];
        for (int i = 0; i <= degree; i++)
            coefB[i] = ist.coefB[i];
        //return;
    }
    if (ist.coefR)
    {
        coefB = 0;
        coefI = 0;
        coefD = 0;
        coefR = new Complex<Rational>[1000];
        for (int i = 0; i <= degree; i++)
            coefR[i] = ist.coefR[i];
        //return;
    }
    if (ist.coefD)
    {
        coefB = 0;
        coefR = 0;
        coefI = 0;
        coefD = new Complex<double>[1000];
        for (int i = 0; i <= degree; i++)
            coefD[i] = ist.coefD[i];
        //return;
    }
}

Polynom::Polynom(Complex<int> value, int deg)
{
    coefI = new Complex<int>[1000];
    for (int i = 0; i < 1000; i++)
        coefI[i] = 0;

    coefI[deg] = value;
    degree = deg;
    coefB = 0;
    coefR = 0;
    coefD = 0;
}

Polynom::Polynom(Complex<BigInt> value, int deg)
{
    coefB = new Complex<BigInt>[1000];
    BigInt zero(0);
    Complex<BigInt> Czero(zero, zero);
    for (int i = 0; i < 1000; i++)
        coefB[i] = Czero;

    coefB[deg] = value;
    degree = deg;
    coefI = 0;
    coefR = 0;
    coefD = 0;
}

Polynom::Polynom(Complex<Rational> value, int deg)
{
    coefR = new Complex<Rational>[1000];
    Rational zero(0);
    for (int i = 0; i < 1000; i++)
        coefR[i] = zero;

    coefR[deg] = value;
    degree = deg;
    coefI = 0;
    coefB = 0;
    coefD = 0;
}

Polynom::Polynom(Complex<double> value, int deg)
{
    coefD = new Complex<double>[1000];
    for (int i = 0; i < 1000; i++)
        coefD[i] = 0;

    coefD[deg] = value;
    degree = deg;
    coefI = 0;
    coefB = 0;
    coefR = 0;
}

Polynom Polynom::operator+(Polynom summand)
{
    if (coefI && summand.coefI)
    {
        Complex<int> temp(0);
        Polynom sum(temp, 0);
        sum.degree = max(degree, summand.degree);
        for (int i = 0; i <= sum.degree; i++)
            sum.coefI[i] = coefI[i] + summand.coefI[i];
        return sum;
    }
    if (coefI && summand.coefB)
    {
        Complex<BigInt> temp(0);
        Polynom sum(temp, 0);
        sum.degree = max(degree, summand.degree);
        for (int i = 0; i <= degree; i++)
            sum.coefB[i] = coefI[i] + summand.coefB[i];
        return sum;
    }
    if (coefI && summand.coefR)
    {
        Complex<Rational> temp(0);
        Polynom sum(temp, 0);
        sum.degree = max(degree, summand.degree);
        for (int i = 0; i <= sum.degree; i++)
            sum.coefR[i] = coefI[i] + summand.coefR[i];
        return sum;
    }
    if (coefI && summand.coefD)
    {
        Complex<double> temp(0);
        Polynom sum(temp, 0);
        sum.degree = max(degree, summand.degree);
        for (int i = 0; i <= sum.degree; i++)
            sum.coefD[i] = coefI[i] + summand.coefD[i];
        return sum;
    }
    if (coefB && summand.coefI)
    {
        Complex<BigInt> temp(0);
        Polynom sum(temp, 0);
        sum.degree = max(degree, summand.degree);
        for (int i = 0; i <= sum.degree; i++)
            sum.coefB[i] = coefB[i] + summand.coefI[i];
        return sum;
    }
    if (coefB && summand.coefB)
    {
        Complex<BigInt> temp(0);
        Polynom sum(temp, 0);
        sum.degree = max(degree, summand.degree);
        for (int i = 0; i <= sum.degree; i++)
            sum.coefB[i] = coefB[i] + summand.coefB[i];
        return sum;
    }
    if (coefB && summand.coefR)
    {
        Complex<Rational> temp(0);
        Polynom sum(temp, 0);
        sum.degree = max(degree, summand.degree);
        for (int i = 0; i <= sum.degree; i++)
            sum.coefR[i] = coefB[i] + summand.coefR[i];
        return sum;
    }
    if (coefB && summand.coefD)
    {
        Complex<double> temp(0);
        Polynom sum(temp, 0);
        sum.degree = max(degree, summand.degree);
        for (int i = 0; i <= sum.degree; i++)
            sum.coefD[i] = coefB[i] + summand.coefD[i];
        return sum;
    }
    if (coefR && summand.coefI)
    {
        Complex<Rational> temp(0);
        Polynom sum(temp, 0);
        sum.degree = max(degree, summand.degree);
        for (int i = 0; i <= sum.degree; i++)
            sum.coefR[i] = coefR[i] + summand.coefI[i];
        return sum;
    }
    if (coefR && summand.coefB)
    {
        Complex<Rational> temp(0);
        Polynom sum(temp, 0);
        sum.degree = max(degree, summand.degree);
        for (int i = 0; i <= sum.degree; i++)
            sum.coefR[i] = coefR[i] + summand.coefB[i];
        return sum;
    }
    if (coefR && summand.coefR)
    {
        Complex<Rational> temp(0);
        Polynom sum(temp, 0);
        sum.degree = max(degree, summand.degree);
        for (int i = 0; i <= sum.degree; i++)
            sum.coefR[i] = coefR[i] + summand.coefR[i];
        return sum;
    }
    if (coefR && summand.coefD)
    {
        Complex<double> temp(0);
        Polynom sum(temp, 0);
        sum.degree = max(degree, summand.degree);
        for (int i = 0; i <= sum.degree; i++)
            sum.coefD[i] = coefR[i] + summand.coefD[i];
        return sum;
    }
    if (coefD && summand.coefI)
    {
        Complex<double> temp(0);
        Polynom sum(temp, 0);
        sum.degree = max(degree, summand.degree);
        for (int i = 0; i <= sum.degree; i++)
            sum.coefD[i] = coefD[i] + summand.coefI[i];
        return sum;
    }
    if (coefD && summand.coefB)
    {
        Complex<double> temp(0);
        Polynom sum(temp, 0);
        sum.degree = max(degree, summand.degree);
        for (int i = 0; i <= sum.degree; i++)
            sum.coefD[i] = coefD[i] + summand.coefB[i];
        return sum;
    }
    if (coefD && summand.coefR)
    {
        Complex<double> temp(0);
        Polynom sum(temp, 0);
        sum.degree = max(degree, summand.degree);
        for (int i = 0; i <= sum.degree; i++)
            sum.coefD[i] = coefD[i] + summand.coefR[i];
        return sum;
    }
    if (coefD && summand.coefD)
    {
        Complex<double> temp(0);
        Polynom sum(temp, 0);
        sum.degree = max(degree, summand.degree);
        for (int i = 0; i <= sum.degree; i++)
            sum.coefD[i] = coefD[i] + summand.coefD[i];
        return sum;
    }
}

Polynom Polynom::operator-(Polynom summand)
{
    if (coefI && summand.coefI)
    {
        Complex<int> temp(0);
        Polynom sum(temp, 0);
        sum.degree = max(degree, summand.degree);
        for (int i = 0; i <= sum.degree; i++)
            sum.coefI[i] = coefI[i] - summand.coefI[i];
        return sum;
    }
    if (coefI && summand.coefB)
    {
        Complex<BigInt> temp(0);
        Polynom sum(temp, 0);
        sum.degree = max(degree, summand.degree);
        for (int i = 0; i <= sum.degree; i++)
            sum.coefB[i] = coefI[i] - summand.coefB[i];
        return sum;
    }
    if (coefI && summand.coefR)
    {
        Complex<Rational> temp(0);
        Polynom sum(temp, 0);
        sum.degree = max(degree, summand.degree);
        for (int i = 0; i <= sum.degree; i++)
            sum.coefR[i] = coefI[i] - summand.coefR[i];
        return sum;
    }
    if (coefI && summand.coefD)
    {
        Complex<double> temp(0);
        Polynom sum(temp, 0);
        sum.degree = max(degree, summand.degree);
        for (int i = 0; i <= sum.degree; i++)
            sum.coefD[i] = coefI[i] - summand.coefD[i];
        return sum;
    }
    if (coefB && summand.coefI)
    {
        Complex<BigInt> temp(0);
        Polynom sum(temp, 0);
        sum.degree = max(degree, summand.degree);
        for (int i = 0; i <= sum.degree; i++)
            sum.coefB[i] = coefB[i] - summand.coefI[i];
        return sum;
    }
    if (coefB && summand.coefB)
    {
        Complex<BigInt> temp(0);
        Polynom sum(temp, 0);
        sum.degree = max(degree, summand.degree);
        for (int i = 0; i <= sum.degree; i++)
            sum.coefB[i] = coefB[i] - summand.coefB[i];
        return sum;
    }
    if (coefB && summand.coefR)
    {
        Complex<Rational> temp(0);
        Polynom sum(temp, 0);
        sum.degree = max(degree, summand.degree);
        for (int i = 0; i <= sum.degree; i++)
            sum.coefR[i] = coefB[i] - summand.coefR[i];
        return sum;
    }
    if (coefB && summand.coefD)
    {
        Complex<double> temp(0);
        Polynom sum(temp, 0);
        sum.degree = max(degree, summand.degree);
        for (int i = 0; i <= sum.degree; i++)
            sum.coefD[i] = coefB[i] - summand.coefD[i];
        return sum;
    }
    if (coefR && summand.coefI)
    {
        Complex<Rational> temp(0);
        Polynom sum(temp, 0);
        sum.degree = max(degree, summand.degree);
        for (int i = 0; i <= sum.degree; i++)
            sum.coefR[i] = coefR[i] - summand.coefI[i];
        return sum;
    }
    if (coefR && summand.coefB)
    {
        Complex<Rational> temp(0);
        Polynom sum(temp, 0);
        sum.degree = max(degree, summand.degree);
        for (int i = 0; i <= sum.degree; i++)
            sum.coefR[i] = coefR[i] - summand.coefB[i];
        return sum;
    }
    if (coefR && summand.coefR)
    {
        Complex<Rational> temp(0);
        Polynom sum(temp, 0);
        sum.degree = max(degree, summand.degree);
        for (int i = 0; i <= sum.degree; i++)
            sum.coefR[i] = coefR[i] - summand.coefR[i];
        return sum;
    }
    if (coefR && summand.coefD)
    {
        Complex<double> temp(0);
        Polynom sum(temp, 0);
        sum.degree = max(degree, summand.degree);
        for (int i = 0; i <= sum.degree; i++)
            sum.coefD[i] = coefR[i] - summand.coefD[i];
        return sum;
    }
    if (coefD && summand.coefI)
    {
        Complex<double> temp(0);
        Polynom sum(temp, 0);
        sum.degree = max(degree, summand.degree);
        for (int i = 0; i <= sum.degree; i++)
            sum.coefD[i] = coefD[i] - summand.coefI[i];
        return sum;
    }
    if (coefD && summand.coefB)
    {
        Complex<double> temp(0);
        Polynom sum(temp, 0);
        sum.degree = max(degree, summand.degree);
        for (int i = 0; i <= sum.degree; i++)
            sum.coefD[i] = coefD[i] - summand.coefB[i];
        return sum;
    }
    if (coefD && summand.coefR)
    {
        Complex<double> temp(0);
        Polynom sum(temp, 0);
        sum.degree = max(degree, summand.degree);
        for (int i = 0; i <= sum.degree; i++)
            sum.coefD[i] = coefD[i] - summand.coefR[i];
        return sum;
    }
    if (coefD && summand.coefD)
    {
        Complex<double> temp(0);
        Polynom sum(temp, 0);
        sum.degree = max(degree, summand.degree);
        for (int i = 0; i <= sum.degree; i++)
            sum.coefD[i] = coefD[i] - summand.coefD[i];
        return sum;
    }
}

Polynom Polynom::operator*(Polynom summand)
{
    if (coefI && summand.coefI)
    {
        Complex<int> temp(0);
        Polynom sum(temp, 0);
        sum.degree = degree + summand.degree;
        for (int i = 0; i <= degree; i++)
            for (int j = 0; j <= summand.degree; j++)
                sum.coefI[i + j] = sum.coefI[i+j] + coefI[i] * summand.coefI[j];
        return sum;
    }
    if (coefI && summand.coefB)
    {
        Complex<BigInt> temp(0);
        Polynom sum(temp, 0);
        sum.degree = degree + summand.degree;
        for (int i = 0; i <= degree; i++)
            for (int j = 0; j <= summand.degree; j++)
                sum.coefB[i + j] = sum.coefB[i + j] + coefI[i] * summand.coefB[j];
        return sum;
    }
    if (coefI && summand.coefR)
    {
        Complex<Rational> temp(0);
        Polynom sum(temp, 0);
        sum.degree = degree + summand.degree;
        for (int i = 0; i <= degree; i++)
            for (int j = 0; j <= summand.degree; j++)
                sum.coefR[i + j] = sum.coefR[i + j] + coefI[i] * summand.coefR[j];
        return sum;
    }
    if (coefI && summand.coefD)
    {
        Complex<double> temp(0);
        Polynom sum(temp, 0);
        sum.degree = degree + summand.degree;
        for (int i = 0; i <= degree; i++)
            for (int j = 0; j <= summand.degree; j++)
                sum.coefD[i + j] = sum.coefD[i + j] + coefI[i] * summand.coefD[j];
        return sum;
    }
    if (coefB && summand.coefI)
    {
        Complex<BigInt> temp(0);
        Polynom sum(temp, 0);
        sum.degree = degree + summand.degree;
        for (int i = 0; i <= degree; i++)
            for (int j = 0; j <= summand.degree; j++)
                sum.coefB[i + j] = sum.coefB[i + j] + coefB[i] * summand.coefI[j];
        return sum;
    }
    if (coefB && summand.coefB)
    {
        Complex<BigInt> temp(0);
        Polynom sum(temp, 0);
        sum.degree = degree + summand.degree;
        for (int i = 0; i <= degree; i++)
            for (int j = 0; j <= summand.degree; j++)
                sum.coefB[i + j] = sum.coefB[i + j] + coefB[i] * summand.coefB[j];
        return sum;
    }
    if (coefB && summand.coefR)
    {
        Complex<Rational> temp(0);
        Polynom sum(temp, 0);
        sum.degree = degree + summand.degree;
        for (int i = 0; i <= degree; i++)
            for (int j = 0; j <= summand.degree; j++)
                sum.coefR[i + j] = sum.coefR[i + j] + coefB[i] * summand.coefR[j];
        return sum;
    }
    if (coefB && summand.coefD)
    {
        Complex<double> temp(0);
        Polynom sum(temp, 0);
        sum.degree = degree + summand.degree;
        for (int i = 0; i <= degree; i++)
            for (int j = 0; j <= summand.degree; j++)
                sum.coefD[i + j] = sum.coefD[i + j] + coefB[i] * summand.coefD[j];
        return sum;
    }
    if (coefR && summand.coefI)
    {
        Complex<Rational> temp(0);
        Polynom sum(temp, 0);
        sum.degree = degree + summand.degree;
        for (int i = 0; i <= degree; i++)
            for (int j = 0; j <= summand.degree; j++)
                sum.coefR[i + j] = sum.coefR[i + j] + coefR[i] * summand.coefI[j];
        return sum;
    }
    if (coefR && summand.coefB)
    {
        Complex<Rational> temp(0);
        Polynom sum(temp, 0);
        sum.degree = degree + summand.degree;
        for (int i = 0; i <= degree; i++)
            for (int j = 0; j <= summand.degree; j++)
                sum.coefR[i + j] = sum.coefR[i + j] + coefR[i] * summand.coefB[j];
        return sum;
    }
    if (coefR && summand.coefR)
    {
        Complex<Rational> temp(0);
        Polynom sum(temp, 0);
        sum.degree = degree + summand.degree;
        for (int i = 0; i <= degree; i++)
            for (int j = 0; j <= summand.degree; j++)
                sum.coefR[i + j] = sum.coefR[i + j] + coefR[i] * summand.coefR[j];
        return sum;
    }
    if (coefR && summand.coefD)
    {
        Complex<double> temp(0);
        Polynom sum(temp, 0);
        sum.degree = degree + summand.degree;
        for (int i = 0; i <= degree; i++)
            for (int j = 0; j <= summand.degree; j++)
                sum.coefD[i + j] = sum.coefD[i + j] + coefR[i] * summand.coefD[j];
        return sum;
    }
    if (coefD && summand.coefI)
    {
        Complex<double> temp(0);
        Polynom sum(temp, 0);
        sum.degree = degree + summand.degree;
        for (int i = 0; i <= degree; i++)
            for (int j = 0; j <= summand.degree; j++)
                sum.coefD[i + j] = sum.coefD[i + j] + coefD[i] * summand.coefI[j];
        return sum;
    }
    if (coefD && summand.coefB)
    {
        Complex<double> temp(0);
        Polynom sum(temp, 0);
        sum.degree = degree + summand.degree;
        for (int i = 0; i <= degree; i++)
            for (int j = 0; j <= summand.degree; j++)
                sum.coefD[i + j] = sum.coefD[i + j] + coefD[i] * summand.coefB[j];
        return sum;
    }
    if (coefD && summand.coefR)
    {
        Complex<double> temp(0);
        Polynom sum(temp, 0);
        sum.degree = degree + summand.degree;
        for (int i = 0; i <= degree; i++)
            for (int j = 0; j <= summand.degree; j++)
                sum.coefD[i + j] = sum.coefD[i + j] + coefD[i] * summand.coefR[j];
        return sum;
    }
    if (coefD && summand.coefD)
    {
        Complex<double> temp(0);
        Polynom sum(temp, 0);
        sum.degree = degree + summand.degree;
        for (int i = 0; i <= degree; i++)
            for (int j = 0; j <= summand.degree; j++)
                sum.coefD[i + j] = sum.coefD[i + j] + coefD[i] * summand.coefD[j];
        return sum;
    }
}

Polynom::Polynom()
{
    coefI = 0;
    coefB = 0;
    coefR = 0;
    coefD = 0;
    degree = 0;
}

std::ostream& operator<<(std::ostream& out, const Polynom& pol)
{
    if (pol.coefI)
    {
        for (int i = pol.degree; i >= 0; i--)
            out << "(" << pol.coefI[i]<<")x^"<<i<<" ";
    }
    if (pol.coefB)
    {
        for (int i = pol.degree; i >= 0; i--)
            out << "(" << pol.coefB[i]<<")x^"<<i<<" ";
    }
    if (pol.coefR)
    {
        for (int i = pol.degree; i >= 0; i--)
            out << "(" << pol.coefR[i]<<")x^"<<i<<" ";
    }
    if (pol.coefD)
    {
        for (int i = pol.degree; i >= 0; i--)
            out << "(" << pol.coefD[i]<<")x^"<<i<<" ";
    }
    return out;
}

Polynom Polynom::substitution(Polynom value)
{
    if (coefI && value.coefI)
    {
        Complex<int> temp0(0,0);
        Complex<int> temp1(1,0);
        Polynom temp(temp1,0);
        Polynom answer(temp0,0);
        for (int i = 0; i <= degree; i++)
        {
            Polynom curr(coefI[i], 0);
            answer = answer + temp * curr;
            temp = temp * value;
        }
        *this = answer;
        return answer;
    }
    if (coefI && value.coefB)
    {
        Complex<BigInt> temp0(0,0);
        Complex<BigInt> temp1(1,0);
        Polynom temp(temp1,0);
        Polynom answer(temp0,0);
        for (int i = 0; i <= degree; i++)
        {
            Polynom curr(coefI[i], 0);
            answer = answer + temp * curr;
            temp = temp * value;
        }
        *this = answer;
        return answer;
    }
    if (coefI && value.coefR)
    {
        Complex<Rational> temp0(0,0);
        Complex<Rational> temp1(1,0);
        Polynom temp(temp1,0);
        Polynom answer(temp0,0);
        for (int i = 0; i <= degree; i++)
        {
            Polynom curr(coefI[i], 0);
            answer = answer + temp * curr;
            temp = temp * value;
        }
        *this = answer;
        return answer;
    }
    if (coefI && value.coefD)
    {
        Complex<double> temp0(0,0);
        Complex<double> temp1(1,0);
        Polynom temp(temp1,0);
        Polynom answer(temp0,0);
        for (int i = 0; i <= degree; i++)
        {
            Polynom curr(coefI[i], 0);
            answer = answer + temp * curr;
            temp = temp * value;
        }
        *this = answer;
        return answer;
    }
    if (coefB && value.coefI)
    {
        Complex<BigInt> temp0(0,0);
        Complex<BigInt> temp1(1,0);
        Polynom temp(temp1,0);
        Polynom answer(temp0,0);
        for (int i = 0; i <= degree; i++)
        {
            Polynom curr(coefI[i], 0);
            answer = answer + temp * curr;
            temp = temp * value;
        }
        *this = answer;
        return answer;
    }
    if (coefB && value.coefB)
    {
        Complex<BigInt> temp0(0,0);
        Complex<BigInt> temp1(1,0);
        Polynom temp(temp1,0);
        Polynom answer(temp0,0);
        for (int i = 0; i <= degree; i++)
        {
            Polynom curr(coefI[i], 0);
            answer = answer + temp * curr;
            temp = temp * value;
        }
        *this = answer;
        return answer;
    }
    if (coefB && value.coefR)
    {
        Complex<Rational> temp0(0,0);
        Complex<Rational> temp1(1,0);
        Polynom temp(temp1,0);
        Polynom answer(temp0,0);
        for (int i = 0; i <= degree; i++)
        {
            Polynom curr(coefI[i], 0);
            answer = answer + temp * curr;
            temp = temp * value;
        }
        *this = answer;
        return answer;
    }
    if (coefB && value.coefD)
    {
        Complex<double> temp0(0,0);
        Complex<double> temp1(1,0);
        Polynom temp(temp1,0);
        Polynom answer(temp0,0);
        for (int i = 0; i <= degree; i++)
        {
            Polynom curr(coefI[i], 0);
            answer = answer + temp * curr;
            temp = temp * value;
        }
        *this = answer;
        return answer;
    }
    if (coefR && value.coefI)
    {
        Complex<Rational> temp0(0,0);
        Complex<Rational> temp1(1,0);
        Polynom temp(temp1,0);
        Polynom answer(temp0,0);
        for (int i = 0; i <= degree; i++)
        {
            Polynom curr(coefI[i], 0);
            answer = answer + temp * curr;
            temp = temp * value;
        }
        *this = answer;
        return answer;
    }
    if (coefR && value.coefB)
    {
        Complex<Rational> temp0(0,0);
        Complex<Rational> temp1(1,0);
        Polynom temp(temp1,0);
        Polynom answer(temp0,0);
        for (int i = 0; i <= degree; i++)
        {
            Polynom curr(coefI[i], 0);
            answer = answer + temp * curr;
            temp = temp * value;
        }
        *this = answer;
        return answer;
    }
    if (coefR && value.coefR)
    {
        Complex<Rational> temp0(0,0);
        Complex<Rational> temp1(1,0);
        Polynom temp(temp1,0);
        Polynom answer(temp0,0);
        for (int i = 0; i <= degree; i++)
        {
            Polynom curr(coefI[i], 0);
            answer = answer + temp * curr;
            temp = temp * value;
        }
        *this = answer;
        return answer;
    }
    if (coefR && value.coefD)
    {
        Complex<double> temp0(0,0);
        Complex<double> temp1(1,0);
        Polynom temp(temp1,0);
        Polynom answer(temp0,0);
        for (int i = 0; i <= degree; i++)
        {
            Polynom curr(coefI[i], 0);
            answer = answer + temp * curr;
            temp = temp * value;
        }
        *this = answer;
        return answer;
    }
    if (coefD && value.coefI)
    {
        Complex<double> temp0(0,0);
        Complex<double> temp1(1,0);
        Polynom temp(temp1,0);
        Polynom answer(temp0,0);
        for (int i = 0; i <= degree; i++)
        {
            Polynom curr(coefI[i], 0);
            answer = answer + temp * curr;
            temp = temp * value;
        }
        *this = answer;
        return answer;
    }
    if (coefD && value.coefB)
    {
        Complex<double> temp0(0,0);
        Complex<double> temp1(1,0);
        Polynom temp(temp1,0);
        Polynom answer(temp0,0);
        for (int i = 0; i <= degree; i++)
        {
            Polynom curr(coefI[i], 0);
            answer = answer + temp * curr;
            temp = temp * value;
        }
        *this = answer;
        return answer;
    }
    if (coefD && value.coefR)
    {
        Complex<double> temp0(0,0);
        Complex<double> temp1(1,0);
        Polynom temp(temp1,0);
        Polynom answer(temp0,0);
        for (int i = 0; i <= degree; i++)
        {
            Polynom curr(coefI[i], 0);
            answer = answer + temp * curr;
            temp = temp * value;
        }
        *this = answer;
        return answer;
    }
    if (coefD && value.coefD)
    {
        Complex<double> temp0(0,0);
        Complex<double> temp1(1,0);
        Polynom temp(temp1,0);
        Polynom answer(temp0,0);
        for (int i = 0; i <= degree; i++)
        {
            Polynom curr(coefI[i], 0);
            answer = answer + temp * curr;
            temp = temp * value;
        }
        *this = answer;
        return answer;
    }
}

/*Polynom Polynom::operator^(Polynom degree)
{
    Polynom temp = *this;
    Polynom res(1);
    int deg = degree.coefI[0].getRe();
    while (deg) 
    {
        if (deg & 1) 
            res = res * temp;
        temp = temp * temp;
        deg >>= 1;
    }
    return res;
}*/