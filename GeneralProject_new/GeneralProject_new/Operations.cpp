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
    char stroka[10000];//_CrtDumpMemoryLeaks();
    int i; int p; bool XXX = false; bool RRR = false;  bool BBB= false;
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
        if (input[i] == '/')
        {
            RRR = true;
        }
        stroka[p] = input[i];
        p++;
    }
    stroka[p] = '\0';
    char degree[50] = "0";

    //double ss;
    //Complex<int> ss(1);
    double dd; //_CrtDumpMemoryLeaks();
    if (!XXX&&strlen(stroka) > 10)
        BBB = true;
    if (XXX&&!RRR)
    for (i = 0, p = 0; true; i++, p++)
    {
        if (stroka[i] == 'x'&&(stroka[i - 1] >= '0'&&stroka[i - 1] <= '9')&&stroka[i + 1] != '\0')
        {
            int k;
            for (k = 0; stroka[i]; k++, i++)
                stroka[k] = stroka[i + 1];
            Complex<int> ss(atof(degree));
            dd = atof(stroka);
            Polynom temp(ss, dd, getX());    
            return temp;
            break;
        }
        /*if (input[i] == 'x')
        {
        continue;
        }*/
        if (stroka[i] == 'x'&&(stroka[i - 1] >= '0'&&stroka[i - 1] <= '9')&&stroka[i + 1] == '\0')
        {
            Complex<int> ss(atof(degree));
            dd = 1;
            Polynom temp(ss, dd, getX());    
            return temp;
            break;
        }
        if (stroka[i] == 'x'&&i == 0 && stroka[i + 1] == '\0')
        {
            Complex<int> ss(1);
            dd = 1;
            Polynom temp(ss, dd, getX());    
            return temp;
            break;
        }
        if (stroka[i] == 'x'&&i == 0 && stroka[i + 1] != '\0')
        {
            
            for (int j = 0; stroka[j]; j++)
            {
                stroka[j] = stroka[j + 1];

            }
            Complex<int> ss(1);
            dd = atof(stroka);
            Polynom temp(ss, dd, getX());    
            return temp;
            break;
        }
        degree[p] = stroka[i];
        if (strlen(degree)>10)
        {
            for (i = 0, p = 0; true; i++, p++)
            {
                if (stroka[i] == 'x'&&(stroka[i - 1] >= '0'&&stroka[i - 1] <= '9')&&stroka[i + 1] != '\0')
                {
                    int k;
                    for (k = 0; stroka[i]; k++, i++)
                        stroka[k] = stroka[i + 1];
                    BigInt bb((string)degree);
                    Complex<BigInt> ss(bb, 0);
                    dd = atof(stroka);
                    Polynom temp(ss, dd, getX());
                    return temp;
                    break;
                }
                /*if (input[i] == 'x')
                {
                continue;
                }*/
                if (stroka[i] == 'x'&&(stroka[i - 1] >= '0'&&stroka[i - 1] <= '9')&&stroka[i + 1] == '\0')
                {
                    BigInt bb((string)degree);
                    Complex<BigInt> ss(bb,0);
                    dd = 1;
                    Polynom temp(ss, dd, getX());
                    return temp;
                    break;
                }
                /*if (stroka[i] == 'x'&&i == 0 && stroka[i + 1] == '\0')
                {
                    Complex<int> ss(1);
                    dd = 1;
                    Polynom temp(ss, dd, getX());
                    return temp;
                    break;
                }
                if (stroka[i] == 'x'&&i == 0 && stroka[i + 1] != '\0')
                {

                    for (int j = 0; stroka[j]; j++)
                    {
                        stroka[j] = stroka[j + 1];

                    }
                    Complex<int> ss(1);
                    dd = atof(stroka);
                    Polynom temp(ss, dd, getX());
                    return temp;
                    break;
                }*/
                degree[p] = stroka[i];
            }
        }

    }
    else  if (XXX&&RRR)
    for (i = 0, p = 0; true; i++, p++)
    {
        if (stroka[i] == 'x'&&(stroka[i - 1] >= '0'&&stroka[i - 1] <= '9')&&stroka[i + 1] != '\0')
        {
            char left[50];
            char right[50];   
            p = 0;
            while (degree[p] != '/')
            {
                left[p] = degree[p];
                p++;
            }
            left[p] = '\0';
            for (int l = 0, n = p + 1; degree[n]; n++,l++)
            {
                right[l] = degree[n];
                right[l+1] = '\0';
            }
             Rational dg(atof(left), atof(right));
            int k;
            for (k = 0; stroka[i]; k++, i++)
                stroka[k] = stroka[i + 1];
           
            Complex<Rational> ss(dg,0);
            dd = atof(stroka);
            Polynom temp(ss, dd, getX());    
            return temp;
            break;
        }
        /*if (input[i] == 'x')
        {
        continue;
        }*/
        if (stroka[i] == 'x'&&(stroka[i - 1] >= '0'&&stroka[i - 1] <= '9')&&stroka[i + 1] == '\0')
        {
            char left[50];
            char right[50];
            p = 0;
            while (degree[p] != '/')
            {
                left[p] = degree[p];
                p++;
            }
            left[p] = '\0';
            for (int l = 0, n = p + 1; degree[n]; n++, l++)
            {
                right[l] = degree[n];
                right[l + 1] = '\0';
            }
            Rational dg(atof(left), atof(right));
            Complex<Rational> ss(dg);
            dd = 1;
            Polynom temp(ss, dd, getX());    
            return temp;
            break;
        }
        if (stroka[i] == 'x'&&i == 0 && stroka[i + 1] == '\0')
        {
            Complex<Rational> ss(1);
            dd = 1;
            Polynom temp(ss, dd, getX());    
            return temp;
            break;
        }
        if (stroka[i] == 'x'&&i == 0 && stroka[i + 1] != '\0')
        {

            for (int j = 0; stroka[j]; j++)
            {
                stroka[j] = stroka[j + 1];

            }
            Complex<Rational> ss(1);
            dd = atof(stroka);
            Polynom temp(ss, dd, getX());    
            return temp;
            break;
        }
        degree[p] = stroka[i];

    }
    else{
        dd = atof(degree);
        if (!RRR&&!BBB)
        {
            Complex<int> ss(atof(stroka), 0);
            Polynom temp(Complex<int>(atof(stroka), 0), dd, getX());
            return temp;
        }
        if (BBB)
        {
            BigInt bb((string)stroka);
            Complex<BigInt> ss(bb, 0);
            //dd = atof(stroka);
            Polynom temp(ss, dd, getX());
            return temp;
        }
        if (RRR)
        {
        char left[50];
        char right[50];
        p = 0;
        while (stroka[p] != '/')
        {
        left[p] = stroka[p];
        p++;
        }
        left[p] = '\0';
        for (int l = 0, n = p + 1; stroka[n]; n++, l++)
        {
        right[l] = stroka[n];
        right[l + 1] = '\0';
        }
        Rational dg(atof(left), atof(right));
        Complex<Rational> ss(dg);
        dd = 0;
        Polynom temp(ss, dd, getX());
        return temp;
        }
        
    }
    
    
}