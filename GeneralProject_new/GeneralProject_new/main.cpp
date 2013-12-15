#include <iostream>
#include "BigInt.h"
#include "Rational.h"
#include "Calc.h"
using namespace std;

// For try, that I won't brake anything
int main()
{
    Calc a;
    cout<<a.result("2+3");
    return 0;
}