#include <iostream>
#include "BigInt.h"
#include "Rational.h"

// For try, that I won't brake anything
int main()
{
    Rational a(2,3);
    Rational b(1,6);
    a = a + b;
    cout << a;
    return 0;
}