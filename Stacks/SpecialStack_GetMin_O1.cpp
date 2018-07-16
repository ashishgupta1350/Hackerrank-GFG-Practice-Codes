#include <iostream>
using namespace std;
#define LL long long int
#define FOR(a,b,c)   for (int (a)=(b); (a)<(c); (a)++)
#define FORN(a,b,c)  for (int (a)=(b); (a)<=(c); (a)++)
#define FORD(a,b,c)  for (int (a)=(b); (a)>=(c); (a)--)
#define REP(i,n)     FOR(i,0,n)
#define REPN(i,n)    FORN(i,1,n)
#define REPD(i,n)    FORD(i,n,1)
#include<stack>

class SpecialStack{
public:
    // we have 2 stacks.
    stack<int> mainStack;
    stack<int> minStack;
    int size;
/// complete this , because I am tired of doing this simple question. the logic is great, I could not think, but the implementation is quiet simple.
    SpecialStack(){this->size=0;}
    void push(int x)
    {

        this->mainStack.push(x);
        size++;
    }
    void pop()
    {

        this->mainStack.pop(x);
    }
    int top()
    {
        return this->mainStack.top();
    }
    int
};

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
        // we have array

    }
	return 0;
}