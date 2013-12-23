#include <iostream>
#include <fstream>

using namespace std;

#include "Test.h"

Test::Test(){}

Test::Test(string in, string out)
{
    backup = std::cout.rdbuf();
    ifs.open("C:\\Users\\Nikita\\Documents\\GitHub\\TeamFirstFpmiLaba\\GeneralProject_new\\GeneralProject_new\\Tests\\"+in);
    if (inStatus2()&&outStatus2(out))
    {
        cin.rdbuf(ifs.rdbuf());
        ofs.open("C:\\Users\\Nikita\\Documents\\GitHub\\TeamFirstFpmiLaba\\GeneralProject_new\\GeneralProject_new\\Tests\\" + out);
        cout.rdbuf(ofs.rdbuf());
    }
}

bool Test::inStatus()
{
    if (ifs.is_open())
    {
        return true;
    }
    else
    {
        cout << "Wrong input parameter. This should be an existing txt file in Tests directory." << endl;
        return false;
    }
}

bool Test::outStatus(string txt)
{
    int len = strlen(txt.c_str());
    int k = 0;
    for (int i = 0; i < len;i++)
    if (!strcmp(txt.c_str() + i, ".txt"))
        k++;
    if (k == 1)
        return true;
    cout << "Wrong output parameter. Should be `name`.txt ." << endl;
    return false;
}

void Test::check(int num)
{
    if (ifs.is_open())
        ifs.close();
    if (ofs.is_open())
        ofs.close();
    string s = to_string(num);
    result.open("C:\\Users\\Nikita\\Documents\\GitHub\\TeamFirstFpmiLaba\\GeneralProject_new\\GeneralProject_new\\Tests\\output"+s+".txt");
    cin.rdbuf(result.rdbuf());
    string checkResult;
    cin >> checkResult;
    result.close();
    string s2 = to_string(num);    
    checkRes.open("C:\\Users\\Nikita\\Documents\\GitHub\\TeamFirstFpmiLaba\\GeneralProject_new\\GeneralProject_new\\Tests\\result"+s+".txt");
    cin.rdbuf(checkRes.rdbuf());
    string checkResult2;
    cin >> checkResult2;
    checkRes.close();
    ofs.close();
    std::cout.rdbuf(backup);
    if (checkResult == checkResult2)
        cout <<num<< " - Pass"<<endl;
    else cout <<num<< " - Fail"<<endl;

}

void Test::testingProcess()
{
    cout << "Tests:\n";
    for (int i = 1; i <= 18; i++)
    {
        string s = to_string(i);
        Test test("input" + s + ".txt", "result" + s + ".txt");
        Calc a;
        char zz[100];
        cin >> zz;
        cout << a.result(zz) << endl;
        test.check(i);
    }   
}

Test::~Test()
{    
    if (ifs.is_open())
    ifs.close();
    if (ofs.is_open())
    ofs.close();
}

bool Test::inStatus2()
{
    if (ifs.is_open())
    {
        return true;
    }
    else
    {       
        return false;
    }
}

bool Test::outStatus2(string txt)
{
    int len = strlen(txt.c_str());
    int k = 0;
    for (int i = 0; i < len; i++)
    if (!strcmp(txt.c_str() + i, ".txt"))
        k++;
    if (k == 1)
        return true;
    return false;
}