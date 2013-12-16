#include <iostream>
#include "Polynom.h"

Polynom::Polynom()
{
    for(int i = 0; i < 10000; i++)
        coeff[i] = 0;
    degree = 0;
}

Polynom::Polynom(double value)
{
    degree = 0;
    coeff[0] = value;
    for (int i = 1; i < 10000; i++)
        coeff[i] = 0;
}

Polynom::Polynom(const Polynom& pol)
{
    degree = pol.degree;
    for (int i = 0; i < 10000; i++)
        coeff[i] = pol.coeff[i];
}

void Polynom::setPolynom(int deg)
{
    degree = deg;
    for(int i = 0; i <= degree; i++)
        std::cin >> coeff[i];
    return;
}

void Polynom::getPolynom()
{
    for(int i = degree; i >= 0; i--)
        std::cout << coeff[i] << " ";
    std::cout << std::endl;
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
void Polynom::division(const Polynom& pol1, const Polynom& pol2)
{
    Polynom quot;
    Polynom rem(pol1);
    quot.degree = rem.degree - pol2.degree;
    
    while (rem.degree >= pol2.degree)
    {
        quot.coeff[rem.degree - pol2.degree] = rem.coeff[rem.degree]/pol2.coeff[pol2.degree];
        Polynom temp;
	    temp.coeff[rem.degree - pol2.degree] = rem.coeff[rem.degree]/pol2.coeff[pol2.degree];
        Polynom temp2;
        temp2.mult(temp, pol2); 
	    rem -= temp2;
    }
    *this = quot;

}
void Polynom::operator=(const Polynom& pol)
{
    degree = pol.degree;
    for (int i = 0; i < 10000; i++)
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
Polynom Polynom::operator/(const Polynom& pol)
{
    Polynom quot;
    Polynom rem;
    rem = *this;
    quot.degree = rem.degree - pol.degree;
    
    while (rem.degree >= pol.degree)
    {
        quot.coeff[rem.degree - pol.degree] = rem.coeff[rem.degree]/pol.coeff[pol.degree];
        Polynom temp;
	    temp.coeff[rem.degree - pol.degree] = rem.coeff[rem.degree]/pol.coeff[pol.degree];
	    rem = rem - (temp * pol);
    }
    return quot;
 }

void Polynom::operator/=(const Polynom& pol)
{
    Polynom quot;
    Polynom rem;
    rem = *this;
    quot.degree = rem.degree - pol.degree;
    
    while (rem.degree >= pol.degree)
    { 
        quot.coeff[rem.degree - pol.degree] = rem.coeff[rem.degree]/pol.coeff[pol.degree];
        Polynom temp;
	    temp.coeff[rem.degree - pol.degree] = rem.coeff[rem.degree]/pol.coeff[pol.degree];
	    rem = rem - (temp * pol);
    }

    *this = quot;
 }

Polynom Polynom::operator%(const Polynom& pol)
{
    Polynom rem;
    rem = *this;
    
    while (rem.degree >= pol.degree)
    {
        Polynom temp;
	    temp.coeff[rem.degree - pol.degree] = rem.coeff[rem.degree]/pol.coeff[pol.degree];
	    rem = rem - (temp * pol);
    }
return rem;
 }

void Polynom::operator%=(const Polynom& pol)
{
    Polynom rem;
    rem = *this;
    
    while (rem.degree >= pol.degree)
    {
        Polynom temp;
	    temp.coeff[rem.degree - pol.degree] = rem.coeff[rem.degree]/pol.coeff[pol.degree];
	    rem = rem - (temp * pol);
    }

    *this = rem;
 }
double& Polynom::operator[](int i)
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

std::ostream& operator<<(std::ostream& o, const Polynom& pol)
{
    for ( int i = pol.degree; i >= 0; i--)
        o << pol.coeff[i]<<" ";

    return o;
}
