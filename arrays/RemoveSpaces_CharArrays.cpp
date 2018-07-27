#include<bits/stdc++.h>
using namespace std;
#define LL long long int
#define FOR(a,b,c)   for (int (a)=(b); (a)<(c); (a)++)
#define FORN(a,b,c)  for (int (a)=(b); (a)<=(c); (a)++)
#define FORD(a,b,c)  for (int (a)=(b); (a)>=(c); (a)--)
#define REP(i,n)     FOR(i,0,n)
#define REPN(i,n)    FORN(i,1,n)
#define REPD(i,n)    FORD(i,n,1)

int main() {
	int tc=1;
    // cin >> tc;
    while(tc--) {
    
    	vector<string> v;
    	string s;
    	do
    	{
    	   // string s;
    	    cin>>s;
    	    v.push_back(s);

    	}while(s!="");
    	REP(i,v.size())
    	{
    	    cout<<v[i];
    	}
    	cout<<endl;
    }
	return 0;
}