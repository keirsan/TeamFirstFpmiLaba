#include <iostream>
#include <fstream>

using namespace std;

#include "Test.h"


Test::Test()
{
    ifs.open("input.txt");
    cin.rdbuf(ifs.rdbuf());
    ofs.open("output.txt");
    cout.rdbuf(ofs.rdbuf());

}


Test::~Test()
{
    ifs.close();
    ofs.close();
}
