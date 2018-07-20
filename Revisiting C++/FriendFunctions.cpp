#include<iostream>
using namespace std;
class Complex1;
class Complex{
	int a;int b;
public:
	void setData(int a,int b)
	{
		this->a=a;this->b=b;
	}
	void printData()
	{
		cout<<"a : "<<a<<" and b : "<<b<<endl;
	}
	friend ostream& operator<<(ostream&,Complex c);
	friend void fun(Complex,Complex1);

};

class Complex1{
	int c;int d;
	public:
	void setData(int a,int b)
	{
		this->c=a;this->d=b;
	}
	void printData()
	{
		cout<<"c : "<<c<<" and d : "<<d<<endl;
	}
	friend ostream& operator<<(ostream&,Complex1 c);
	friend void fun(Complex,Complex1);

};
void fun(Complex c,Complex1 c1)
{
	cout<<"Private Data members of both classes are : "<<c.a<<" "<<c.b<<" "<<c1.c<<" "<<c1.d;
}

ostream&operator <<(ostream& cout,Complex1 c)
{
	cout<<c.c<<" "<<c.d<<endl;
	return cout;
}


ostream&operator <<(ostream& cout,Complex c)
{
	cout<<c.a<<" "<<c.b<<endl;
	return cout;
}
// istream& operator >>(isream& cin,Complex c)
// {
// 	cin>>c.a>>c.b;
// 	return cin;
// }



int main()
{
	Complex c;
	c.setData(1,2);
	cout<<c; // overload operator <<

}