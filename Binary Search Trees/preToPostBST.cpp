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


void preToPost(int *arr,int si,int ei)
{
    if(si>=ei) return;
    
    else{
        int root=arr[si];   
        
        int i=si+1;
        while(i<=ei && arr[i]<root)
        {
            i++;
        }
        int ll=si+1;
        int lr=i-1;
        int rl=lr+1;
        int rr=ei;
        
        preToPost(arr,ll,lr);
        preToPost(arr,rl,rr);
        vector<int> v;
        // int *arr1=new int[ei-si+1];//
        int j=si+1;
        // int k=0;
        while(j<=ei)
        {
            v.push_back(arr[j]);j++;
            

        }
        // arr1[k]=root;
        v.push_back(root);
        //the array has been successfully copied
        // for(int i=ei;i>=si;i--)
        // {
        //     arr[i--]=arr1[k--];
        // }
        int k=0;
        for(int i=si;i<=ei;i++)
        {
            arr[i]=v[k++];
        }
        //delete []arr1;
        
        return;
    }
    
    
}

bool checkValidPreOrder(int *arr,int si,int ei)
{
    if(si>=ei) return true;
    // there is nothing wrong in it:)
    else{
        int root=arr[si];   
        
        int i=si+1;
        while(i<=ei && arr[i]<root)
        {
            i++;
        }
        //cout<<"index stopped at : "<<i<<endl;
        int k=i-1; // this is index where the values stop decreasing( the left part of BST)
        for(;i<=ei;i++)
        {
            if(arr[i]<root)
            {
                return false;
            }
            
        }
        return checkValidPreOrder(arr,si+1,k) && checkValidPreOrder(arr,k+1,ei);
    }
    
}
int main() {
	//code
	
	int tc;
    // cout << "enter tc : ";
    cin >> tc;
    for (int i = 0; i < tc; i++) {
    
    	int n;
    	cin >> n; 
    	int *arr = new int[n];
    	for (int i = 0; i < n; i++)
    	{
    		cin >> arr[i];
    	}
        //cout<<checkValidPreOrder(arr,0,n-1)<<endl;
    	if(checkValidPreOrder(arr,0,n-1)==false)
    	{
    	    cout<<"NO"<<endl;
    	   // continue;
    	}
    	else{
    	    preToPost(arr,0,n-1);
        	for (int i = 0; i < n; i++)
        	{
        		cout<<arr[i]<<" ";
        	}
        	cout<<endl;
        	continue;
    	}
    	
    	delete[]arr;
    }
	return 0;
}