#pragma once
#include <fstream>
#include <iostream>

class Test
{
public:
    Test();
    ~Test();
private:
    std::ifstream ifs;
    std::ofstream ofs;
};

