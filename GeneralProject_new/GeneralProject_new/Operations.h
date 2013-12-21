#pragma once
#include "Rational.h"
#include "BigInt.h"
// int BigInt Rational double

//int BigInt
BigInt operator+(BigInt number1, int number2);
BigInt operator+(int number1, BigInt number2);
BigInt operator-(BigInt number1, int number2);
BigInt operator-(int number1, BigInt number2);
BigInt operator*(BigInt number1, int number2);
BigInt operator*(int number1, BigInt number2);

//BigInt Rational
Rational operator+(BigInt number1, Rational number2);
Rational operator+(Rational number1, BigInt number2);
Rational operator-(BigInt number1, Rational number2);
Rational operator-(Rational number1, BigInt number2);
Rational operator*(BigInt number1, Rational number2);
Rational operator*(Rational number1, BigInt number2);

//BigInt double
double operator+(BigInt number1, double number2);
double operator+(double number1, BigInt number2);
double operator-(BigInt number1, double number2);
double operator-(double number1, BigInt number2);
double operator*(BigInt number1, double number2);
double operator*(double number1, BigInt number2);

//Rational double

double operator+(Rational number1, double number2);
double operator+(double number1, Rational number2);
double operator-(Rational number1, double number2);
double operator-(double number1, Rational number2);
double operator*(Rational number1, double number2);
double operator*(double number1, Rational number2);
