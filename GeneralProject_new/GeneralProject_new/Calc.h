#include<iostream>
#include<stack>
#include<cstring>
#include<math.h>
#include<ctype.h>

#include"Dictionary.h"

using namespace std;

class Calc
{
    int length;
    bool isOK;
    int point;

    stack <char> operands;
    stack <double> buffer;

        //   Functions

    void recording_toStack(int &, char expression[]);
    void use_Variable(int &, char expression[]);

    void oper_mult(int &, char expression[]);
    void oper_pow(int &, char expression[]);
    void oper_addit(int &, char expression[]);
    void oper_subtr(int &, char expression[]);
    void realizeOperators(int &, char expression[]);
    void realiseBinOper(int, char expression[]);
    
    //---------------------------------------------

    void inputNumbers(int &, char expressionConv[], char expression[]);
    void writeOpFirst_toStack(int &, char expressionConv[], char expression[]);
    void writeOpSecond_toStack(int &, char expressionConv[], char expression[]);
    void writeCloseBrecket(int &, char expressionConv[], char expression[]);

    bool reading(char expression[]);
    bool reformation(char expressionConv[]);

public:
    void pushV(char V[], bool& isOK);
    double result(char expressionConv[]);    
};
