#include<bits/stdc++.h>
using namespace std;
#define LL long long int
#define FOR(a,b,c)   for (int (a)=(b); (a)<(c); (a)++)
#define FORN(a,b,c)  for (int (a)=(b); (a)<=(c); (a)++)
#define FORD(a,b,c)  for (int (a)=(b); (a)>=(c); (a)--)
#define REP(i,n)     FOR(i,0,n)
#define REPN(i,n)    FORN(i,1,n)
#define REPD(i,n)    FORD(i,n,1)

int getLargest(string str,int s,int e)
{
    cout<<s<<" "<<e<<endl;
    if(s==e) return 1;// the alphabet is the length itself.
    if(s>e)
    {
        return 0;// no palindrome for you
    }
    else{
        if(str[s]==str[e])
        {
            return 2+getLargest(str,s+1,e-1);
        }
        else
        {
            return max(getLargest(str,s+1,e),getLargest(str,s,e-1));
        }
        
    }
}

int main() {
	int tc;
    cin >> tc;
    while(tc--) {
    
    	int n;
    	// cin >> n;
    	string s;
    	cin>>s;
        // cout<<s<<endl;
    	cout<<getLargest( s,0,s.length()-1)<<endl;
    }
	return 0;
}