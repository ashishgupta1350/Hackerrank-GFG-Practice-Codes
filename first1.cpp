#include <iostream>
using namespace std;
int **a;
int maxIndex(int *arr, int si,int ei){
    if (si>ei) return -1;
    if (si==ei) return 0;
    
    
    
    
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
    	
    	a = new int*[rowCount];
        for(int i = 0; i < rowCount; ++i)
             a[i] = new int[colCount];
        int** a = new int*[rowCount];
        for(int i = 0; i < rowCount; ++i)
            delete[]a[i];
        delete[]a;
        delete[]arr;
    }
	return 0;
}