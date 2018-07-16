#include<iostream>
using namespace std;
#include<vector>
#include<string>
string encoder(string s)
{
	int d[26];// dictionary of size 26
	for(int i=0;i<26;i++)
		d[i]=0; // initialize with zero, alternately use memset.
	unsigned int i=0;
	while(i<s.length())
	{
		d[s[i]-'a']+=1;
		i+=2;// taking the even part of the string
	}
	string encoded_even;
	for(int i=0;i<26;i++)
	{
		char ch=d[i]+'0';
		encoded_even+=ch;
	}
	for(int i=0;i<26;i++)
		d[i]=0;  // reuse the d
	i=1;
	while(i<s.length())
	{
		d[s[i]-'a']+=1;
		i+=2;// taking the odd part of the string
	}
	string encoded_odd;
	for(int i=0;i<26;i++)
	{
		char ch=d[i]+'0';
		encoded_odd+=ch;
	}
	return encoded_odd + '%' + encoded_even + '\0'; // merge them using a seperator. Return the string. 

}
#include<map>
int getDistinct(vector<string> strings)
{
	map<string, bool> myMap;
	for(unsigned int i=0;i<strings.size();i++)
	{
		myMap[encoder(strings[i])]=true;
	}
	return myMap.size();
	
}
int main()
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		vector<string> v;
		int n;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			string s;
			cin>>s;
			v.push_back(s);
		}
		cout<<getDistinct(v)<<endl;
	}


	return 0;
}