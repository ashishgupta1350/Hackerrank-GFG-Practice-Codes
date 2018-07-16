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



int advBS(int *arr,int n,int key)
{
    int si=0;
    int ei=n-1;
    
    
    while(si<=ei){
        int mid=si+(ei-si)/2;
        // cout<<mid<<" ";
        if(arr[mid]==key || (mid-1>=si && arr[mid-1]==key) || (mid+1<=ei && arr[mid+1]==key))
        {
            return mid;
        }
        else if(arr[mid]>key)
        {
            ei=mid-2;
            
        }
        else{
            si=mid+2;
        }
    }
        return -1;
}

void print(int *arr,int n,int index,int si,int ei)
{
    for(int i=si;i<=ei;i++)
    {
        if(i==index) continue;
        cout<<arr[i]<<" ";
    }
}

void printNearestNeighbours(int *arr,int n,int index,int k)
{
    int diff=0;
    int ei,si;
    ei=index+k/2;
    si=index-k/2;
    if(si<0)
    {
        diff=0-si;
        ei+=diff;
        si=0;
        if(ei>=n)
        {
            ei=n-1;
        }
    }
    if(ei>=n)
    {
        diff=ei-n-1;
        si-=diff;
        ei=n-1;
        if(si<0){
            si=0;
        }
    }
    print(arr,n,index,si,ei);
}

int binarySearch(int* arr,int n,int key)
{
    int si=0;
    int ei=n-1;
    
    
    while(si<=ei){
        int mid=(ei+si)/2;
        // cout<<mid<<" ";
        if(arr[mid]==key)
        {
            return mid;
        }
        else if(arr[mid]>key)
        {
            ei=mid-1;
            
        }
        else{
            si=mid+1;
        }
        
    }
    return -1;
    
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
        // int k;cin>>k;
        int key;cin>>key;
        cout<<advBS(arr,n,key);
        
        // if(keyIndex!=-1)
        // printNearestNeighbours(arr,n,keyIndex,k);
        // cout<<endl;
    }
	return 0;
}