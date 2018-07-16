#include <iostream>
#include<stack>
#include<map>
using namespace std;
#define LL long long int
#define FOR(a,b,c)   for (int (a)=(b); (a)<(c); (a)++)
#define FORN(a,b,c)  for (int (a)=(b); (a)<=(c); (a)++)
#define FORD(a,b,c)  for (int (a)=(b); (a)>=(c); (a)--)
#define REP(i,n)     FOR(i,0,n)
#define REPN(i,n)    FORN(i,1,n)
#define REPD(i,n)    FORD(i,n,1)
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

            // we have a stack and we have a map, we can easily code this problem, if time!


    }
	return 0;
}