#include"Calc.h"

Dictionary Var;

void Calc::pushV(char V[], bool& isOK)     
{
    isOK = false;
    double v = 0;
    char * n = 0;
    bool isFirst = true;
    for(int j = 0; V[j]; j++)
    {            
        if(V[j] == ' ')
            continue;
        if(V[j] == '=' && isFirst)
        {
            V[j] = ' ';
            isFirst = false;
            continue;
        }
        else if(V[j] == '=' && !isFirst)
        {
            cout<<"ERROR! Wrong input of variable"<<endl;
            isOK = false;
            break;
        }
        if(!isOK && isalpha(V[j]))
        {
            int len = 1;
            while(isalpha(V[j + len]))
                len++;
            n = new char [len];
            for(int i = 0; i < len; i++)
            {
                n[i] = V[j + i];
                V[j + i] = ' ';
            }
            n[len] = '\0';
            isOK = true;
        }
        else if(isOK && (isdigit(V[j]) || V[j] == '-'))
        {
            v = atof(V);
            break;
        }
        else
        {
            isOK = false;
            cout<<"ERROR! Wrong input of variable"<<endl;
            break;
        }
    }
    Var.add((int)v, n);
}

//----------------------------------------------------------------------------------

void Calc::recording_toStack(int &start, char expression[])	// push number in stack and check is number was input correctly
{
	int len;	// length of quantity
	bool isFirstFullStop = true;	// is full stop in double firstly received
	for(len = 0; ((expression[start + len] >= '0') && (expression[start + len] <= '9')) || (expression[start + len] == '.'); len++)
	{
		if(expression[start + len] == '.')
        {
            if(!isFirstFullStop)
		    {
			    isOK = false;
			    break;
		    }
			isFirstFullStop = false;
        }
	}
    Complex<int> coef(atoi(expression), 0);
    Polynom x(coef, 0);
	buffer.push(x);
	for(int k = 0; k < len; k++)
		expression[start + k] = ' ';
	start += len - 1;
}

//----------------------------------------------------------------------------------

void Calc::oper_mult(int &start, char expression[])	// multiplication
{
	if(buffer.size() == 0)
    {
        isOK = false;
        cout<<"Error! Amount of operands less than amount of operations"<<endl;
    }
	else
	{
		Polynom arg1 = buffer.top();
		buffer.pop();
		if(buffer.size() == 0)
        {
           isOK = false;
           cout<<"Error! Amount of operands less than amount of operations"<<endl;
        }
		else
		{
			Polynom arg2 = buffer.top();
			buffer.pop();
			Polynom result = arg2 * arg1;
			buffer.push(result);
		    expression[start] = ' ';
		}
	}
}

void Calc::oper_pow(int &start, char expression[])	
{
	if(buffer.size() == 0)
    {
        isOK = false;
        cout<<"Error! Amount of operands less than amount of operations"<<endl;
    }
	else
	{
		Polynom arg1 = buffer.top();
		buffer.pop();
		if(buffer.size() == 0)
        {
            isOK = false;
            cout<<"Error! Amount of operands less than amount of operations"<<endl;
        }
		else
        {
            Polynom arg2 = buffer.top();
            buffer.pop();
            Polynom result = arg2^arg1;
            buffer.push(result);
            for(int i = 0; i < 3; i++)
                expression[start] = ' ';
		}
	}
}

void Calc::oper_addit(int &start, char expression[])	// addition
{
	if(buffer.size() == 0)
    {
        isOK = false;
        cout<<"Error! Amount of operants less than amount of operations"<<endl;
    }
	else
	{
		Polynom arg1 = buffer.top();
		buffer.pop();
		if(buffer.size() == 0)
        {
            isOK = false;
            cout<<"Error! Amount of operants less than amount of operations"<<endl;
        }
		else
		{
			Polynom arg2 = buffer.top();
			buffer.pop();
			Polynom result = arg2 + arg1;
			buffer.push(result);
            expression[start] = ' ';
		}
	}
}

void Calc::oper_subtr(int &start, char expression[])	// subtraction
{
	if(buffer.size() == 0)
    {
        isOK = false;
        cout<<"Error! Amount of operants less than amount of operations"<<endl;
    }
	else
	{
		Polynom arg1 = buffer.top();
		buffer.pop();
		if(buffer.size() == 0)
        {
            isOK = false;
            cout<<"Error! Amount of operants less than amount of operations"<<endl;
        }
		else
		{
			Polynom arg2 = buffer.top();
			buffer.pop();
			Polynom result = arg2 - arg1;
			buffer.push(result);
			for(int i = 0; i < 3; i++)
		    	expression[start] = ' ';
		}
	}
}

void Calc::substitution(int &start, char expression[])
{
	if(buffer.size() == 0)
    {
        isOK = false;
        cout<<"Error! Amount of operants less than amount of operations"<<endl;
    }
	else
	{
		Polynom arg1 = buffer.top();
		buffer.pop();
		if(buffer.size() == 0)
        {
            isOK = false;
            cout<<"Error! Amount of operants less than amount of operations"<<endl;
        }
		else
		{
			Polynom arg2 = buffer.top();
			buffer.pop();
			Polynom result = arg2;//.substitution(arg1);
			buffer.push(result);
			for(int i = 0; i < 3; i++)
		    	expression[start] = ' ';
		}
	}
}

void Calc::realizeOperators(int &start, char expression[])
{
	if(expression[start] == '*')
		oper_mult(start, expression);
	else if(expression[start] == '^')
		oper_pow(start, expression);
	else if(expression[start] == '+')
		oper_addit(start, expression);
	else if(expression[start] == '-')
		oper_subtr(start, expression);
    else if(expression[start] == '&')
		sustitution(start, expression);
}

//-----------------------------------------------------------------------------------

void Calc::realiseBinOper(int start, char expression[])
{
    expression[start - 1] = ' ';
	if(buffer.size() == 0)
    {
        isOK = false;
        cout<<"Error! Amount of operants less than amount of operations"<<endl;
    }
	else
	{
        Polynom sign(-1);
		Polynom result = sign * buffer.top();
        buffer.pop();
        buffer.push(result);
	}
}

//-----------------------------------------------------------------------------------

void Calc::use_Variable(int & start, char expression[])
{
    char n[100];
    int i = 0;
    while(isalpha(expression[start + i]))
    {
        n[i] = expression[start + i];
        expression[start + i] = ' ';
        i++;
    }
    n[i] = '\0';
    double value = Var.search(n, isOK);
    if(!isOK)
    {
        cout<<"ERROR! You input indefenite variable!"<<endl;
        return;
    }
    Polynom x((int)value);
    buffer.push(x);
    start += i - 1;
}

//-----------------------------------------------------------------------------------

bool Calc::reading(char expression[])	//find numbers, functions & operations in inverse polish record
{
    isOK = true;
    length = strlen(expression);
    for(int i = 0; expression[i]; i++)
    {
        if(expression[i] == ' ')
			continue;
        else if((expression[i] >= '0') && (expression[i] <= '9'))
            recording_toStack(i, expression);
        else if(expression[i] == 'x')
        {
            Complex<int> coef(1, 0);
            Polynom x(coef, 1);
            buffer.push(x);
            expression[i] = ' ';
        }
        else if(expression[i] == 'i')
        {
            Complex<int> coef(0, 1);
            Polynom x(coef, 0);
            buffer.push(x);
            expression[i] = ' ';
        }
        else if(isalpha(expression[i]))
            use_Variable(i, expression);
        else if(expression[i] == '*' || expression[i] == '+' || expression[i] == '-' || expression[i] == '^' || expression[i] == '&')
			realizeOperators(i, expression);
		else if(expression[i] == '_')
			realiseBinOper(i + 1, expression);
		else
		{
            cout<<"ERROR! You input unknown operation!"<<endl;
            isOK = false;
        }

        if(isOK)
            continue;
        else
            break;
    }
    return isOK;
}

//-----------------------------------------------------------------------------------

void Calc::inputNumbers(int &start, char expressionConv[], char expression[])
{
	while(((expressionConv[start] >= '0') && (expressionConv[start] <= '9')) || (expressionConv[start] == '.'))
	{
		expression[point] = expressionConv[start];
        start++;
		point++;
	}
    if(operands.size() != 0 && operands.top() == '_')
    {
        expression[point++] = '_';
        operands.pop();
    }
    if(expressionConv[start] == 'x')
    {
        expression[point++] = 'x';
        expressionConv[start] = '*';
        writeOpFirst_toStack(start, expressionConv, expression);
    }
    else if(expressionConv[start] == '/')
        expression[point++] = '/';
    else if(expressionConv[start] == 'i')
    {
        expression[point++] = 'i';
        expressionConv[start] = '*';
        writeOpFirst_toStack(start, expressionConv, expression);
    }
    else
        start--;
    expression[point] = ' ';
    point++;
}

//---------------------------------------

void Calc::writeOpFirst_toStack(int &start, char expressionConv[], char expression[])        //what we do with '*' and '/'
{
    if(operands.size() != 0 && operands.top() == '*')
    {
        expression[point++] = operands.top();
        operands.pop();
    }
    if(operands.size() != 0 && operands.top() == '^')
    {
        expression[point++] = operands.top();
        operands.pop();
        if(operands.size() != 0 && operands.top() == '*')
        {
            expression[point++] = operands.top();
            operands.pop();
        }
    }
    if(operands.size() != 0 && operands.top() == '&')
    {
        expression[point++] = operands.top();
        operands.pop();
        if(operands.size() != 0 && operands.top() == '^')
        {
            expression[point++] = operands.top();
            operands.pop();
            if(operands.size() != 0 && operands.top() == '*')
            {
                expression[point++] = operands.top();
                operands.pop();
            }
        }
    }
    operands.push(expressionConv[start]);
}

void Calc::writeOpSecond_toStack(int &start, char expressionConv[], char expression[])        //what we do with '+' and '-'
{
    if((point == 0 && operands.size() == 0) || expressionConv[start - 1] == '(' || (expressionConv[start - 1] == ' ' && expressionConv[start - 2] == '('))
        operands.push('_');
    else
    {
        
        if(operands.size() != 0 && (operands.top() == '+' || operands.top() == '-'))
        {
            expression[point++] = operands.top();
            operands.pop();
        }
        if(operands.size() != 0 && operands.top() == '*')
        {
            expression[point++] = operands.top();
            operands.pop();
            if(operands.size() != 0 && (operands.top() == '+' || operands.top() == '-'))
            {
                expression[point++] = operands.top();
                operands.pop();
            }
        }
        if(operands.size() != 0 && operands.top() == '^')
        {
            expression[point++] = operands.top();
            operands.pop();
            if(operands.size() != 0 && (operands.top() == '*' || operands.top() == '/'))
            {
                expression[point++] = operands.top();
                operands.pop();
                if(operands.size() != 0 && (operands.top() == '+' || operands.top() == '-'))
                {
                    expression[point++] = operands.top();
                    operands.pop();
                }
            }
        }
        if(operands.size() != 0 && operands.top() == '&')
        {
            expression[point++] = operands.top();
            operands.pop();
            if(operands.size() != 0 && operands.top() == '^')
            {
                expression[point++] = operands.top();
                operands.pop();
                if(operands.size() != 0 && (operands.top() == '*' || operands.top() == '/'))
                {
                    expression[point++] = operands.top();
                    operands.pop();
                    if(operands.size() != 0 && (operands.top() == '+' || operands.top() == '-'))
                    {
                        expression[point++] = operands.top();
                        operands.pop();
                    }
                }
            }
        }
        operands.push(expressionConv[start]);
    }
}

//---------------------------------------

void Calc::writeCloseBrecket(int &start, char expressionConv[], char expression[])
{
    if(operands.top() == '(')
        operands.pop();
    else
    {
        while(operands.top() != '(')
        {
            expression[point++] = operands.top();
            operands.pop();
        }
        operands.pop();
    }
}

//---------------------------------------

bool Calc::reformation(char expressionConv[])		// convert normal expression to inverse polish record
{
    point = 0;
    isOK = true;
    length = strlen(expressionConv);
    char * expression;
    expression = new char [3*length];
    int OpenedBrackets = 0;
    for(int i = 0; i < length; i++)
    {
        if(expressionConv[i] == ' ')
			continue;
        else if(expressionConv[i] == ',')
        {
            if(operands.size() != 0 && operands.top() != '(')
            {
                expression[point++] = operands.top();
                operands.pop();
            }
            else
                continue;
        }
        else if((expressionConv[i] >= '0') && (expressionConv[i] <= '9'))
            inputNumbers(i, expressionConv, expression);            
        else if(expressionConv[i] == 'x')
        {
            expression[point++] = ' ';
            expression[point++] = 'x';
        }
        else if(expressionConv[i] == 'i')
        {
            expression[point++] = ' ';
            expression[point++] = 'i';
        }
        else if(isalpha(expressionConv[i]))
        {
            expression[point++] = expressionConv[i];
            if(!isalpha(expressionConv[i + 1]))
                expression[point++] = ' ';
        }        
        else if(expressionConv[i] == '^')
        {
            if(operands.size() != 0 && operands.top() == '^')
            {
                expression[point++] = operands.top();
                operands.pop();
            }
            if(operands.size() != 0 && operands.top() == '&')
            {
                expression[point++] = operands.top();
                operands.pop();
                if(operands.size() != 0 && operands.top() == '^')
                {
                    expression[point++] = operands.top();
                    operands.pop();
                }
            }
            operands.push(expressionConv[i]);
        }
        else if(expressionConv[i] == '*')
            writeOpFirst_toStack(i, expressionConv, expression);
        else if(expressionConv[i] == '+' || expressionConv[i] == '-')
		    writeOpSecond_toStack(i, expressionConv, expression);
        else if(expressionConv[i] == '(')
        {
            operands.push('(');
            OpenedBrackets++;
            int j = 1;
            while(expressionConv[i - j] == ' ')
                j--;
            if(expressionConv[i - j] != '*' && expressionConv[i - j] != '-' && expressionConv[i - j] != '+')
            {
                if(operands.top() == '&')
                {
                    expression[point++] = '&';
                    operands.pop();
                }
                operands.push('&');
            }
        }
        else if(expressionConv[i] == ')')
        {
            if(OpenedBrackets != 0)
            {
                writeCloseBrecket(i, expressionConv, expression);
                OpenedBrackets--;
            }
            else
                isOK = false;
        }
        else
        {
            cout<<"ERROR! You input unknown operation!"<<endl;
            isOK = false;
        }
        if(isOK)
            continue;
        else
            break;
    }
    if(OpenedBrackets == 0)
            isOK = true;
    else
    {
        cout<<"ERROR! You input wrong expression! You put brackets incorrectly"<<endl;
        isOK = false;
    }
    while(operands.size())
    {        
        expression[point++] = operands.top();
        if(operands.top() == '(')
            isOK = false;
        operands.pop();        
    }
    expression[point++] = '\0';
    if(isOK)
        isOK = reading(expression);
    else
        cout<<"ERROR! You input wrong expression! You put brackets incorrectly"<<endl;
    return isOK;
}


Polynom Calc::result(char expressionConv[])
{
    isOK = reformation(expressionConv);
    Polynom result(0);
    if(isOK && buffer.size())
    {
        result = buffer.top();
        buffer.pop();
    }
    while(buffer.size())
        buffer.pop();
    while(operands.size())
        operands.pop();
    return result;
}