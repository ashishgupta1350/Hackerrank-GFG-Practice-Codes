#include<iostream>
using namespace std;

class vehicle{
public:
	vehicle()
	{
		cout<<"Vehicle's Constructor"<<endl;
	}
	virtual void insurance()
	{
		cout<<"vechicle class insurance"<<endl;
	}
	virtual void distance()
	{
		cout<<"vechicle class distance"<<endl;
	}
	 void type()
	{
		cout<<"vechicle class type"<<endl;
	}
	virtual void plate()
	{
		cout<<"vehicle plate"<<endl;
	}
};

class car: public vehicle{
public:
	void insurance()
	{
		cout<<"Car Insurance"<<endl;
	}
	void distance()
	{
		cout<<"Car distance"<<endl;
	}
	void plate()
	{
		cout<<"Car plate"<<endl;
	}
};
int main()
{
	vehicle v1;
	vehicle *v;
	car c;
	v=&c;
	v->insurance();
	v->plate();
	car c;
}
