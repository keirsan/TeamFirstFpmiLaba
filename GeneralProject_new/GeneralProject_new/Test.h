#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include "Calc.h"
class Test
{
public:
    Test();
    Test(string,string);
    void testingProcess();
    void check(int);
    ~Test();
private:
    std::ifstream ifs;
    std::ofstream ofs;
    std::ifstream result;
    std::ifstream checkRes;
    std::streambuf *backup;
};

