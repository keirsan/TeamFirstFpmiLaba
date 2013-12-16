#pragma once
#include <fstream>
#include <iostream>
#include <string>

class Test
{
public:
    Test(string,string);
    void check(int);
    ~Test();
private:
    std::ifstream ifs;
    std::ofstream ofs;
    std::ifstream result;
    std::ifstream checkRes;
    std::streambuf *backup;
};

