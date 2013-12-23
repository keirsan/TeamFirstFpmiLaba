#pragma once
#include <iostream>
#include <string>
#include "BigInt.h"
#include "Rational.h"
#include "Calc.h"
#include "Polynom.h"
#include "Test.h"
#include "Operations.h"
#include "stack.h"
#include "Complex.h"
#include "Polynom.h"

using namespace std;

int main(int argc, char * argv[])
{
    
    Polynom x(1,2,2);
    Polynom y(1, 3, 2);
    cout << "arg1=" << x.polValue() << endl;
    cout << "arg2=" << y.polValue() << endl;
    Polynom result(0, x.polValue() + y.polValue(), 0);
    cout <<"res="<< result<<endl;
   // x.getPolynom();
    //cout << endl << x.polValue() << endl;
    // process command line arguments
    if (argc > 1)
    {
        if (argc == 2 && !strcmp(argv[1], "-tests"))
        {
            Test testing;
            testing.testingProcess();
            system("pause");
            return 0;
        }
        cout << "Use -tests to run tests." << endl;
        return 0;
    }
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