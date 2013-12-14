// Объяснение , как работает класс, вконце

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



