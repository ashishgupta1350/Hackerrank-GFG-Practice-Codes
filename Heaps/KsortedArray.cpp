#include<iostream>
using namespace std;
#include<queue>
#include<vector>
#include<algorithm>
void print(int *arr, int n)
{
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}
void print(vector<int> arr, int n)
{
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}

int main()
{
	priority_queue<int> pq; // to have a max pq , let me see
	/// lets have an input
	//int n=10;
	int *arr=new int[5];
	arr[0]=5;
	arr[1]=3;
	arr[2]=4;
	arr[3]=1;
	arr[4]=2;
	// array is made, just solve the question now
	//std::priority_queue<int, std::vector<int>, std::greater<int> > my_min_heap;
	int k;
	cout<<"Enter k: ";cin>>k;
	if(k>=5){
		sort(arr,arr+5);
		print(arr,5);
		return 0;
	}
	int i=0;
	for( i=0;i<k;i++)
	{
		pq.push(arr[i]);
	}
	vector<int> v;
	while(!pq.empty())
	{
		v.push_back(pq.top());
		pq.pop();
		if(i<5){
			pq.push(arr[i]);i++;
		}
	}	
	print(v,5);



}