#include"Calc.h"

Calc::Variable * start;

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
    if(n)            
    {
        if(!start)
        {
            start = new Variable;
            strcpy(start->name, n);
            start->value = v;
            start->next = 0;
        }
        else
        {
            Variable * pnew = new Variable;
            pnew->value = v;
            strcpy(pnew->name, n);
            pnew->next = start;
            start = pnew;
        }
    }
}

double Calc::searchV(char n[], bool& isOK)
{
    Variable * cur = start;
    while(cur)
    {
        if(!strcmp(cur->name, n))
            break;
        cur = cur->next;
    }
    if(cur)
        return cur->value;
    isOK = false;
    return 0;
}

void Calc::destruct()
{
    while(start)
    {
        Variable * temp;
        temp = start->next;
        delete start;
        start = temp;
    }
}

//----------------------------------------------------------------------------------

void Calc::recording_toStack(int &start, char expression[], stack <double> & buffer)	// push number in stack and check is number was input correctly
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
	buffer.push(atof(expression));
	for(int k = 0; k < len; k++)
		expression[start + k] = ' ';
	start += len - 1;
}

//----------------------------------------------------------------------------------

void Calc::buf_sin(int &start, char expression[], stack <double> & buffer)
{
	if(buffer.size() == 0)
    {
        isOK = false;
        cout<<"Error! Amount of operands less than amount of operations"<<endl;
    }
	else
	{
		double result = sin(buffer.top());
		buffer.pop();
		buffer.push(result);
		for(int i = 0; i < 3; i++)
			expression[start + i] = ' ';
		start+=2;
	}
}

void Calc::buf_sqrt(int &start, char expression[], stack <double> & buffer)
{
	if(buffer.size() == 0)
    {
        isOK = false;
        cout<<"Error! Amount of operands less than amount of operations"<<endl;
    }
	else
	{
        if(buffer.top() < 0)
        {
            isOK = false;
            cout<<"Error! Can't use sqrt(x) for x < 0"<<endl;
        }

		else
        {
            double result = sqrt(buffer.top());
		    buffer.pop();
	    	buffer.push(result);
	    	for(int i = 0; i < 4; i++)
	    		expression[start + i] = ' ';
	    	start+=3;
        }
	}
}

void Calc::buf_cos(int &start, char expression[], stack <double> & buffer)
{
	if(buffer.size() == 0)
    {
        isOK = false;
        cout<<"Error! Amount of operands less than amount of operations"<<endl;
    }
	else
	{
		double result = cos(buffer.top());
		buffer.pop();
		buffer.push(result);
		for(int i = 0; i < 3; i++)
			expression[start + i] = ' ';
		start+=2;
	}
}

void Calc::buf_abs(int &start, char expression[], stack <double> & buffer)
{
	if(buffer.size() == 0)
    {
        isOK = false;
        cout<<"Error! Amount of operands less than amount of operations"<<endl;
    }
	else
	{
		double result = fabs(buffer.top());
		buffer.pop();
		buffer.push(result);
		for(int i = 0; i < 3; i++)
			expression[start + i] = ' ';
		start+=2;
	}
}

void Calc::buf_log(int &start, char expression[], stack <double> & buffer)
{
	if(buffer.size() == 0)
    {
        isOK = false;
        cout<<"Error! Amount of operands less than amount of operations"<<endl;
    }
	else
	{
		double arg1 = buffer.top();
		buffer.pop();
        if(arg1 <= 0 || arg1 == 1)
        {
            isOK = false;
            cout<<"Error! Incorrect value of argument under log() function"<<endl;
        }
        else
        {
		    if(buffer.size() == 0)
            {
               isOK = false;
               cout<<"Error! Amount of operands less than amount of operations"<<endl;
            }
	    	else
	    	{
		    	double arg2 = buffer.top();
    			buffer.pop();
                if(arg2 <= 0)
                {
                    isOK = false;
                    cout<<"Error! Incorrect value of argument under log() function"<<endl;
                }
			    else
                {
                    double result = log(arg2) / log(arg1);
		        	buffer.push(result);
		        	for(int i = 0; i < 3; i++)
		    	        expression[start + i] = ' ';
		        	start+=2;
                }
		    }
        }
	}
}

void Calc::buf_pow(int &start, char expression[], stack <double> & buffer)
{
	if(buffer.size() == 0)
    {
        isOK = false;
        cout<<"Error! Amount of operants less than amount of operations"<<endl;
    }
	else
	{
		double arg1 = buffer.top();
		buffer.pop();
		if(buffer.size() == 0)
        {
           isOK = false;
           cout<<"Error! Amount of operants less than amount of operations"<<endl;
        }
		else
		{
			double arg2 = buffer.top();
			buffer.pop();
			double result = pow(arg2, arg1);
			buffer.push(result);
			for(int i = 0; i < 3; i++)
    			expression[start + i] = ' ';
			start+=2;
		}
	}
}

void Calc::realizeFunctions(int &start, char expression[], stack <double> & buffer)       // identify functions(log, pow, sin, etc.)
{
	if(expression[start] == 's' &&  expression[start + 1] == 'q' && expression[start + 2] == 'r' && expression[start + 3] == 't')
		buf_sqrt(start, expression, buffer);
	else if(expression[start] == 's' &&  expression[start + 1] == 'i' && expression[start + 2] == 'n')
		buf_sin(start, expression, buffer);
	else if(expression[start] == 'c' &&  expression[start + 1] == 'o' && expression[start + 2] == 's')
		buf_cos(start, expression, buffer);
	else if(expression[start] == 'a' &&  expression[start + 1] == 'b' && expression[start + 2] == 's')
		buf_abs(start, expression, buffer);
	else if(expression[start] == 'l' &&  expression[start + 1] == 'o' && expression[start + 2] == 'g')
		buf_log(start, expression, buffer);
	else if(expression[start] == 'p' &&  expression[start + 1] == 'o' && expression[start + 2] == 'w')
		buf_pow(start, expression, buffer);
	else
	{
        cout<<"ERROR! You input unknown operation!"<<endl;
        isOK = false;
    }
}

//----------------------------------------------------------------------------------

void Calc::oper_mult(int &start, char expression[], stack <double> & buffer)	// multiplication
{
	if(buffer.size() == 0)
    {
        isOK = false;
        cout<<"Error! Amount of operands less than amount of operations"<<endl;
    }
	else
	{
		double arg1 = buffer.top();
		buffer.pop();
		if(buffer.size() == 0)
        {
           isOK = false;
           cout<<"Error! Amount of operands less than amount of operations"<<endl;
        }
		else
		{
			double arg2 = buffer.top();
			buffer.pop();
			double result = arg2 * arg1;
			buffer.push(result);
			for(int i = 0; i < 3; i++)
		    	expression[start] = ' ';
		}
	}
}

void Calc::oper_div(int &start, char expression[], stack <double> & buffer)		// division
{
	if(buffer.size() == 0)
    {
        isOK = false;
        cout<<"Error! Amount of operands less than amount of operations"<<endl;
    }
	else
	{
		double arg1 = buffer.top();
		buffer.pop();
		if(buffer.size() == 0)
        {
            isOK = false;
            cout<<"Error! Amount of operands less than amount of operations"<<endl;
        }
		else
		{
            if(arg1 == 0)
            {
                isOK = false;
                cout<<"Error! You can't devide by 0"<<endl;
            }
            else
            {
		    	double arg2 = buffer.top();
		    	buffer.pop();
		    	double result = arg2 / arg1;
		    	buffer.push(result);
		    	for(int i = 0; i < 3; i++)
		        	expression[start] = ' ';
            }
		}
	}
}

void Calc::oper_addit(int &start, char expression[], stack <double> & buffer)	// addition
{
	if(buffer.size() == 0)
    {
        isOK = false;
        cout<<"Error! Amount of operants less than amount of operations"<<endl;
    }
	else
	{
		double arg1 = buffer.top();
		buffer.pop();
		if(buffer.size() == 0)
        {
            isOK = false;
            cout<<"Error! Amount of operants less than amount of operations"<<endl;
        }
		else
		{
			double arg2 = buffer.top();
			buffer.pop();
			double result = arg2 + arg1;
			buffer.push(result);
			for(int i = 0; i < 3; i++)
			    expression[start] = ' ';
		}
	}
}

void Calc::oper_subtr(int &start, char expression[], stack <double> & buffer)	// subtraction
{
	if(buffer.size() == 0)
    {
        isOK = false;
        cout<<"Error! Amount of operants less than amount of operations"<<endl;
    }
	else
	{
		double arg1 = buffer.top();
		buffer.pop();
		if(buffer.size() == 0)
        {
            isOK = false;
            cout<<"Error! Amount of operants less than amount of operations"<<endl;
        }
		else
		{
			double arg2 = buffer.top();
			buffer.pop();
			double result = arg2 - arg1;
			buffer.push(result);
			for(int i = 0; i < 3; i++)
		    	expression[start] = ' ';
		}
	}
}

void Calc::realizeOperators(int &start, char expression[], stack <double> & buffer)
{
	if(expression[start] == '*')
		oper_mult(start, expression, buffer);
	else if(expression[start] == '/')
		oper_div(start, expression, buffer);
	else if(expression[start] == '+')
		oper_addit(start, expression, buffer);
	else if(expression[start] == '-')
		oper_subtr(start, expression, buffer);
}

//-----------------------------------------------------------------------------------

void Calc::realiseBinOper(int start, char expression[], stack <double> & buffer)
{
    expression[start - 1] = ' ';
	if(buffer.size() == 0)
    {
        isOK = false;
        cout<<"Error! Amount of operants less than amount of operations"<<endl;
    }
	else
	{
		double result = (-1) * buffer.top();
        buffer.pop();
        buffer.push(result);
	}
}

//-----------------------------------------------------------------------------------

void Calc::use_Variable(int & start, char expression[], stack <double> & buffer)
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
    double value = searchV(n, isOK);
    if(!isOK)
    {
        cout<<"ERROR! You input indefenite variable!"<<endl;
        return;
    }
    buffer.push(value);
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
            recording_toStack(i, expression, buffer);
        else if((expression[i] == 's' || expression[i] == 'c' || expression[i] == 'a' || expression[i] == 'l' || expression[i] == 'p') && isalpha(expression[i + 1]))
			realizeFunctions(i, expression, buffer);
        else if(isalpha(expression[i]))
            use_Variable(i, expression, buffer);
        else if(expression[i] == '*' || expression[i] == '+' || expression[i] == '-' || expression[i] == '/')
			realizeOperators(i, expression, buffer);
		else if(expression[i] == '_')
			realiseBinOper(i + 1, expression, buffer);
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

//-----------------------------------------------------------------------------------

void Calc::writeF_toStack(int &start, char expressionConv[], char expression[], stack <char> & operands)  		// input functions to stack
{
	if(expressionConv[start] == 's' &&  expressionConv[start + 1] == 'q' && expressionConv[start + 2] == 'r' && expressionConv[start + 3] == 't')
	{
		operands.push('S');
		start += 3;
	}
	else if(expressionConv[start] == 's' &&  expressionConv[start + 1] == 'i' && expressionConv[start + 2] == 'n')
		operands.push('s');
	else if(expressionConv[start] == 'c' &&  expressionConv[start + 1] == 'o' && expressionConv[start + 2] == 's')
		operands.push('c');
	else if(expressionConv[start] == 'a' &&  expressionConv[start + 1] == 'b' && expressionConv[start + 2] == 's')
		operands.push('a');
	else if(expressionConv[start] == 'l' &&  expressionConv[start + 1] == 'o' && expressionConv[start + 2] == 'g')
		operands.push('l');
	else if(expressionConv[start] == 'p' &&  expressionConv[start + 1] == 'o' && expressionConv[start + 2] == 'w')
		operands.push('p');
	else
	{
        cout<<"ERROR! You input unknown operation!"<<endl;
        isOK = false;
    }
	start += 2;
}

void Calc::writeF_toExpression(char expressionConv[], char expression[], stack <char> & operands)
{
	if(operands.top() == 'S')
	{
		expression[point] = 's';
		expression[++point] = 'q';
		expression[++point] = 'r';
		expression[++point] = 't';
		point++;
		operands.pop();
	}
	else if(operands.top() == 's')
	{
		expression[point] = 's';
		expression[++point] = 'i';
		expression[++point] = 'n';
		point++;
		operands.pop();
	}
	else if(operands.top() == 'c')
	{
		expression[point] = 'c';
		expression[++point] = 'o';
		expression[++point] = 's';
		point++;
        operands.pop();
	}
	else if(operands.top() == 'l')
	{
		expression[point] = 'l';
		expression[++point] = 'o';
		expression[++point] = 'g';
		point++;
		operands.pop();
	}
	else if(operands.top() == 's')
	{
		expression[point] = 'p';
		expression[++point] = 'o';
		expression[++point] = 'w';
		point++;
		operands.pop();
	}
	else if(operands.top() == 'a')
	{
		expression[point] = 'a';
		expression[++point] = 'b';
		expression[++point] = 's';
		operands.pop();
		point++;
	}
	else if(operands.top() == 'p')
	{
		expression[point] = 'p';
		expression[++point] = 'o';
		expression[++point] = 'w';
		operands.pop();
		point++;
	}
}

//---------------------------------------

void Calc::inputNumbers(int &start, char expressionConv[], char expression[], stack <char> & operands)
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
    expression[point] = ' ';
    point++;
    start--;
}

//---------------------------------------

void Calc::writeOpFirst_toStack(int &start, char expressionConv[], char expression[], stack <char> & operands)        //what we do with '*' and '/'
{
    if(operands.size() != 0 && (operands.top() == '*' || operands.top() == '/'))
    {
        expression[point++] = operands.top();
        operands.pop();
    }
    operands.push(expressionConv[start]);
}

void Calc::writeOpSecond_toStack(int &start, char expressionConv[], char expression[], stack <char> & operands)        //what we do with '+' and '-'
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
        if(operands.size() != 0 && (operands.top() == '*' || operands.top() == '/'))
        {
            char * op = new char [1000];
            int i;
            for(i = 1; ; i++)
            {
                if(operands.size() != 0 && (operands.top() == '*' || operands.top() == '/'))
                {
                    op[i] = operands.top();
                    operands.pop();
                }
                if((operands.size() && (operands.top() == '+' || operands.top() == '-')) || (!operands.size() || operands.top() == '('))
                {
                    if(!operands.size() || operands.top() == '(')
                        op[0] = ' ';
                    else
                    {
                        op[0] = operands.top();
                        operands.pop();
                    }
                    for(int k = i; k >= 0; k--)
                        expression[point++] = op[k];
                    break;

                }
            }
            delete [] op;
        }
        operands.push(expressionConv[start]);
    }
}

//---------------------------------------

void Calc::writeCloseBrecket(int &start, char expressionConv[], char expression[], stack <char> & operands)
{
    if(operands.top() == '(')
    {
        operands.pop();
        if(isalpha(operands.top()))
            writeF_toExpression(expressionConv, expression, operands);
    }
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
            inputNumbers(i, expressionConv, expression, operands);
        else if((expressionConv[i] == 's' || expressionConv[i] == 'c' || expressionConv[i] == 'a' || expressionConv[i] == 'l' || expressionConv[i] == 'p') && isalpha(expressionConv[i + 1]))
            writeF_toStack(i, expressionConv, expression, operands);
        else if(isalpha(expressionConv[i]))
        {
            expression[point++] = expressionConv[i];
            if(!isalpha(expressionConv[i + 1]))
                expression[point++] = ' ';
        }
        else if(expressionConv[i] == '*' || expressionConv[i] == '/')
            writeOpFirst_toStack(i, expressionConv, expression, operands);
        else if(expressionConv[i] == '+' || expressionConv[i] == '-')
		    writeOpSecond_toStack(i, expressionConv, expression, operands);
        else if(expressionConv[i] == '(')
        {
            operands.push('(');
            OpenedBrackets++;
        }
        else if(expressionConv[i] == ')')
        {
            if(OpenedBrackets != 0)
            {
                writeCloseBrecket(i, expressionConv, expression, operands);
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
        if(isalpha(operands.top()))
            writeF_toExpression(expressionConv, expression, operands);
        else
        {
            expression[point++] = operands.top();
            if(operands.top() == '(')
                isOK = false;
            operands.pop();
        }
    }
    expression[point++] = '\0';
    if(isOK)
        isOK = reading(expression);
    else
        cout<<"ERROR! You input wrong expression! You put brackets incorrectly"<<endl;
    return isOK;
}

double Calc::result(char expressionConv[])
{
    isOK = reformation(expressionConv);
    double result = 0;
    if(isOK && buffer.size())
    {
        result = buffer.top();
        buffer.pop();
    }
    while(buffer.size())
        buffer.pop();
    while(operands.size())
        operands.pop();
    destruct();
    return result;
}
