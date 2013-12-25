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

Polynom atoP(char* input)
{
    char stroka[10000];
    int i; int p; bool XXX = false;
    for (i = 0, p = 0; true; i++)
    {
        if (input[i] == ' '&&((input[i - 1] >= '0'&&input[i - 1] <= '9') || input[i - 1] == 'x'))
        {
            break;
        }
        if (input[i] == ' ')
        {
            continue;
        }
        if (input[i] == 'x')
        {
            XXX = true;
        }
        stroka[p] = input[i];
        p++;
    }
    stroka[p] = '\0';
    char degree[50] = "0";

    double ss;
    double dd;
    if (XXX)
    for (i = 0, p = 0; true; i++, p++)
    {
        if (stroka[i] == 'x'&&(stroka[i - 1] >= '0'&&stroka[i - 1] <= '9')&&stroka[i + 1] != '\0')
        {
            int k;
            for (k = 0; stroka[i]; k++, i++)
                stroka[k] = stroka[i + 1];
            ss = atof(stroka);
            dd = atof(degree);
            break;
        }
        /*if (input[i] == 'x')
        {
        continue;
        }*/
        if (stroka[i] == 'x'&&(stroka[i - 1] >= '0'&&stroka[i - 1] <= '9')&&stroka[i + 1] == '\0')
        {
            ss = 1;
            dd = atof(degree);
            break;
        }
        if (stroka[i] == 'x'&&i == 0 && stroka[i + 1] == '\0')
        {
            ss = 1;
            dd = 1;
            break;
        }
        if (stroka[i] == 'x'&&i == 0 && stroka[i + 1] != '\0')
        {
            
            for (int j = 0; stroka[j]; j++)
            {
                stroka[j] = stroka[j + 1];

            }
            ss = atof(stroka);
            dd = 1;
            break;
        }
        degree[p] = stroka[i];

    }
    else{
        dd = atof(stroka);
        ss = atof(degree);
    }

    Polynom temp(ss, dd, getX());    // degree is 0 by default, x too
    return temp;
}