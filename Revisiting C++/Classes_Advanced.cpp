#include<iostream>
using namespace std;
#include<string>

class Fraction{
	public:

	int a=1;
	int b=2;
	// static int fraction_count; // how do I initialize it?

public:
	// we don't need constructor now;
	
	void setA(int a)const{
		//this->a=a;
		return;
	}
};

class fraction
{
public:
	int den=1;
	int num=1;
	fraction(int num,int den){
		this->num=num;
		this->den=den;

	}

	fraction add(fraction const &f2) const{
		
		int n1=this->num;
		int n2=f2.num;
		int d1=this->den;
		int d2=f2.den;
		int numerator=(n1*d2+n2*d1);
		int denominator=(d1+d2);
		fraction *f3=new fraction(numerator,denominator);
		return *f3;//fraction. Smart way of returning
	}

	fraction* operator+(fraction const &f2)  const{

		int n1=this->num;
		int n2=f2.num;
		int d1=this->den;
		int d2=f2.den;
		int numerator=(n1*d2+n2*d1);
		int denominator=(d1+d2);
		fraction *f3=new fraction(numerator,denominator);
		return f3;// to return the fraction. Smart way of returning
	}
	fraction* operator*(fraction const &f2) const{
		int n1=this->num;
		int n2=f2.num;
		int d1=this->den;
		int d2=f2.den;
		int numerator=(n1*n2);
		int denominator=(d1*d2);
		fraction *f3=new fraction(numerator,denominator);
		return f3;// to return the fraction. Smart way of returning

	}
	fraction operator++(){

		this->num+=this->den;
		return *this;

	}


};

int main()
{
	
	fraction  f1(1,2);
	fraction  f2(1,2);
	fraction* f3=f1+f2;
	// cout<<f3->num <<endl;// this is memory efficient.
	// f3=f1*f2;
	// cout<<f3->num;
	fraction f4=*f3;
	cout<<"operator ++ "<<endl;
	f4=++f4;
	f4=f4 ++;
	cout<<f4.num<<endl;

	return 0;
}