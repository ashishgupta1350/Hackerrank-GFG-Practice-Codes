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
#include<map>
#include<queue>

stack<int> insertAtBottom(stack<int> myStack,int x){
    // but this will definately create some extra space! O(N) that is and even (O(n^2))
    if(myStack.empty()){
        myStack.push(x);
        return myStack;
    }
    int n=myStack.top();
    myStack.pop();
    myStack=insertAtBottom(myStack,x);
    myStack.push(n);
    return myStack;
}

stack<int> Reverse(stack<int> myStack) /* returning my stack is useless, use reference. see the reverse_stack_pointers.cpp*/
{
    if(myStack.empty())
        return myStack;
    int x=myStack.top();
    myStack.pop();
    Reverse(myStack);
    // insert the x at the bottom of the stack but you can't use (O(n)) space
    myStack=insertAtBottom(myStack,x);// stack is almost reversed
    // I can also make a stack here and do reverse in (O(N)) space and time.
    return myStack;
}

void printStack(stack<int> myStack)
{
    while(myStack.empty()==false)
    {
        int x=myStack.top();
        cout<<x<<" ";
        myStack.pop();
    }
    return;
}

int main() {
	//code
	

    stack<int> myStack;
    myStack.push(1);
    myStack.push(2);
    myStack.push(3);
    myStack.push(4);
    // stack is 1 2 3 4. 
    // if I print it prints: 4 3 2 1
    myStack=Reverse(myStack);
    printStack(myStack);
	



	return 0;
}