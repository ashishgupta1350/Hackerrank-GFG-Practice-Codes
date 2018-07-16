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
#include<stack>
#include<map>
// code works great now!

void printPostFix(vector<char> v,int n,map<char,int> precidence)
{
    stack<char> myStack;
    myStack.push('(');
    v.push_back(')');
    int i=0;
    while(!myStack.empty() &&i<n+1)
    {
        int ascii=v[i];
        char ch=v[i];
        //cout<<"ch being processed is : "<<ch<<" ascii : "<<ascii<<endl;

        if((ascii>=65 && ascii<=90) || (ascii>=97 && ascii<=122) ){
            // this means an alphabet
            cout<<ch;
        }
        else if(ch=='(')
        {
            myStack.push(ch);
        }
        else if(ch=='+'||ch=='-'||ch=='/'||ch=='*'||ch=='^'||ch=='%')/// all the operators. I assume no garbage operator is provided except the 6 operators
        {
            char ch_top=myStack.top();// see if this is really a function
            // be carefull with the equal to sign below! 
            if(precidence[ch]>precidence[ch_top])
            {
                // push the ch on the stack
                myStack.push(ch);
            }
            else{

                char ch_top=myStack.top();

                while(ch_top!='(' && precidence[ch]<=precidence[ch_top])
                {

                    ch_top=myStack.top();
                    if(ch_top=='(') break;
                    myStack.pop();
                    cout<<ch_top;
                    //myStack.push(ch);
              }
              myStack.push(ch);
            }

        }
        else if(ch==')')
        {
            while(!myStack.empty() && myStack.top()!='(')
            {
                char ch_top=myStack.top();
                myStack.pop();
                cout<<ch_top;

            }
            myStack.pop();
        }
        i++;
    }
    cout<<endl;
    return;

}

int main() {
	//code
	
	int tc;
    // cout << "enter tc : ";
    cin >> tc;
    for (int i = 0; i < tc; i++) {
    
    	
    	vector<char> v;
        string s;
        cin>>s;
    	for (int i = 0; s[i]!='\0'; i++)
    	{
            char k;
            k=s[i];
            v.push_back(k);
    	}
        map<char,int> precidence;
        precidence['+']=1;
        precidence['-']=1;
        precidence['*']=2;
        precidence['/']=2;
        precidence['^']=3;// higher the better rule
        precidence['%']=3;
        int n=s.length();
        printPostFix(v,n,precidence);
        
        continue;
    }
	return 0;
}