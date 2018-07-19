#include<iostream>
using namespace std;
#include<string>
struct emp{
	string name;
	int age;
	float sal;
}; 

emp emp1={"Ashish",20,2000000};
emp emp2={"Divyansh",20,230000};
emp &fun();

int foo()
{
	int a=10;
	return a;

}

int main()
{
	fun()=emp2;
	cout<<emp1.name<<" "<<emp1.age<<" "<<emp1.sal<<endl;
	int b;
	b=foo();
	cout<<b<<endl;
	// return 0;

	string *s=new string("This is maa town!");
	string * &s1=s;
	cout<<*s1<<endl;
	*s1="Dont touch maa town!";
	cout<<*s1<<endl;
	*s="You touched maa town, now you are done!";
	cout<<*s<<endl;

}

emp &fun()
{
	cout<<emp1.name<<" "<<emp1.age<<" "<<emp1.sal<<endl;
	return emp1;
}