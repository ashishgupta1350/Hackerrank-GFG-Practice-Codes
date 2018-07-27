#include<bits/stdc++.h>
using namespace std;


int gcd1(int a,int b)
{
	if(a==1 or b==1) return 1;
	else if(a<0 or b<0) return -1;
	if(a==b) return a;
	if(a>b) return gcd1(a-b,b);
	else return gcd1(a,b-a);
}

int gcd(int *arr, int n)
{
	int ans=arr[0];
	for(int i=0;i<n;i++)
	{
		// int j=i+1;
		ans=gcd1(ans,arr[i]);
	}
	return ans;



}

int main()
{
	int arr[]={5,10,15};
	int size=3;
	cout<<gcd(arr,size);
	cout<<endl;



	return 0;
}