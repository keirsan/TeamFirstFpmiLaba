#include "Operations.h"
#include "Rational.h"
#include "BigInt.h"

BigInt operator+(BigInt number1, int number2)
{
    return number1 + (BigInt)number2;
}

BigInt operator+(int number1, BigInt number2)
{
    return (BigInt)number1 + number2;
}

BigInt operator-(BigInt number1, int number2)
{
    return number1 - (BigInt)number2;
}

BigInt operator-(int number1, BigInt number2)
{
    return (BigInt)number1 - number2;
}

BigInt atoB(char* input) 
{
    char stroka[10000];
    int i; int p;
    for (i=0,p=0; true; i++)
    {
        if (input[i] == ' '&&input[i-1]>='0'&&input[i-1]<='9')
        {
            break;
        }
        if (input[i] == ' ')
        {
            continue;
        }
        stroka[p] = input[i];      
        p++;
    }
    stroka[p] = '\0';    
    return BigInt((string)stroka);
}

BigInt operator*(BigInt number1, int number2)
{
    return number1 * (BigInt)number2;
}

BigInt operator*(int number1, BigInt number2)
{
    return (BigInt)number1 * number2;
}

Rational operator+(BigInt number1, Rational number2)
{
    Rational number(number1.getInt(), 1);
    return number + number2;
}

Rational operator+(Rational number1, BigInt number2)
{
    Rational number(number2.getInt(), 1);
    return number + number1;
}

Rational operator-(BigInt number1, Rational number2)
{
    Rational number(number1.getInt(), 1);
    return number - number2;
}

Rational operator-(Rational number1, BigInt number2)
{
    Rational number(number2.getInt(), 1);
    return number1 - number;
}

Rational operator*(BigInt number1, Rational number2)
{
    Rational number(number1.getInt(), 1);
    return number * number2;
}

Rational operator*(Rational number1, BigInt number2)
{
    Rational number(number2.getInt(), 1);
    return number1 * number;
}

double operator+(BigInt number1, double number2)
{
    double number = number1.getLongLong();
    return number + number2;
}

double operator+(double number1, BigInt number2)
{
    double number = number2.getLongLong();
    return number + number1;
}

double operator-(BigInt number1, double number2)
{
    double number = number1.getLongLong();
    return number - number2;
}

double operator-(double number1, BigInt number2)
{
    double number = number2.getLongLong();
    return number1 - number;
}

double operator*(BigInt number1, double number2)
{
    double number = number1.getLongLong();
    return number * number2;
}

double operator*(double number1, BigInt number2)
{
    double number = number2.getLongLong();
    return number1 * number;
}

double operator+(Rational number1, double number2)
{
    return number1.getDouble() + number2; 
}

double operator+(double number1, Rational number2)
{
    return number2.getDouble() + number1; 
}

double operator-(Rational number1, double number2)
{
    return number1.getDouble() - number2; 
}

double operator-(double number1, Rational number2)
{
    return number1 - number2.getDouble(); 
}

double operator*(Rational number1, double number2)
{
    return number1.getDouble() * number2; 
}

double operator*(double number1, Rational number2)
{
    return number1 * number2.getDouble(); 
}