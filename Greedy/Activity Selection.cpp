#include<iostream>
#include<vector>
using namespace std;
#include<algorithm>
// class comparitor{

// public:
// 	bool operator()pair<int,int> const &p1,pair<int,int> const &p2 const{
// 		return p1.second<p2.second;
// 	}

// };
bool comparitor(const pair<int,int> &p1, const pair<int,int> &p2)
{
	return (p1.second<p2.second);
}
int main()
{
	int n;cin>>n;
	int *st=new int [n];
	int *ft=new int [n];
	for(int i=0;i<n;i++)
	{
		cin>>st[i];
	}
	for(int i=0;i<n;i++)
	{
		cin>>ft[i];
	}
	vector<pair<int,int>>arr;//=new vector<pair<int,int>>;

	for(int i=0;i<n;i++)
	{
		pair<int,int> p(st[i],ft[i]);
		arr.push_back(p);
	}

	sort(arr.begin(),arr.end(),comparitor); // see this, this is not right, (comparitor part)
	int currFinishTime=arr[0].second;
	int count=0;
	for(int i=1;i<n;i++)
	{
		if(arr[i].first<currFinishTime) continue;
		currFinishTime=arr[i].second;
		count++;
	}
	cout<<"The max activities are : "<<count<<endl;
	return 0;
}