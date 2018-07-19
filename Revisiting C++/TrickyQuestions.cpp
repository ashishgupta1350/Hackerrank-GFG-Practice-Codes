// #include<iostream>

// using namespace std;

// int main()
// {
// 	int a = 10, b = 20;
// 	long int c;
	
// 	c = a *long int(b);
// 	cout << c;
	
// 	return 0;	
// }
// #include<iostream>

// using namespace std;

// int main()
// {
// 	enum result {first, second, third};
// 	result a = first;
// 	// int b = a;
// 	// result c = 1;
// 	// result d = result(1);
// 	cout<<a<<endl;
// 	return 0;	
// }
// #include<iostream>
// #include<string>
// #include<cstring>// does the job
// using namespace std;

// int main()
// {
// 	char t[] = "String functions are simple";
// 	int l = strlen(t);
// 	cout <<l;
// 	return 0;	
// }

// #include<iostream>

// using namespace std;

// int main()
// {
// 	char *p = "Internet";
// 	char * &q=p;
// 	cout << p << endl << q << endl;
// 	q = "Intranet";
// 	cout << p << endl << q << endl;
// 	return 0;
// }
// #include<iostream>
// using namespace std;

// struct employee{
// 	char name[20];
// 	int age;
// }e;

// int main()
// {
// 	employee *p;
// 	p = (employee*)malloc(sizeof(e));
// 	float q;
// 	int a, b;
// 	q = (float)a/b;

// 	employee *p1=new employee();

// }

#include<iostream>
using namespace std;
void f(int a);
void f(const int a);
int main()
{
	int a=10;
	const int b=10;
	f(a);
	f(b);

	return 0;
}
void f(int a)
{
	cout<<"int a"<<endl;
}
void f(const int a)
{
	cout<<"const int a"<<endl;
}