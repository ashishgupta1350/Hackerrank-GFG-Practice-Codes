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

void printCommon(int *arr1,int *arr2,int *arr3,int m,int n,int o)
{
    
    int i=0,j=0,k=0;
    while(j<n && k<o)
    	{
    	    if(arr2[j]==arr3[k])
    	    {
    	       // cout<<arr2[j]<<" ";
               // cout<<j<<" & "<<k<<" ";
    	        while(i<m && arr1[i]<arr2[j])
    	        {
    	            i++;
    	        }
    	        if(i==m) return;
    	        else if(arr1[i]==arr2[j])
    	        {
    	            cout<<arr1[i]<<" ";
    	            
    	        }
                k++;
    	        
    	    }
    	    else if(arr2[j]>arr3[k])
    	    {
    	     k++;   
    	    }
    	    else{
    	        j++;
    	    }
    	}
}

int main() {
	int tc;
    cin >> tc;
    while(tc--) {
    
    	int m,n,o;
        // cout<<"enter m,n,o"<<endl;
    	cin >> m>>n>>o;
    	int *arr1 = new int[m];
    	int *arr2 = new int[n];
    	int *arr3 = new int[o];
    	for (int i = 0; i < m; i++)
    	{
    		cin >> arr1[i];
    	}
    	for (int i = 0; i < n; i++)
    	{
    		cin >> arr2[i];
    	}
    	for (int i = 0; i < o; i++)
    	{
    		cin >> arr3[i];
    	}
    	printCommon(arr1,arr2,arr3,m,n,o);
    	cout<<endl;
    	delete[]arr1;delete[]arr2;delete[]arr3;
    	
    }
	return 0;
}