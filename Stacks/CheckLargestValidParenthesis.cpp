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
int main() {
    //code
    
    int tc;
    // cout << "enter tc : ";
    cin>>tc;
    while(tc--)
    {
        string s;
        cin>>s;
        stack <char> st;
        stack<int> numSt;
        numSt.push(0);
        //int Count=0;
        int n=s.length();
        int m=0;
        for(int i=0;i<n;i++)
        {
           // cout<<i<<endl;
            if(s[i]=='(')
            {
                st.push('(');
            }
            else if(s[i]==')')
            {
                 //cout<<i<<endl;
                if(st.empty())
                {
                    numSt.push(0);
                }
                else if(st.top()=='(')
                {
                    st.pop();
                    int a=numSt.top();numSt.pop();
                    a+=2;
                    if(a>m)
                    {
                        m=a;
                    }
                    numSt.push(a);
                }
            }
        }
        cout<<m<<endl;
    }
    return 0;
}