// Объяснение , как работает класс, вконце
#pragma once
#include<iostream>
#include<stack>
#include<cstring>
#include<math.h>
#include<ctype.h>

#include "Dictionary.h"
#include "Operations.h"

using namespace std;


class Calc
{
    int length;
    bool isOK;
    int point;

    stack <char> operands;
    stack <Polynom> buffer;

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
    Polynom result(char expressionConv[]);    
};

double getX();

/*     Функции result() передаётся строка, которая превращается в строку ОПЗ в функции reformaton()
При преобразовании числа и переменные записываются в строку сразу, а операторы помещаются в стек. У операторов *, / приоритет выше, чем у + и -. При переводе проверяет правильность расстановки круглых скобок.

Функция reading() читает ОПЗ и вычисляет. Числа загоняются в стек, а операции выполняются сразу после их нахождения.

Пример: expressionConv[] = 5*2.3-1
Функция идёт по строке
i = 0: 5 - записываем в новую строку. expression[] = 5
i = 1: * - заносим в стек операторов. expression[] = 5
i = 2: 2 - записываем в новую строку. expression[] = 5 2
i = 3: . - записываем в новую строку. expression[] = 5 2.
i = 4: 3 - записываем в новую строку. expression[] = 5 2.3 
i = 5: - - проверяем последний оператор в стеке, если это оператор, который выше по приоритету, записываем его в строку. Т.к. последнее - это умножение, то в строку записываем *. expression[] = 5 2.3 *
i = 6: 1 - записываем в новую строку. expression[] = 5 2.3 * 1
После всего оставшиеся операторы записываем в строку
Конечная ОПЗ -  expression[] = 5 2.3 * 1 -
 ОПЗ считаем, знося в стек числаи попутно выполняя действия операторов
*/



