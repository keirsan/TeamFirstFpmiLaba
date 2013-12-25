#include <iostream>
#include <string>
#include <sstream>
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
    
    /* Complex<int> gg(1, 2);
     CBase& lol = gg;*/

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
        if (argc == 3)
        {
            Test flow(argv[1],argv[2]);
            if (flow.inStatus()&&flow.outStatus(argv[2]))
            {
                Calc a;
                char * str = new char[];
                cin >> str;
                cout << a.result(str) << endl;
            }
            else{
                cout << "Wrong command line parameters." << endl;
            }
            return 0;
        }
        
    }
    // run calculator
    int counter = 0;
    Dictionary dict;
    while (true)
    {
        counter++;
        cout << "In[" << counter << "]:=";
        Calc a;
        char * str = new char[];
        cin >> str;
        if (str[0] == 'e')
            break;
        Polynom ans = a.result(str).polValue();
        stringstream ss;
        ss << ans;
        string strr = ss.str();
        dict.add(counter, strr);
        cout << "Out[" << counter << "]=" << ans << endl;
    }

    return 0;
}