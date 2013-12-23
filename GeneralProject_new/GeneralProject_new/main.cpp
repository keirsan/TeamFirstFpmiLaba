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
    
    Polynom x(3,5);
    x.setPolynom(3);
    x.getPolynom();
    cout << endl;

    Polynom y(3,5);
    y.setPolynom(2);
    y.getPolynom();
    cout << endl;

    x.substitution(y);
    x.getPolynom();
    cout << endl;

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