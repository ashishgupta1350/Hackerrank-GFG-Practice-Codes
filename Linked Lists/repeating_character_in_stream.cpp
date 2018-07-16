#include <iostream>
using namespace std;
#include<map>
#include<list>
// working solution and simple approach using singly lists, map (all are inbuilt.)

int main() {
	//code
	
	int tc;
    // cout << "enter tc : ";
    cin >> tc;
    for (int i = 0; i < tc; i++) {
    
    	int n;
    	cin >> n;
    	char *arr = new char[n];
    	for (int i = 0; i < n; i++)
    	{
    		cin >> arr[i];
    	}
    	
        map<char,int> myMap;
        list<char> myList;
        for(int i=0;i<n;i++)
        {
            // go thru every element and do these operations.
            if(myMap[arr[i]]==0){
                myMap[arr[i]]+=1;
                myList.push_back(arr[i]);
                cout<<myList.front()<<" ";
            }
            else{
                myList.remove(arr[i]);
                if(myList.empty()){
                    cout<<"-1"<<" ";
                }
                else{
                    cout<<myList.front()<<" ";
                }
            }
            
            
        }
        cout<<endl;
    	
    }
	return 0;
}