#include<iostream>
using namespace std;
#include<string>

class st{
public:
	int age;
	const int rollNo;
	 st(int r, int a):rollNo(r),age(a){

	 }
	 // versus

};
/*
class st1{
public:
	int age;
	const int rollNo;
	 Student(int r, int a){
	 	this->age=age;
	 	this->rollNo=rollNo;
	 }
	 // versus
	 
};*/

class student{
public:
	string name;
	int rollNo;
	int age;
	string address;
	long long int contactNo;
private:
	// Account Details
	int account_number;
	int account_type;
	bool fees_pending;
	int lib_dues;

public:
	 student(string name, int rollNo,int age=20,string address="not Yet Given",int contactNo=0){
		// Now how do I address them???
		this->name=name;
		this->rollNo=rollNo;
		this->age=age;
		this->address=address;
		this->contactNo=contactNo;
		this->fees_pending=0;

	}
	// we dont need many functions.

	bool check_pending_fees(){
		return fees_pending==true?true:false;
	}
	bool verifyAccount(int acc_no){
		if (student::account_number==acc_no){
			return true;
		}
		else return false;
}
   	~ student(){
	cout<<"destructor is called"<<endl;
}

};




int main()
{
	student *s=new student("Ashish",23);
	delete s;
	st* s1=new st(26,2);
	return 0;
}