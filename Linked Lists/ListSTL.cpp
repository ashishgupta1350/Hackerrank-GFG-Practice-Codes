#include<iostream>
using namespace std;
#include<list>
#include<forward_list>

void printList(list<int> l1)
{
	for(auto it=l1.begin();it!=l1.end();it++)
	{
		cout<<*it<<" ";
	}
	cout<<endl;
}

int main()
{
	list<int> l1;
	l1.push_back(1);
	l1.push_back(2);
	l1.push_back(3);
	l1.push_back(100);
	l1.push_back(100);
	l1.push_back(100);
	l1.push_back(100);

	l1.push_front(-1);
	cout<<l1.empty()<<endl;
	cout<<l1.front()<<endl;
	cout<<l1.back()<<endl;
	for(auto it=l1.begin();it!=l1.end();it++)
	{
		cout<<*it<<" ";
	}
	cout<<endl;
	// cout<<l1.erase(l1.2))<<endl;
	l1.reverse();
	l1.sort();
	l1.remove(3);
	printList(l1);
	l1.unique();
	printList(l1);
	list<int>*li=new list<int>;
	li->push_back(1);
	li->push_back(1);
	li->push_back(1);
	li->push_back(1);
	cout<<(li[1]);


}