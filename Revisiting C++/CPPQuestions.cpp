

// #include<iostream>
// using namespace std;
// class user
// {
// 	private:
// 		int i;
// 		float f;
// 		char c;
// 	public:
// 		void displaydata()
// 		{
// 			cout << endl << i << '\n' << f << "\n" << c;
// 		}
// };
// int main()
// {
// 	cout << sizeof(user);
// 	user u1;
// 	cout << endl << sizeof(u1);
// 	u1.displaydata();
// 	return 0;
// }

// #include<iostream>
// using namespace std;

// int top = 3;

// class base 
// {
// protected:
// 	int top;
// public:
// 	base()
// 	{
// 		top = 2;
// 		cout << endl << top;
// 	}
// };

// class derived : public base
// {
// private:
// 	int top;
// public:
// 	derived(): base()
// 	{
// 		top = 1;
// 		cout << endl << top;
// 		cout << endl << base::top;
// 		cout << endl << ::top;
// 	}
// };

// int main()
// {
// 	derived d1;
// 	return 0;
// }
// #include<iostream>

// using namespace std;

// class base 
// {
// private:
// 	int i;
// };

// class base2 
// {
// private:
// 	int j;
// };
// class base3 : public base,public base2
// {
// private:
// 	int k;
// public:
// 	base3()
// 	{
// 		// i=2; // this is invalid statement in this context;
// 	}
// };
// int main()
// {
// 	cout<<endl<<sizeof(base)<<" "<<sizeof(base2)<<" "<<sizeof(base3)<<endl;
// 	return 0;
// }
// #include<iostream>

// using namespace std;

// class base 
// {
// protected:
// 	int i;
// public:
// 	base()
// 	{
// 		cout<<"In base: ";
// 		cout << endl << &i;
// 	}
// };

// class derived : public base
// {
// public:
// 	derived() 
// 	{
// 		cout<<"In derived: ";

// 		cout << endl << &i;
// 	}
// };

// int main()
// {
// 	derived d1;
// 	base b1;
// 	return 0;
// }

// #include<iostream>
// using namespace std;

// class base 
// {
// protected:
// 	int i;
// public:
// 	void funct()
// 	{
// 		cout << endl << &i;
// 	}
// };

// class derived : public base
// {
// public:
// 	derived()
// 	{
// 		cout << endl << &i;
// 		funct();
// 	}
// };

// int main()
// {
// 	derived d1;
// 	return 0;
// }

// #include<iostream>
// using namespace std;

// int top = 3;

// class base 
// {
// protected:
// 	int top;
// public:
// 	base()
// 	{
// 		top = 2;
// 		cout << endl << top;
// 	}
// };

// class derived : public base
// {
// private:
// 	int top;
// public:
// 	derived(): base()
// 	{
// 		top = 1;
// 		cout << endl << top;
// 		cout << endl << base::top;
// 		cout << endl << ::top;
// 	}
// };

// int main()
// {
// 	derived d1;
// 	return 0;
// }

// #include<iostream>
// using namespace std;

// class index
// {
// protected:
// 	int count;

// public:
// 	index()
// 	{
// 		count = 0;
// 	}
// 	void operator++()
// 	{
// 		count++;
// 	}
// 	void display()
// 	{
// 		cout << endl << count;
// 	}
// };

// int main()
// {
// 	index c;
// 	++c;
// 	c.display();
// 	++c;
// 	c.display();
// 	return 0;
// }


#include<iostream>
using namespace std;
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
	friend
};
int main()
{
	Complex c;
	c.setData(1,2);
	cout<<c; // overload operator <<

}