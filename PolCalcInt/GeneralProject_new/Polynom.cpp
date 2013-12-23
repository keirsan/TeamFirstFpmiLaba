#include <iostream>
#include "Polynom.h"

Polynom::Polynom()
{
    for(int i = 0; i < 1000; i++)
        coeff[i] = 0;
    degree = 0;
}

Polynom::Polynom(double value)
{
    degree = 0;
    coeff[0] = value;
    for (int i = 1; i < 1000; i++)
        coeff[i] = 0;
    
}

Polynom::Polynom(const Polynom& pol)
{
    degree = pol.degree;
    for (int i = 0; i < 1000; i++)
        coeff[i] = pol.coeff[i];
    x = pol.x;
}

Polynom::Polynom(int deg, int val, int xe)
{
    degree = deg;
    for (int i = 0; i < deg; i++)
        coeff[i] = 0;
    coeff[deg] = val;
    x = xe;
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

double Polynom::polValue()
{
    double temp = 1;
    double result = 0;
    for (int i = 0; i <= degree; i++)
    {
        result += coeff[i] * temp;
        temp *= x;
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
    x = pol.x;
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

double& Polynom::operator[](int i)
{
    if((i < 0) || (i >= 1000))
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

Polynom Polynom::operator*(int num)
{
    Polynom res;
    res = *(this);
    for (int i = res.degree; i >= 0; i--)
        res.coeff[i] = res.coeff[i] * num;
    return res;
}

Polynom operator*(int num, Polynom pol)
{
    Polynom res;
    res = pol;
    for (int i = res.degree; i >= 0; i--)
        res.coeff[i] = res.coeff[i] * num;
    return res;
}

bool Polynom::operator==(int num)
{
    if (this->polValue(2) == num) return true;
    else return false;
}

Polynom pow(Polynom pol1, Polynom pol2)
{
    Polynom temp;
    temp = pol1;
    for (Polynom i = 1; i < pol2; i = i + 1)
        pol1 = pol1*temp;
    return pol1;
}

bool Polynom::operator<(Polynom pol)
{
    Polynom temp=*this;
    int eq = 0;
    if (temp.degree < pol.degree)
        return true;
    else if (temp.degree == pol.degree)
    {
        for (int j = 0; j < temp.degree;j++)
        if (temp.coeff[j] == pol.coeff[j] || temp.coeff[j] < pol.coeff[j])
            eq++;
        if (eq == temp.degree)
            return true;
    }
    else return false;
}