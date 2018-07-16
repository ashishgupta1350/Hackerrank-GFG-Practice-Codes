#include<bits/stdc++.h>
using namespace std;
#define LL long long int
#define FOR(a,b,c)   for (int (a)=(b); (a)<(c); (a)++)
#define FORN(a,b,c)  for (int (a)=(b); (a)<=(c); (a)++)
#define FORD(a,b,c)  for (int (a)=(b); (a)>=(c); (a)--)
#define REP(i,n)     FOR(i,0,n)
#define REPN(i,n)    FORN(i,1,n)
#define REPD(i,n)    FORD(i,n,1)
#include<queue>
#include<stack>
#include<algorithm>
#include<map>

int greedyProfit(vector<pair<int,int>>v,int n,int *slots)
{
    int num=0;
    for(int i=0;i<n;i++)
    {
        int index=v[i].first-1;
        while(index>=0 )
        {
            if(slots[index]==0)
            {
                slots[index]=v[i].second;
                num++;
                break;
            }
            index--;
        }
    }
    return num;
    
}

bool comparitor(pair<int,int> &a,pair<int,int> &b)
{
    return a.second>b.second;//order of higest profit and profit is a.second.
}

int main() {
	int tc;
    cin >> tc;
    while(tc--) {
    
    	int n;
    	cin >> n;
    	vector<pair<int,int>> v;
    	int HDeadline=-1;
    	for (int i = 0; i < n; i++)
    	{
    		int a,b,c;
    		cin>>a>>b>>c;
    		pair<int,int> p(b,c);// deadline,profit
    		v.push_back(p);
    		if(HDeadline<b)
    		{
    		    HDeadline=b;
    		}
    	}
    	// make slots array with Hdeadline as size
    	int *slots=new int[HDeadline];
        for(int i=0;i<HDeadline;i++)
        {
            slots[i]=0;
        }
    	// greedyProfit()
    	sort(v.begin(),v.end(),comparitor);
        int num=greedyProfit(v,n,slots);
        int sum=0;
        for(int i=0;i<HDeadline;i++)
        {
            sum+=slots[i];
        }
        cout<<num<<" "<<sum<<endl;
        delete[]slots;
        // delete v;
    	
    }
	return 0;
}