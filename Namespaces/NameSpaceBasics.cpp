#include<iostream>
using namespace std;

namespace mine{
	class c{
	public: 
		void fun();
	};
	class myClass;
}
void mine::c::fun()
{
	cout<<"its good to be in class c and namespace mine"<<endl;
}
//create a class?

 class mine::myClass
{
public:
	myClass();
	void show();
};
mine::myClass::myClass()
{
	cout<<"Yo, I am a new class in mine"<<endl;
}
void mine::myClass::show()
{
	cout<<"show called in class myClass of mine namespace"<<endl;
}
int main()
{
	// not using  --- > using keyword
	mine::myClass b;
	b.show();
	return 0;
}
