#include <iostream>
#include "BigInt.h"
#include "Rational.h"
#include "Calc.h"
#include "Polynom.h"
#include "Test.h"
#include <Windows.h>
#include <stdlib.h>
using namespace std;

int main(int argc, char *argv[])
{
    if (argv[1])
    {
        if (argv[1][0] == '-'&&argv[1][1] == 't'&&argv[1][2] == 'e'&&argv[1][3] == 's'&&argv[1][4] == 't'&&argv[1][5] == 's')
        {
            Test testing;
            testing.testingProcess();            
            system("pause");
        }
    }
    else
    {
        while (true)
        {
            Calc a;
            char * str = new char[];
            cin >> str;
            if (str[0] == 'e')
                break;
            cout << a.result(str) << endl;
        }
    }
    
    return 0;
}