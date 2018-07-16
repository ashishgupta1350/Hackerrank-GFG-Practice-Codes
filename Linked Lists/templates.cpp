#include<iostream>
using namespace std;
template<typename T>
class data{
	T x;
	T y;
public:
	data(T x,T y)
	{
		this->x=x;
		this->y=y;
	}
	void printData()
	{
		cout<<"x is : "<<x<<" and y is : "<<y<<endl;
	}
};
int main()
{
	data<double> d(10.1,20.2);
	d.printData();
	return 0;
}