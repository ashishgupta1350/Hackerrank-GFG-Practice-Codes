#include<iostream>
using namespace std;
#include<climits>
int lis(int *arr,int s,int e,int lastVal=INT_MIN)
{
	if(s>e)
	{
		return 0;
	}
	int lisLeft=lis(arr,s+1,e);
	int lisRight=0;
	if(lastVal<arr[s])
	{
		lisRight=1+lis(arr,s+1,e,arr[s]);
		return max(lisLeft,lisRight);
	}
	else return lisLeft;
}
int main()
{
	int *arr=new int [5];
	arr[0]=1;
	arr[1]=6;
	arr[2]=3;
	arr[3]=5;
	arr[4]=9;
	cout<<lis(arr,0,4)<<endl;

}