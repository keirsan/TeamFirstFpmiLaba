#pragma once
#include<iostream>
#include<stack>
#include<cstring>
#include<math.h>
#include<ctype.h>

#include"Dictionary.h"
#include"Polynom.h"

using namespace std;

class Calc
{
    int length;
    bool isOK;
    bool isInitialization;
    int point;

    stack <char> operands;
    stack <Polynom> buffer;

        //   Functions

    void pushV(char[], bool&);
    Polynom atoC(int&, char[]);

    Polynom atod(int&, int, char[]);
    Polynom atoB(int&, int, char[]);
    Polynom atoR(int&, int, char[]);

    void recording_toStack(int &, char[]);
    void use_Variable(int &, char[]);

    void oper_mult(int &, char[]);
    void oper_pow(int &, char[]);
    void oper_addit(int &, char[]);
    void oper_subtr(int &, char[]);
    void substitution(int &, char[]);
    void realizeOperators(int &, char[]);
    void realiseBinOper(int, char[]);
    
    //---------------------------------------------

    void inputNumbers(int &, char[], char[]);
    void writeOpFirst_toStack(int &, char[], char[]);
    void writeOpSecond_toStack(int &, char[], char[]);
    void writeCloseBrecket(int &, char[], char[]);

    bool reading(char[]);
    bool reformation(char[]);    

public:
    Polynom result(char[]);    
};