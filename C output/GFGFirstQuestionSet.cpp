// #include<iostream>
// using namespace std;
// #include<vector>
// #include<string>
// string encoder(string s)
// {
// 	int d[26];// dictionary of size 26
// 	for(int i=0;i<26;i++)
// 		d[i]=0; // initialize with zero, alternately use memset.
// 	unsigned int i=0;
// 	while(i<s.length())
// 	{
// 		d[s[i]-'a']+=1;
// 		i+=2;// taking the even part of the string
// 	}
// 	string encoded_even;
// 	for(int i=0;i<26;i++)
// 	{
// 		char ch=d[i]+'0';
// 		encoded_even+=ch;
// 	}
// 	for(int i=0;i<26;i++)
// 		d[i]=0;  // reuse the d
// 	i=1;
// 	while(i<s.length())
// 	{
// 		d[s[i]-'a']+=1;
// 		i+=2;// taking the odd part of the string
// 	}
// 	string encoded_odd;
// 	for(int i=0;i<26;i++)
// 	{
// 		char ch=d[i]+'0';
// 		encoded_odd+=ch;
// 	}
// 	return encoded_odd + '%' + encoded_even + '\0'; // merge them using a seperator. Return the string. 

// }
// #include<map>
// map<string,bool> getDistinct(vector<string> strings)
// {
// 	map<string, bool> myMap;
// 	for(unsigned int i=0;i<strings.size();i++)
// 	{
// 		myMap[encoder(strings[i])]=true;
// 	}
// 	return myMap;
	
// }
// int main()
// {
// 	// simple driver code , takes in orignals, compute map of encoded string and returns a map.
// 	// we just encode each input string and check if the encoded string matches anyone in the map.
// 	vector<string> originals;
// 	int n;
// 	cin>>n;
// 	for(int i=0;i<n;i++)
// 	{
// 		string s;
// 		cin>>s;
// 		originals.push_back(s);
// 	}
// 	map<string,bool>resultMap=getDistinct(originals);
// 	int k;
// 	cin >> k;
// 	for(int i=0;i<k;i++)
// 	{
// 		string s;
// 		cin>>s;
// 		s=encoder(s);
// 		if(resultMap.find(s)!=resultMap.end())
// 		{
// 			cout<<1<<endl;
// 		}
// 		else cout<<0<<endl;
// 	}

// 	return 0;
// }


// An efficient solution generate an encoded string for every input string. The encoded has counts of even and odd positioned characters separated by a separator. Two strings are considered sameish if their encoded strings are same else not. Once we have a way to encode string, the problem reduces to checking the distinct encoded strings. This is a typical problem of hashing. We create hash set and one by one store encodings of strings. If an encoding already exists, we ignore string and print 0. Else we print 1. 

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
map<string,bool> getDistinct(vector<string> strings)
{
	map<string, bool> myMap;
	for(unsigned int i=0;i<strings.size();i++)
	{
		myMap[encoder(strings[i])]=true;
	}
	return myMap;
	
}
int main()
{
	// simple driver code , takes in orignals, compute map of encoded string and returns a map.
	// we just encode each input string and check if the encoded string matches anyone in the map.
	vector<string> originals;
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		string s;
		cin>>s;
		originals.push_back(s);
	}
	map<string,bool>resultMap=getDistinct(originals);
	int k;
	cin >> k;
	for(int i=0;i<k;i++)
	{
		string s;
		cin>>s;
		s=encoder(s);
		if(resultMap.find(s)!=resultMap.end())
		{
			cout<<1<<endl;
		}
		else cout<<0<<endl;
	}

	return 0;
}