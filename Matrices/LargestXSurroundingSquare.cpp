#include<bits/stdc++.h>
using namespace std;
#define LL long long int
#define FOR(a,b,c)   for (int (a)=(b); (a)<(c); (a)++)
#define FORN(a,b,c)  for (int (a)=(b); (a)<=(c); (a)++)
#define FORD(a,b,c)  for (int (a)=(b); (a)>=(c); (a)--)
#define REP(i,n)     FOR(i,0,n)
#define REPN(i,n)    FORN(i,1,n)
#define REPD(i,n)    FORD(i,n,1)

int getXLeftDown(bool** matrix,int n,int row,int col)
{
    // pair<int,int> ans;
    int a=0,b=0;
    for(int i=row+1;i<n;i++)
    {
        if(matrix[i][col]==1) a++;
        else break;
    }
    for(int i=col+1;i<n;i++)
    {
        if(matrix[row][i]==1) b++;
        else break;
    }
    cout<<"For row, col: "<<row<<" "<<col<<" returning "<<min(a,b)<<endl;
    return min(a,b);
    
}

bool checkX(bool **matrix,int n,int row,int col,int m)
{
    cout<<"For row, col: "<<row<<" "<<col<<" "<<m<<endl;
    for(int c=col;c<col+m+1 && c<n;c++)
    {
        if(matrix[row+m][c]!=1) return false;
    }
    for(int r=row;r<row+m+1 && r<n;r++)
    {
        if(matrix[r][col+m]!=1) return false;
    }
    cout<<" returning true"<<endl;
    return true;
}

int getAns(bool**matrix,int n)
{
    int ans=1;
    REP(i,n)
    {
        REP(j,n)
        {
            if(matrix[i][j]==1)
            {
                int m=getXLeftDown(matrix,n,i,j);
                if(m==0) continue;
                
                if(checkX(matrix,n,i,j,m))
                {
                    (ans<m+1)? (ans=m+1):(ans=ans);
                }
            }
        }
    }
    return ans;
}

int main() {
    int tc;
    cin >> tc;
    while(tc--) {
        int n;cin>>n;
        bool **matrix=new bool*[n];
        REP(i,n)
            matrix[i]=new bool [n];
        char ch;
        REP(i,n)
        REP(j,n)
        {
            cin>>ch;
            if(ch=='X') matrix[i][j]=1;
            else matrix[i][j]=0;
        }
        cout<<getAns(matrix,n);
        cout<<endl;
    }
    return 0;
}