#pragma once
#include <iostream>
#include "Complex.h"
using namespace std;

//template <class T>
class CBase
{
public:
    virtual void getComplex(char & Type, int & Ci1,int & Ci2, BigInt & Cb1, BigInt & Cb2, Rational & Cr1, Rational & Cr2, double & Cd1, double & Cd2);
};
