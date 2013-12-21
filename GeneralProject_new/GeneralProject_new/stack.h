#include <iostream>

using namespace std;

template<class T> class Stack
{
private:
	int size;
	int hit;
	T * Pointer;

public:
	~Stack();
	void push(T);
	T pop();
	T top();
	int Size();
	bool isEmpty();
};

template<class T> Stack<T>::~Stack() 
{
	delete [] Pointer;
}
 
template<class T> void Stack<T>::push(T value)
{
    if (size == hit)  
    {
        T * Temp = new T [size *2];
        for (int i = 0; i < size; i++)
            Temp[i] = Pointer[i];
        delete [] Pointer;
        Pointer = Temp;
        size *= 2;	
    }
	Pointer[hit++] = value;    
}

template<class T> T Stack<T>::pop()
{
    if (hit == 0) 
        return 0;
    if (size / 4 >= hit)
    {
        T *Temp = new T [size / 2];
        for (int i = 0; i < size; i++)
            Temp[i] = Pointer[i];
        delete [] Pointer;
        Pointer = Temp;
        size /= 2;
    }
    return Pointer[--hit];
}

template<class T> T Stack<T>::top()
{
	 if (!isEmpty())
          return Pointer[hit - 1];
	 return 0;
}

template<class T> int Stack<T>::Size()
{
	return hit;
}

template<class T> bool Stack<T>::isEmpty()
{
	return hit == 0;
}