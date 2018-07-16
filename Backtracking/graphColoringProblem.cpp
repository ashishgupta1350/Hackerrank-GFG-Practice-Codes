#include <iostream>
using namespace std;
#define LL long long int
#define FOR(a,b,c)   for (int (a)=(b); (a)<(c); (a)++)
#define FORN(a,b,c)  for (int (a)=(b); (a)<=(c); (a)++)
#define FORD(a,b,c)  for (int (a)=(b); (a)>=(c); (a)--)
#define REP(i,n)     FOR(i,0,n)
#define REPN(i,n)    FORN(i,1,n)
#define REPD(i,n)    FORD(i,n,1)
#include<queue>
#include<stack>
#include<algorithm>
#include<map>

bool checkSafe(int color,int *ca,int **edges,int n,int sv)
{
    REP(i,n)
    {
        if(edges[sv][i]==1)
        {
            if(ca[i]==color)
                return false;
        }
    }
    return true;
}

bool graphColoring(int **edges,int n,int *ca,int sv,int m)
{
    int flag=0,flag1=0;
    REP(i,n) // see if all the vertexes are colored
    {
        if(ca[i]==-1)
        {
            flag=1;
            break;
        }
    }
    if(flag==0) return true;
    bool flag2=0;
    REP(c,m) // for all colors
    {
        if(checkSafe(c,ca,edges,n,sv))
        {
            flag2=1;
            ca[sv]=c;
            REP(i,n)
            {
                if(edges[sv][i]==1 && ca[i]==-1)
                {
                    flag1=1;
                    bool isTrue=graphColoring(edges,n,ca,i,m);
                    if(isTrue) return true;
                }
            }
        }
    }
    if(flag2==false)
    {
        return false;
    }
    bool flag3=false;
    if (flag1) return false;// return true didnot happen inside. so a color was indeed present but all of them would have returned false;
    else{
        REP(i,n)
        {
            if(ca[i]==-1)
            {
                flag3=true;
                bool isTrue=graphColoring(edges,n,ca,i,m);
                if(isTrue) return true;
            }
        }

    }
    if(flag3==false) return true;
    return false;
}

int main() {
	int tc;
    cin >> tc;
    while(tc--) {
    
    	int n,m;
    	cin >> n>>m;
    	int **edges=new int*[n];
        REP(i,n){
            edges[i]=new int[n];
        }
        REP(i,n)
        {
            REP(j,n){
                int x;
                int y;
                cin>>x>>y;
                edges[x][y]=1;
                edges[y][x]=1;
            }
        }
        int *ca=new int[n];
        REP(i,n)
        {
            ca[i]=-1;
        }
        // int m;
        // cin>>m;
        bool isTrue=graphColoring(edges,n,ca,0,m);
        if(isTrue)
        {
            cout<<"YES";
        }
        else cout<<"NO";
        cout<<endl;
    }
	return 0;
}