#include<iostream>
#include<stack>
#include<cstring>
#include<math.h>
#include<ctype.h>

using namespace std;

class Calc
{
    int length;
    bool isOK;
    int point;

    stack <char> operands;
    stack <double> buffer;

        //   Functions

    void recording_toStack(int &, char expression[], stack <double> & buffer);
    void buf_sin(int &, char expression[], stack <double> & buffer);
    void buf_sqrt(int &, char expression[], stack <double> & buffer);
    void buf_cos(int &, char expression[], stack <double> & buffer);
    void buf_abs(int &, char expression[], stack <double> & buffer);
    void buf_log(int &, char expression[], stack <double> & buffer);
    void buf_pow(int &, char expression[], stack <double> & buffer);
    void realizeFunctions(int &, char expression[], stack <double> & buffer);
    void use_Variable(int &, char expression[], stack <double> & buffer);

    void oper_mult(int &, char expression[], stack <double> & buffer);
    void oper_div(int &, char expression[], stack <double> & buffer);
    void oper_addit(int &, char expression[], stack <double> & buffer);
    void oper_subtr(int &, char expression[], stack <double> & buffer);
    void realizeOperators(int &, char expression[], stack <double> & buffer);
    void realiseBinOper(int, char expression[], stack <double> & buffer);
    
    //---------------------------------------------

    void writeF_toStack(int &, char expressionConv[], char expression[], stack <char> & operands);
    void writeF_toExpression(char expressionConv[], char expression[], stack <char> & operands);
    void inputNumbers(int &, char expressionConv[], char expression[], stack <char> & operands);
    void writeOpFirst_toStack(int &, char expressionConv[], char expression[], stack <char> & operands);
    void writeOpSecond_toStack(int &, char expressionConv[], char expression[], stack <char> & operands);
    void writeCloseBrecket(int &, char expressionConv[], char expression[], stack <char> & operands);

public:
    struct Variable
    {
        double value;
        char name[100];
        Variable * next;
    };
    void pushV(char V[], bool&);

private: 
    double searchV(char n[], bool&);
    bool reading(char expression[]);
    bool reformation(char expressionConv[]);
    void destruct();

public:
    double result(char expressionConv[]);
    
};
