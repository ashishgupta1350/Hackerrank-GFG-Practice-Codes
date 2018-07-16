#include <iostream>
using namespace std;

int main() {
	//code
// 	this is a very basic question
    int tc;
    cout<<"enter test cases : ";
    cin>>tc;
    int n,x;
    for (int i_t=0;i_t<tc;i_t++){
        cout<<"enter n : ";
        cin>>n;
        int *arr=new int (n+1);
        for(int i=1;i<n+1;i++){
           arr[x]=0;
        }
        cout<<"enter array : ";
        for(int i=1;i<n;i++){
           cin>>x;
           arr[x]=1;
        }
        for(int i=1;i<n+1;i++){
           if(arr[i]==0){
               cout<<i<<endl;
               break;
           }
        }
        delete []arr;
        
    }

	return 0;
}