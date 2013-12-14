#include <iostream>

using namespace std;

template <class type1> 
class Complex
{
	type1 re;
	type1 im;

public:
	Complex();
	Complex(type1 r, type1 i);
	Complex(type1 r);
	Complex(Complex &c);
	~Complex();
	Complex operator+(Complex &c);
	Complex operator-(Complex &c);
	Complex operator*(Complex &c);
	void show();
};

template <class type1> 
Complex <type1> :: Complex()
{
	re = 0;
	im = 0;
}

template <class type1> 
Complex <type1> :: Complex(type1 r, type1 i)
{
	re = r;
	im = i;
}

template <class type1> 
Complex <type1> :: Complex(type1 i)
{
	re = 0;
	im = i;
}

template <class type1> 
Complex <type1> :: ~Complex()
{

}

template <class type1> 
Complex <type1> :: Complex(Complex &c)
{
      re = c.re; 
      im = c.im;
}

template <class type1> 
Complex <type1> Complex <type1> :: operator+(Complex &c)
{
	Complex temp;
	temp.re = re + c.re;
	temp.im = im + c.im;
	return temp;
}

template <class type1> 
Complex <type1> Complex <type1> :: operator-(Complex &c)
{
	Complex temp;
	temp.re = re - c.re;
	temp.im = im - c.im;
	return temp;
}

template <class type1> 
Complex <type1> Complex <type1> :: operator*(Complex &c)
{
	Complex temp;
	temp.re = re * c.re - im * c.im;
	temp.im = re * c.im + im * c.re;
	return temp;
}
