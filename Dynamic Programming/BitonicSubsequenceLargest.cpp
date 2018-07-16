#include<bits/stdc++.h>
using namespace std;
#define LL long long int
#define FOR(a,b,c)   for (int (a)=(b); (a)<(c); (a)++)
#define FORN(a,b,c)  for (int (a)=(b); (a)<=(c); (a)++)
#define FORD(a,b,c)  for (int (a)=(b); (a)>=(c); (a)--)
#define REP(i,n)     FOR(i,0,n)
#define REPN(i,n)    FORN(i,1,n)
#define REPD(i,n)    FORD(i,n,1)

int bitonic(int *arr,int n,int s,int lastVal,char flag,int **memorised)
{
    // increasing flag initially
    if(s>=n)
    {
        return 0;// no bitonic sequence can be found
    }
    bool f=1;
    if(flag=='i')
    {
        f=1;
    }
    else f=0;
    cout<<"start is : "<<s<<" flag is : "<<flag<<" memorised [s][f]= : "<<memorised[s][f]<<" ";
    cout<<"arr[s] : "<<arr[s]<<endl;

    if(memorised[s][f]!=-1)
    {
        return memorised[s][f];
    }
    int maxWhenLeft=bitonic(arr,n,s+1,lastVal,flag,memorised);
    if(flag=='i')
    {
        if(arr[s]>lastVal)
        {
            memorised[s][f]= max(maxWhenLeft,1+bitonic(arr,n,s+1,arr[s],flag,memorised));
        }
        else if(arr[s]==lastVal)
        {
            memorised[s][f]= maxWhenLeft;// we want the result to be strict
        }
        else
        {
            memorised[s][f]= max(maxWhenLeft,1+bitonic(arr,n,s+1,arr[s],'d',memorised)); // embrace the smaller value and say recursion to bring the best bitonic count for a decreasing subsequence
            
        }
    }
    else{
        //decreasing bitonic sequences
        if(arr[s]>=lastVal)
        {
            memorised[s][f]= maxWhenLeft;// do not go increasing again
        }
        else{
            memorised[s][f]= max(maxWhenLeft,1+bitonic(arr,n,s+1,arr[s],flag,memorised));
        }
    }
    cout<<"returning : "<<memorised[s][f]<<endl;
    return memorised[s][f];
}

int main() {
	int tc;
    cin >> tc;
    while(tc--) {
    
    	int n;
    	cin >> n;
    	int *arr = new int[n];
    	for (int i = 0; i < n; i++)
    	{
    		cin >> arr[i];
    	}
    	int ** m = new int*[n];
    	for(int i=0;i<n;i++)
    	{
    	    m[i]=new int[2];// 0 or 1
    	}
    	REP(i,n){
    	    REP(j,2)
    	    {
    	        m[i][j]=-1;
    	    }
    	}
        // REP(i,n){
        //     REP(j,2)
        //     {
        //         cout<<m[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
    	cout<<bitonic(arr,n,0,INT_MIN,'i',m)<<endl;
    }
	return 0;
}