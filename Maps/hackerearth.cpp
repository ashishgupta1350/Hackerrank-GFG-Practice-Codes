#include <iostream>
using namespace std;
#define LL long long int
#define FOR(a,b,c)   for (int (a)=(b); (a)<(c); (a)++)
#define FORN(a,b,c)  for (int (a)=(b); (a)<=(c); (a)++)
#define FORD(a,b,c)  for (int (a)=(b); (a)>=(c); (a)--)
#define REP(i,n)     FOR(i,0,n)
#define REPN(i,n)    FORN(i,1,n)
#define REPD(i,n)    FORD(i,n,1)
#include<cmath>
int main() {
	//code
	
	for(int i=1;i<22;i++)
    {
        for(int j=1;j<22;j++)
        {
            if(pow(i,j)==pow(j,i))
            {
                cout<<i<<" "<<j<<endl;
            }
        }
    }
	return 0;
}