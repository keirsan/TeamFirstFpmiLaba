#include <iostream>
#include <fstream>

using namespace std;

#include "Test.h"


Test::Test(string in, string out)
{
    backup = std::cout.rdbuf();
    ifs.open("C:\\Users\\Nikita\\Documents\\GitHub\\TeamFirstFpmiLaba\\GeneralProject_new\\GeneralProject_new\\Tests\\"+in);
    cin.rdbuf(ifs.rdbuf());
    ofs.open("C:\\Users\\Nikita\\Documents\\GitHub\\TeamFirstFpmiLaba\\GeneralProject_new\\GeneralProject_new\\Tests\\"+out);
    cout.rdbuf(ofs.rdbuf());

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

Test::~Test()
{    
    if (ifs.is_open())
    ifs.close();
    if (ofs.is_open())
    ofs.close();
}
