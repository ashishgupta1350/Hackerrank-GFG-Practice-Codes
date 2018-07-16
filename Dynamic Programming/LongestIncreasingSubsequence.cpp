#include<iostream>
using namespace std;
#include<climits>
#define LL long long int
int lis(int *arr,int s,int e,int lastVal=INT_MIN)
{
	if(s>e)
	{
		return 0;
	}
	int lisLeft=lis(arr,s+1,e,lastVal);
	int lisRight=0;
	if(lastVal<arr[s])
	{
		lisRight=1+lis(arr,s+1,e,arr[s]);
		return max(lisLeft,lisRight);
	}
	else return lisLeft;
}

int lcs(string a,string b,unsigned int s1=0,unsigned int s2=0)
{
	if(s1==a.length() || s2==b.length())
	{
		return 0; // this means that one of the strings is empty and thus longest common is trivially 0;
	}
	if(a[s1]==b[s2])
	{
		return 1+lcs(a,b,s1+1,s2+1);
	}
	else
		return max(lcs(a,b,s1+1,s2),lcs(a,b,s1,s2+1));
}


LL maxSumIncreasingSubsequence(LL *arr,LL n,int lastVal=INT_MIN)
{
	if(n<=0) return 0; // means max sum is 0, no element what so ever
	LL maxSumLeft=maxSumIncreasingSubsequence(arr+1,n-1,lastVal);
	LL maxSumRight=0;
	if(arr[0]>lastVal)
	{
		maxSumRight=arr[0]+maxSumIncreasingSubsequence(arr+1,n-1,arr[0]);
		return max(maxSumLeft,maxSumRight);
	}
	else return maxSumLeft;

}

int main()
{
	// int *arr=new int [5];
	LL *arr=new LL [8];

	arr[0]=8;
	arr[1]=7;
	arr[2]=6;
	arr[3]=5;
	arr[4]=4;
	arr[5]=3;
	arr[6]=2;
	arr[7]=1;
	for(int i=0;i<5;i++)
	{
		swap(arr[i],arr[7-i]);
	}
	cout<<"Array is : ";
	for(int i=0;i<=7;i++)
	{
		cout<<arr[i]<<" ";
	}
	// cout<<endl;
	// cout<<lis(arr,0,7)<<endl;
	// cout<<endl<<"Length of Longest common substring in ADBDCA and ABABDB is : "<<lcs("ADBDCA","ABABDB")<<endl; // functional code, do not delete
	cout<<endl<<"MaxSum of the array is : "<<maxSumIncreasingSubsequence(arr,7)<<endl;

}