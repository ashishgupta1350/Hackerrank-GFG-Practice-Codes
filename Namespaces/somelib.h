
#ifndef SOMELIB_H
#define SOMELIB_H
// #include "libCode.cpp"

namespace someLib{
	void fun();
	void display();
}

void someLib:: fun()
{
	cout<<"I am in someLib, fun"<<endl;
}
void someLib:: display()
{
	cout<<"I am in someLib, display"<<endl;
}

#endif