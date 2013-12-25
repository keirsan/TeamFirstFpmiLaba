#include <iostream>
#include "Polynom.h"
#include "BigInt.h"

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
        for (int i = 0; i <= degree; i++)
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
        for (int i = 0; i <= degree; i++)
            sum.coefR[i] = coefI[i] + summand.coefR[i];
        return sum;
    }
    if (coefI && summand.coefD)
    {
        Complex<double> temp(0);
        Polynom sum(temp, 0);
        sum.degree = max(degree, summand.degree);
        for (int i = 0; i <= degree; i++)
            sum.coefD[i] = coefI[i] + summand.coefD[i];
        return sum;
    }
    if (coefB && summand.coefI)
    {
        Complex<BigInt> temp(0);
        Polynom sum(temp, 0);
        sum.degree = max(degree, summand.degree);
        for (int i = 0; i <= degree; i++)
            sum.coefB[i] = coefB[i] + summand.coefI[i];
        return sum;
    }
    if (coefB && summand.coefB)
    {
        Complex<BigInt> temp(0);
        Polynom sum(temp, 0);
        sum.degree = max(degree, summand.degree);
        for (int i = 0; i <= degree; i++)
            sum.coefB[i] = coefB[i] + summand.coefB[i];
        return sum;
    }
    if (coefB && summand.coefR)
    {
        Complex<Rational> temp(0);
        Polynom sum(temp, 0);
        sum.degree = max(degree, summand.degree);
        for (int i = 0; i <= degree; i++)
            sum.coefR[i] = coefB[i] + summand.coefR[i];
        return sum;
    }
    if (coefB && summand.coefD)
    {
        Complex<double> temp(0);
        Polynom sum(temp, 0);
        sum.degree = max(degree, summand.degree);
        for (int i = 0; i <= degree; i++)
            sum.coefD[i] = coefB[i] + summand.coefD[i];
        return sum;
    }
    if (coefR && summand.coefI)
    {
        Complex<Rational> temp(0);
        Polynom sum(temp, 0);
        sum.degree = max(degree, summand.degree);
        for (int i = 0; i <= degree; i++)
            sum.coefR[i] = coefR[i] + summand.coefI[i];
        return sum;
    }
    if (coefR && summand.coefB)
    {
        Complex<Rational> temp(0);
        Polynom sum(temp, 0);
        sum.degree = max(degree, summand.degree);
        for (int i = 0; i <= degree; i++)
            sum.coefR[i] = coefR[i] + summand.coefB[i];
        return sum;
    }
    if (coefR && summand.coefR)
    {
        Complex<Rational> temp(0);
        Polynom sum(temp, 0);
        sum.degree = max(degree, summand.degree);
        for (int i = 0; i <= degree; i++)
            sum.coefR[i] = coefR[i] + summand.coefR[i];
        return sum;
    }
    if (coefR && summand.coefD)
    {
        Complex<double> temp(0);
        Polynom sum(temp, 0);
        sum.degree = max(degree, summand.degree);
        for (int i = 0; i <= degree; i++)
            sum.coefD[i] = coefR[i] + summand.coefD[i];
        return sum;
    }
    if (coefD && summand.coefI)
    {
        Complex<double> temp(0);
        Polynom sum(temp, 0);
        sum.degree = max(degree, summand.degree);
        for (int i = 0; i <= degree; i++)
            sum.coefD[i] = coefD[i] + summand.coefI[i];
        return sum;
    }
    if (coefD && summand.coefB)
    {
        Complex<double> temp(0);
        Polynom sum(temp, 0);
        sum.degree = max(degree, summand.degree);
        for (int i = 0; i <= degree; i++)
            sum.coefD[i] = coefD[i] + summand.coefB[i];
        return sum;
    }
    if (coefD && summand.coefR)
    {
        Complex<double> temp(0);
        Polynom sum(temp, 0);
        sum.degree = max(degree, summand.degree);
        for (int i = 0; i <= degree; i++)
            sum.coefD[i] = coefD[i] + summand.coefR[i];
        return sum;
    }
    if (coefD && summand.coefD)
    {
        Complex<double> temp(0);
        Polynom sum(temp, 0);
        sum.degree = max(degree, summand.degree);
        for (int i = 0; i <= degree; i++)
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
        for (int i = 0; i <= degree; i++)
            sum.coefI[i] = coefI[i] - summand.coefI[i];
        return sum;
    }
    if (coefI && summand.coefB)
    {
        Complex<BigInt> temp(0);
        Polynom sum(temp, 0);
        sum.degree = max(degree, summand.degree);
        for (int i = 0; i <= degree; i++)
            sum.coefB[i] = coefI[i] - summand.coefB[i];
        return sum;
    }
    if (coefI && summand.coefR)
    {
        Complex<Rational> temp(0);
        Polynom sum(temp, 0);
        sum.degree = max(degree, summand.degree);
        for (int i = 0; i <= degree; i++)
            sum.coefR[i] = coefI[i] - summand.coefR[i];
        return sum;
    }
    if (coefI && summand.coefD)
    {
        Complex<double> temp(0);
        Polynom sum(temp, 0);
        sum.degree = max(degree, summand.degree);
        for (int i = 0; i <= degree; i++)
            sum.coefD[i] = coefI[i] - summand.coefD[i];
        return sum;
    }
    if (coefB && summand.coefI)
    {
        Complex<BigInt> temp(0);
        Polynom sum(temp, 0);
        sum.degree = max(degree, summand.degree);
        for (int i = 0; i <= degree; i++)
            sum.coefB[i] = coefB[i] - summand.coefI[i];
        return sum;
    }
    if (coefB && summand.coefB)
    {
        Complex<BigInt> temp(0);
        Polynom sum(temp, 0);
        sum.degree = max(degree, summand.degree);
        for (int i = 0; i <= degree; i++)
            sum.coefB[i] = coefB[i] - summand.coefB[i];
        return sum;
    }
    if (coefB && summand.coefR)
    {
        Complex<Rational> temp(0);
        Polynom sum(temp, 0);
        sum.degree = max(degree, summand.degree);
        for (int i = 0; i <= degree; i++)
            sum.coefR[i] = coefB[i] - summand.coefR[i];
        return sum;
    }
    if (coefB && summand.coefD)
    {
        Complex<double> temp(0);
        Polynom sum(temp, 0);
        sum.degree = max(degree, summand.degree);
        for (int i = 0; i <= degree; i++)
            sum.coefD[i] = coefB[i] - summand.coefD[i];
        return sum;
    }
    if (coefR && summand.coefI)
    {
        Complex<Rational> temp(0);
        Polynom sum(temp, 0);
        sum.degree = max(degree, summand.degree);
        for (int i = 0; i <= degree; i++)
            sum.coefR[i] = coefR[i] - summand.coefI[i];
        return sum;
    }
    if (coefR && summand.coefB)
    {
        Complex<Rational> temp(0);
        Polynom sum(temp, 0);
        sum.degree = max(degree, summand.degree);
        for (int i = 0; i <= degree; i++)
            sum.coefR[i] = coefR[i] - summand.coefB[i];
        return sum;
    }
    if (coefR && summand.coefR)
    {
        Complex<Rational> temp(0);
        Polynom sum(temp, 0);
        sum.degree = max(degree, summand.degree);
        for (int i = 0; i <= degree; i++)
            sum.coefR[i] = coefR[i] - summand.coefR[i];
        return sum;
    }
    if (coefR && summand.coefD)
    {
        Complex<double> temp(0);
        Polynom sum(temp, 0);
        sum.degree = max(degree, summand.degree);
        for (int i = 0; i <= degree; i++)
            sum.coefD[i] = coefR[i] - summand.coefD[i];
        return sum;
    }
    if (coefD && summand.coefI)
    {
        Complex<double> temp(0);
        Polynom sum(temp, 0);
        sum.degree = max(degree, summand.degree);
        for (int i = 0; i <= degree; i++)
            sum.coefD[i] = coefD[i] - summand.coefI[i];
        return sum;
    }
    if (coefD && summand.coefB)
    {
        Complex<double> temp(0);
        Polynom sum(temp, 0);
        sum.degree = max(degree, summand.degree);
        for (int i = 0; i <= degree; i++)
            sum.coefD[i] = coefD[i] - summand.coefB[i];
        return sum;
    }
    if (coefD && summand.coefR)
    {
        Complex<double> temp(0);
        Polynom sum(temp, 0);
        sum.degree = max(degree, summand.degree);
        for (int i = 0; i <= degree; i++)
            sum.coefD[i] = coefD[i] - summand.coefR[i];
        return sum;
    }
    if (coefD && summand.coefD)
    {
        Complex<double> temp(0);
        Polynom sum(temp, 0);
        sum.degree = max(degree, summand.degree);
        for (int i = 0; i <= degree; i++)
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

/*
Polynom::Polynom()
{
for(int i = 0; i < 100; i++)
coeff[i] = 0;
degree = 0;
}
*/
Polynom::Polynom(double value)
{
    degree = 0;
    coeff[0] = value;
    for (int i = 1; i < 1000; i++)
        coeff[i] = 0;
}
/*
Polynom::Polynom(const Polynom& pol)
{
degree = pol.degree;
for (int i = 0; i < 1000; i++)
coeff[i] = pol.coeff[i];
}
*/
Polynom::Polynom(int deg, int val)
{
    degree = deg;
    for (int i = 0; i < 1000; i++)
        coeff[i] = 0;
    coeff[deg] = val;
}
/*
void Polynom::setPolynom(int deg)
{
degree = deg;
for(int i = 0; i <= degree; i++)
std::cin >> coeff[i];
return;
}

void Polynom::getPolynom()
{
bool isPrinted = false;
for(int i = degree; i >= 0; i--)
if (coeff[i]!=0)
{
if (isPrinted && coeff[i]>=0)
std::cout << "+";
if (coeff[i] != -1 && coeff[i] != 1)
std::cout << coeff[i];
else
{
if (coeff[i] == -1)
i==0 ? std::cout << -1 :std::cout << "-";
if (coeff[i] == 1 && i == 0)
std::cout << 1;
}
if (i != 0)
std::cout << "x^"<<i;
isPrinted = true;
}
if (!isPrinted)
std::cout << 0;
return;
}

double Polynom::polValue(double value)
{
double temp = 1;
double result = 0;
for(int i = 0; i <= degree;i++)
{
result += coeff[i] * temp;
temp *= value;
}
return result;
}

void Polynom::mult(const Polynom & pol1, const Polynom & pol2)
{
for(int i=0;i <= pol1.degree;i++)
for(int j=0; j <= pol2.degree;j++)
coeff[i+j] += (pol1.coeff[i]*pol2.coeff[j]);
degree = pol1.degree + pol2.degree;

}

void Polynom::operator=(const Polynom& pol)
{
degree = pol.degree;
for (int i = 0; i < 1000; i++)
coeff[i] = pol.coeff[i];
}
Polynom Polynom::operator+(const Polynom& pol)
{
int max;
max = (pol.degree > degree ? pol.degree : degree);
Polynom sum;
for(int i = 0; i <= max; i++)
sum.coeff[i] = coeff[i] + pol.coeff[i];

sum.degree = max;
while (sum.coeff[sum.degree] == 0)
sum.degree--;

return sum;
}

void Polynom::operator+=(const Polynom& pol)
{
int max;
max = (pol.degree > degree ? pol.degree : degree);
for(int i = 0; i <= max; i++)
coeff[i]+= pol.coeff[i];

degree = max;
while (coeff[degree] == 0)
degree--;

}
Polynom Polynom::operator-(const Polynom& pol)
{
int max;
max = (pol.degree > degree ? pol.degree : degree);
Polynom diff;
for(int i = 0; i <= max; i++)
diff.coeff[i] = coeff[i] - pol.coeff[i];

diff.degree = max;
while (diff.coeff[diff.degree] == 0)
diff.degree--;

return diff;
}

void Polynom::operator-=(const Polynom& pol)
{
int max;
max = (pol.degree > degree ? pol.degree : degree);
for(int i = 0; i <= max; i++)
coeff[i]-= pol.coeff[i];

degree = max;
while (coeff[degree] == 0)
degree--;

}

Polynom Polynom::operator*(const Polynom& pol)
{
Polynom prod;
for(int i = 0;i <= pol.degree; i++)
for(int j=0; j <= degree;j++)
prod.coeff[i+j] += (pol.coeff[i]*coeff[j]);
prod.degree = pol.degree + degree;

return prod;
}

void Polynom::operator*=(const Polynom& pol)
{
Polynom prod;
for(int i = 0;i <= pol.degree; i++)
for(int j=0; j <= degree;j++)
prod.coeff[i+j] += (pol.coeff[i]*coeff[j]);
prod.degree =degree + pol.degree;
*this = prod;
}

int& Polynom::operator[](int i)
{
if((i < 0) || (i >= 10000))
std::cout << "Please, don't try to break my cute program((((" << std::endl;
return coeff[i];
}

std::istream& operator>>(std::istream& o, Polynom& pol)
{
o >> pol.degree;
for (int i = 0; i <= pol.degree; i++)
o >> pol.coeff[i];
return o;
}
*/
std::ostream& operator<<(std::ostream& o, const Polynom& pol)
{
    for ( int i = pol.degree; i >= 0; i--)
        o << pol.coeff[i]<<" ";

    return o;
}
/*
Polynom Polynom::substitution(Polynom value)
{
Polynom temp(0,1);
Polynom answer;
;
for (int i = 0; i <= degree; i++)
{
Polynom curr(0, coeff[i]);
answer += temp * curr;
temp *= value;
}
*this = answer;
return answer;
}
*/