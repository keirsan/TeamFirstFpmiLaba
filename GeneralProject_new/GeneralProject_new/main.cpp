#include <iostream>
#include "BigInt.h"
#include "Rational.h"
#include "Calc.h"
#include "Polynom.h"
#include "Test.h"
using namespace std;

int main(int argc, char *argv[])
{
    if (argv[1])
    {
        if (argv[1][0] == '-'&&argv[1][5] == 's')
        {
            cout << "Tests:\n";
            for (int i = 1; i <= 3; i++)
            {

                string s = to_string(i);
                Test test("input" + s + ".txt", "result" + s + ".txt");

                Calc a;
                char zz[100];

                cin >> zz;
                cout << a.result(zz) << endl;
                test.check(i);


            }
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