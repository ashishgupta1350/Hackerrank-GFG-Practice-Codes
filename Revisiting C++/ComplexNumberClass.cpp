#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class Complex{
public:
	double real;
	double img;
	Complex(double real=0,double img=0)
	{
		this->real=real;this->img=img;
	}
	Complex add (Complex c2);
	Complex subtract(Complex c2);
	// complex operator + (complex c2);
	// complex operator - (complex c2);
	void printComplex();

};
Complex Complex:: add (Complex c2)
{
		Complex c3;
		c3.real=this->real+c2.real;
		c3.img=this->img+c2.img;
		return c3;
}
Complex Complex:: subtract(Complex c2)
{
		Complex c3;
		c3.real=this->real-c2.real;
		c3.img=this->img-c2.img;
		return c3;
}
void Complex:: printComplex()
{
	cout<<this->real<<" +i "<<this->img<<endl;
}
 Complex operator + (Complex c1,Complex c2)
{
	Complex c3;
		c3.real=c1.real+c2.real;
		c3.img=c1.img+c2.img;
		return c3;
}
Complex operator - (Complex c1,Complex c2)
{
	Complex c3;
		c3.real=c1.real-c2.real;
		c3.img=c1.img-c2.img;
		return c3;
}

int main()
{
	Complex c1(1,2);
	Complex c2(3,4);
	Complex c3 = c1+c2;
	c3.printComplex();
}