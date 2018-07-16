#include<iostream>
using namespace std;
#include<map>
#include<string>
int main()
{
	multimap<string,char> myMap;
	// myMap["Anish"]='M';
	// myMap["Aviral"]='M';
	// myMap["Himanshu"]='M';
	// myMap["Neha"]='F';
	// myMap["Raveena"]='F';
	myMap.insert(make_pair("Aviral",'M'));
	myMap.insert(make_pair("Anish",'M'));
	myMap.insert(make_pair("Anish",'F'));
	myMap.insert(make_pair("Anish",'T'));
	myMap.insert(make_pair("Anish",'Y'));
	myMap.insert(make_pair("Anish",'N'));

	myMap.insert(make_pair("Himanshu",'M'));
	myMap.insert(make_pair("Raveena",'F'));
	myMap.insert(make_pair("Eshani",'F'));
	// auto it=myMap.find("Aviral");
	multimap<string,char> myMap2(myMap.begin(),myMap.end());
	myMap.erase("Aviral");
	// yes , this deletes aviral from my map.
	// multimap<string,char>:: iterator it;
	pair<multimap<string,char>:: iterator,multimap<string,char>:: iterator>result=myMap.equal_range("Anish");
	for(auto it=result.first;it!=result.second;it++)
	{
		cout<<it->first<<" "<<it->second<<endl;
	}
	cout<<endl<<endl;

	for(auto it=result.first;it!=result.second;it++)
	{
		cout<<it->first<<" "<<it->second<<endl;
	}

	return 0;

}