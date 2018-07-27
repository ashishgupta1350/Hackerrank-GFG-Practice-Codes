#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void itoa1(int n, char* str,int k)
{
    if(n==0)
    {
        str[0]='0';
        str[1]='\0';return;
    }
    int i=0;
    while(n!=1)
    {
        str[i++]=char(n%2 + '0');
        n/=2;
    }
    str[i++]='1';
    str[i]='\0';
    reverse(str,str+i);
    return;
}

bool check(int n,int target)
{
	if(n==0 and target==0) return true;
	else if(n==0) return false;
	char str[10000];
	itoa(n,str,2); // this gets the binary of the number 
	int i=0;
	int count=0;
	while(str[i]!='\0')
	{
		if(str[i]=='1')
		{
			count++;
		}
		i++;
	}
	if(n+count==target) return true;
	else return false;



}
int main()
{
// 	int t;cin>>t;
// 	while(t--)
// 	{

// 	int n;
// 	cin>>n;
// 	char s[1000];
// 	itoa(n,s,2);
// 	// s has binary
// 	int k=strlen(s);
// 	int flag=0;
// 	for(int i=n-k-1;i>=0 and i<=n;i++)
// 	{
// 		if(check(i,n))
// 		{
// 			cout<<i<<endl;
// 			flag=1;
// 			break;
// 		}
// 	}
// 	if(!flag)
// 	{
// 		cout<<"Number is bleak"<<endl;
// 	}
// }
	char str[1000];
int n;cin>>n;
		itoa1(n,str,1);

cout<<str<<endl;
	return 0;
}