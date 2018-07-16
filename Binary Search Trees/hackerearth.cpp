#include <iostream>
using namespace std;
#define LL long long int
#define FOR(a,b,c)   for (int (a)=(b); (a)<(c); (a)++)
#define FORN(a,b,c)  for (int (a)=(b); (a)<=(c); (a)++)
#define FORD(a,b,c)  for (int (a)=(b); (a)>=(c); (a)--)
#define REP(i,n)     FOR(i,0,n)
#define REPN(i,n)    FORN(i,1,n)
#define REPD(i,n)    FORD(i,n,1)
#include<vector>
#include<algorithm>
bool sorting(pair<LL,LL> &p1,pair<LL,LL> &p2)
{
    return p1.first>p2.first;
}

int main() {
	//code
	
	int tc;
    // cout << "enter tc : ";
    cin >> tc;
    for (int i = 0; i < tc; i++) {
    
    	int n;
    	cin >> n;
    	LL *arr = new LL[n+1];
    	arr[0]=-1;// garbage value not to be used
    	for (LL i = 1; i <=n; i++)
    	{
    		cin >> arr[i];
    	}
    	
    	vector<pair<LL,LL>> v;
    	v.push_back(make_pair(100000001,100000001));// so that ut stays at the front and  not counted
    	for (LL i = 1; i <= n; i++)
    	{
    	    pair<LL,LL> p(arr[i],i);
    		v.push_back(p);
    	}
    	sort(v.begin(),v.end(),sorting);
        // for (LL i = 1; i <= n; i++)
        // { 
        //     cout<<v[i].first<<" ";
        // }
        // cout<<endl<<" this was vector"<<endl;
    	// check if this is soted well
    	LL Count=1;
    	LL reward=1;
    	LL currVal=v[1].first;// this is important
    	for (LL i = 1; i <= n; i++)
    	{
    		if(v[i].first==currVal)
    		{
    		    arr[v[i].second]=reward;
    		}
    		else{
    		    reward=Count;
    		    currVal=v[i].first;
                arr[v[i].second]=reward;
    		}
    		Count++;
    	}
    for (int i = 1; i <= n; i++)
    	{
    		cout<<arr[i]<<" ";
    	}
             delete[]arr;
             cout<<endl;
    }
	return 0;
}