#include <iostream>
#include "BigInt.h"
#include "Rational.h"
using namespace std;

// For try, that I won't brake anything
int main()
{
    BigInt c(228);
    cout << (c ^ 1488) << endl; 
    Rational a(2,3);
    Rational b(1,6);
    a = a + b;
    cout << a;
    return 0;
}