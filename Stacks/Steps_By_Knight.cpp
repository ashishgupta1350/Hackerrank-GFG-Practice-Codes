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
//queue<int> q;

// create a memo
int StepsToAttackHelper(int n,int k1, int k2,int t1,int t2,queue<int> q){
    // base case 
    if(k1==t1 && k2==t2) return 0;
    else{
        if(k1-2 >= 1 && k2-1 >=1) {
            q.push(1+StepsToAttackHelper(n,k1-2,k2-1,t1,t2,q));
            // this is dynamic programming question. 
        }
        if(k1-2 >= 1 && k2+1 <=n) {
            q.push(1+StepsToAttackHelper(n,k1-2,k2+1,t1,t2,q));
        }
        if(k1-1 >= 1 && k2-2 >=1) {
            q.push(1+StepsToAttackHelper(n,k1-1,k2-2,t1,t2,q));
        }
        if(k1-1 >= 1 && k2+2 <=n) {
            q.push(1+StepsToAttackHelper(n,k1-1,k2+2,t1,t2,q));
        }
        // half way
        if(k1+2 <=n && k2+1 <=n) {
            q.push(1+StepsToAttackHelper(n,k1+2,k2+1,t1,t2,q));
        }
        if(k1+2 <=n && k2-1>=1) {
            q.push(1+StepsToAttackHelper(n,k1+2,k2-1,t1,t2,q));
        }
        if(k1+1 <=n  && k2+2 <=n ) {
            q.push(1+StepsToAttackHelper(n,k1+1,k2+2,t1,t2,q));
        }
        if(k1+1<=n  && k2-2 >=1) {
            q.push(1+StepsToAttackHelper(n,k1+1,k2-2,t1,t2,q));
        }
        return 
        
    }
    
}

int stepsToAttack(int n,int k1, int k2,int t1,int t2,queue<int> q){
    if(k1==t1 && k2==t2){
        return 0;
    }
    else if(n==1){
        return -1;
    }
    else if(n==2){
        return -1; // there is no place for the knight to move
    }
    else if (n==3){
        if(k1==2 && k2==2) return -1;
    }
    else return StepsToAttackHelper(n,k1,k2,t1,t2);
    
    
    
}

int main() {
	//code
	
	int tc;
    // cout << "enter tc : ";
    cin >> tc;
    for (int i = 0; i < tc; i++) {
    
    	int n;
    	cin >> n;
    	int k1,k2;
    	int t1,t2;
        cin>>k1>>k2>>t1>>t2;
        // we have source and target location
        queue<int> q;
        // int **memo=new int*[n];
        // for (int i=0;i<n;i++)

        int Ans=stepsToAttack(n,k1,k2,t1,t2,q);
        cout<<Ans<<endl;

    }
	return 0;
}