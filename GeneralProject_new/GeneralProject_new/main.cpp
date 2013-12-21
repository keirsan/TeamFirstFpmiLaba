#include <iostream>
#include "BigInt.h"
#include "Rational.h"
#include "Calc.h"
#include "Polynom.h"
#include "Test.h"
#include "Operations.h"

using namespace std;

int main(int argc, char * argv[])
{
    // process command line arguments
    if (argc>1)
    {
        if (argc == 2 && !strcmp(argv[1], "-tests"))
        {
            Test testing;
            testing.testingProcess();            
            system("pause");
            return 0;
        }
        cout<<"Use -tests to run tests."<<endl;
        return 0;
    }

    int a = 4;
    BigInt b = 123456789;
    Rational c(15,4);
    double d = 3.14;

    cout << "!!!" << endl;
    cout << a + a << endl;
    cout << a + b << endl;
    cout << a + c << endl;
    cout << a + d << endl;
    cout << b + a << endl;
    cout << b + b << endl;
    cout << b + c << endl;
    cout << b + d << endl;
    cout << c + a << endl;
    cout << c + b << endl;
    cout << c + c << endl;
    cout << c + d << endl;
    cout << d + a << endl;
    cout << d + b << endl;
    cout << d + c << endl;
    cout << d + d << endl;

    // run calculator
    while (true)
    {
        Calc a;
        char * str = new char[];
        cin >> str;
        if (str[0] == 'e')
            break;
        cout << a.result(str) << endl;
    }

    return 0;
}