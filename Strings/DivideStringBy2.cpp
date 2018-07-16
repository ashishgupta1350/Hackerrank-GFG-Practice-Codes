#include<iostream>
#include<bits/stdc++.h> // competitive purpose, though not recommended. 16 / 7 / 18
using namespace std;

string divideStringBy2(string s)
{
	if(s=="1") return "0"; // corner case 
	int carry=0;
	string dividedString="";
	for(unsigned int i=0;i<s.length();i++)
	{
		char ch=s[i];
		int num=ch-'0';
		num=carry*10+num;
		if(num % 2 ==0) carry=0;
		else carry=1;
		num/=2;
		dividedString+=char('0'+num);

	}
	if(dividedString[0]=='0') return dividedString.substr(1); // means if the original string had a 1 ("123" in it --- > "061" ---- > "61")
	else return dividedString;
}

bool getBinary(string s)
{
	string bin="";
	int count1=0;// if the count1 is > 3 return false // part of competitive programming contest
	while(s!="1")
	{
		int n=s.length();
		if((s[n-1]-'0' ) % 2 == 0)
		{
			bin+='0';
		}
		else{
			bin+='1';
			count1+=1;
			if(count1>=3) return false; // why because the 1 will be at the last too. equal to sign is important.

		}
		s=divideStringBy2(s);
	}

	return true;

}

string add1ToString(string s)
{

}

int main()
{
	string s="14";
	bool ans=getBinary(s);
	cout<<ans<<endl;
	return 0;
}