#include <iostream>
#include "BigInt.h"
#include "Rational.h"
#include "Calc.h"
#include "Polynom.h"
#include "Test.h"
#include "Operations.h"
#include "stack.h"
#include "Complex.h"

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