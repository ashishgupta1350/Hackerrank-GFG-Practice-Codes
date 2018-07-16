#include <iostream>
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

bool checkEqualSubsetSum(int *arr,int n,int leftSum,int rightSum,int totalSum,bool**memo)
{
    if(n==0)
    {
        if(leftSum==rightSum){ memo[leftSum][rightSum]=true;return true;}
        else {memo[leftSum][rightSum]=false;return false;}
    }
    if(leftSum>rightSum) return false;
    if(memo[leftSum][rightSum]) return true;
    else 
        memo[leftSum][rightSum]=checkEqualSubsetSum(arr+1,n-1,leftSum,rightSum,totalSum,memo);
    if(memo[leftSum][rightSum]) return true;
    
    if(memo[leftSum-arr[0]][rightSum+rightSum+arr[0]])
    {
        return true;
    }
    memo[leftSum+arr[0]][rightSum-arr[0]]=checkEqualSubsetSum(arr+1,n-1,leftSum+arr[0],rightSum-arr[0],totalSum,memo);
    return memo[leftSum-arr[0]][rightSum+rightSum+arr[0]];
}

int main() {
    int tc;
    cin >> tc;
    bool**memo=new bool*[10000];
        for(int i=0;i<10000;i++)
        {
            memo[i]=new bool[10000];
        }
    while(tc--) {
    
        int n;
        cin >> n;
        int *arr = new int[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        sort(arr,arr+n);
        int sum=0;
        
        for(int i=0;i<10000;i++)
        {
            for(int j=0;j<10000;j++)
            {
                memo[i][j]=false;
            }
        }
        for(int i=0;i<n;i++)
        {
            sum+=arr[i];
        }
        bool isTrue=checkEqualSubsetSum(arr,n,0,sum,sum,memo);
        if(isTrue)
        {
            cout<<"YES"<<endl;
            
        }
        else cout<<"NO"<<endl;
    }
    return 0;
}