#include<bits/stdc++.h>
using namespace std;
#define LL long long int
#define FOR(a,b,c)   for (int (a)=(b); (a)<(c); (a)++)
#define FORN(a,b,c)  for (int (a)=(b); (a)<=(c); (a)++)
#define FORD(a,b,c)  for (int (a)=(b); (a)>=(c); (a)--)
#define REP(i,n)     FOR(i,0,n)
#define REPN(i,n)    FORN(i,1,n)
#define REPD(i,n)    FORD(i,n,1)

void printIntegers(string s,int flag=0)
{
    int n=s.length();
    cout<<s.substr(3)<<endl;
    if(n<=0) return  ;
    int i=0;

    if(isdigit(s[0])==true)
    {
        // flag=1;
        
        while(s[i]!='\0' && isdigit(s[i]))
        {
            cout<<s[i];
            i++;
        }
        cout<<" ";
    }
    if(s[i]=='\0') return ;
    else
         printIntegers(s.substr(i),flag);
}

int main() {
	int tc;
    cin >> tc;
    while(tc--) {
    
    	string s;
    	cin>>s;
    	printIntegers(s);
        if(s==""){
    	}
    	else 
    	    cout<<"No Integers";
    	cout<<endl;
    }
	return 0;
}