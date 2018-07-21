#include<iostream>
using namespace std;
// BASE class has 2 subclasses derived1 and derived2, which has further 1 class derived 3. If i want base -> data, or base functions, it creates a ambiguity, which function should I use??
// see here why

class base{
protected:
	int data;
public:
	//nothing right now
	virtual void fun()
	{
		cout<<"base function"<<endl;
	}
	virtual ~base()
	{
		// necessary!	
	}
};
class derived1:virtual public base{ // use virtual
protected:
	int data1;
public:
	


};
class derived2: virtual public base{
protected:
	int data2;
public:

};
class derived3:public derived1, public derived2{
	public:
		getData()
		{
			cout<<"base data is : "<<data<<endl;
		}
};
// which base data should I have? Derived 1 or Derived 2?/?
// Compiler shows error

int main()
{
	derived3 d;
	d.getData();
	return 0;
}