#include<bits/stdc++.h>
using namespace std;
#define LL long long int
#define FOR(a,b,c)   for (int (a)=(b); (a)<(c); (a)++)
#define FORN(a,b,c)  for (int (a)=(b); (a)<=(c); (a)++)
#define FORD(a,b,c)  for (int (a)=(b); (a)>=(c); (a)--)
#define REP(i,n)     FOR(i,0,n)
#define REPN(i,n)    FORN(i,1,n)
#define REPD(i,n)    FORD(i,n,1)


void updateMaxPal(string &s,int &i,int &j,int &val,string &maxPal)
{
    maxPal="";
    FORN(k,i,j)
    {
        maxPal+=s[k];
    }
    maxPal+='\0';
    val=j-i+1;
    return;
}


int main() {
	int t;
	cin>>t;
	
	
	while(t--)
	{
	   
	   string s;
	   cin>>s;
	   int n=s.length();
	   int Max=1;
	   string maxPal;
	   maxPal+=s[0];
	   bool **menu=new bool*[n];
	   REP(i,n)
	   {
	       menu[i]=new bool[n];
	   }
	   
	   REP(k,n)
	   {
	       int row=0;
	       int col=k;
	       while(row<n && col<n)
	       {
	           if(col==row)// right
	            menu[row][col]=true;
	            
	           else if(col-row+1 == 2){// right
	               if(s[row]==s[col]) 
	               {
	                   menu[row][col]=true;
	                    if(Max<col-row+1)
	                        updateMaxPal(s,row,col,Max,maxPal);
	                       // cout<<maxPal<<" ";
	               }
	               else{menu[row][col]=false;}
	           }
	           else{
	               if(s[row]==s[col])
	               {
	                   menu[row][col]=menu[row+1][col-1];
	                   if(Max<col-row+1 && menu[row+1][col-1])
	                   updateMaxPal(s,row,col,Max,maxPal);
	                   //cout<<maxPal<<" ";
	               }
	               else{
	                   menu[row][col]=false;
	               }
	           }
	           row++;
	           col++;
	       }
	   }
	   cout<<maxPal<<endl;
	}
	return 0;
}