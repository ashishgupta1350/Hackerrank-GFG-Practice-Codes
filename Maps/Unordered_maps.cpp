#include <iostream>
#include<unordered_map>
using namespace std;
#define LL long long int
#define FOR(a,b,c)   for (int (a)=(b); (a)<(c); (a)++)
#define FORN(a,b,c)  for (int (a)=(b); (a)<=(c); (a)++)
#define FORD(a,b,c)  for (int (a)=(b); (a)>=(c); (a)--)
#define REP(i,n)     FOR(i,0,n)
#define REPN(i,n)    FORN(i,1,n)
#define REPD(i,n)    FORD(i,n,1)

void removeDuplicates(int *a , int size,unordered_map<int,bool> &seen)
{
    // vector<int> output;
    // unordered_map<int,bool> seen;
    for(int i=0;i<size;i++)
    {
        if(seen[a[i]]==false){
            seen[a[i]]=true;
        }
    }
    return;
}

int main() {
	
    // unordered_map<string,int> myMap;
    // int n;
    // cin>>n;
    // for(int i=0;i<n;i++)
    // {

    //     cout<<"enter string "<<i<<" : ";
    //     string s;
    //     cin>>s;
    //     myMap[s]=1;

    // }
    int *arr=new int[5];
    for(int i=0;i<5;i++)
    {
        cin>>arr[i];
    }
    unordered_map<int,bool> myMap;
    removeDuplicates(arr,5,myMap);
    for(auto it=myMap.begin();it!=myMap.end();it++)
    {
        //++ is overloaded 
        if(it->second==true)
            cout<<it->first<<" : "<<it->second<<endl;
    }


	return 0;
}