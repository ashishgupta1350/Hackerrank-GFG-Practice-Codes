#include<iostream>
using namespace std;
// #include<multi_set>
#include<set>
#include<set>
class node{
public: 
	int data;
	node*next;
	node(int data)
	{
		this->data=data;
		this->next=NULL;
	}
};

int main()
{
	set<int> s;
	for(int i=0;i<10;i++)
	{
		s.insert(10-i);
	}
	set<int> :: iterator it;
	it=s.find(6);
	if(it!=s.end())
	{
		cout<<"found";
	}
	else cout<<"not";
	cout<<endl;
	cout<<"--------------------------------"<<endl;
	node*n=new node(10);
	node*n1=new node(4);
	node*n2=new node(5);
	node*n3=new node(2);
	node*n4=new node(1);
	multiset<node*> advMS;
	advMS.insert(n);
	advMS.insert(n1);
	advMS.insert(n2);
	advMS.insert(n3);
	advMS.insert(n4);
	for(auto it=advMS.begin();it!=advMS.end();it++)
	{
		cout<<(*it)->data<<" ";
	}
	cout<<endl;
	auto it1=advMS.find(n);
	if(it1!=advMS.end())
	{
		cout<<"found"<<" ";
	}
	cout<<endl;
	multiset<int>  ms;
	for(int i=0;i<4;i++)
	{
		ms.insert(4-i);
		ms.insert(4-i);
	}
	for(auto it=ms.begin();it!=ms.end();it++)
	{
		cout<<*it<<" ";
	}
	cout<<endl;
}
