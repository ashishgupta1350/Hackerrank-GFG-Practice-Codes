// #include<bits/stdc++.h>
// using namespace std;
// #define LL long long int
// #define FOR(a,b,c)   for (int (a)=(b); (a)<(c); (a)++)
// #define FORN(a,b,c)  for (int (a)=(b); (a)<=(c); (a)++)
// #define FORD(a,b,c)  for (int (a)=(b); (a)>=(c); (a)--)
// #define REP(i,n)     FOR(i,0,n)
// #define REPN(i,n)    FORN(i,1,n)
// #define REPD(i,n)    FORD(i,n,1)


// LL getMaxAHelper(LL N, LL str, LL buffer, map<pair<LL,LL>,LL> &myMap)
// {
//     if(N==0) return str;
//     LL a,b,c;
//     a=b=c=INT_MIN;
//     pair<LL,LL> p(N,str);
//     if(myMap[p]!=0)
//     {
//         return myMap[p];
//     }
//     if(myMap[make_pair(N-1,str+1)]==0)
//         myMap[make_pair(N-1,str+1)]=a=getMaxAHelper(N-1,str+1,0,myMap);// clear the buffer since that wont be an optimal solution anyways
    
//     if(myMap[make_pair(N-1,str+buffer)]==0)
//         myMap[make_pair(N-1,str+buffer)]=b=getMaxAHelper(N-1,str+buffer,buffer,myMap);
//     if(N>=3 and myMap[make_pair(N-3,2*str)]==0)
//     {
//         // this is because the buffer cant have new values appended to earlier values
//         myMap[make_pair(N-3,2*str)]=c=getMaxAHelper(N-3,str+str,str,myMap);
//     }
//     myMap[p]= max(a,max(b,c));
//     return myMap[p];

// }


// LL getMaxA(LL N)
// {
//     // if(N==0) return str;
//     // LL a,b,c;
//     // a=b=c=INT_MIN;
//     // a=getMaxA(N-1,str+1,0);// clear the buffer since that wont be an optimal solution anyways
//     // b=getMaxA(N-1,str+buffer,buffer);
//     // if(N>=3)
//     // {
//     //     // this is because the buffer cant have new values appended to earlier values
//     //     c=getMaxA(N-3,str+str,str);
//     // }
//     // return max(a,max(b,c));
//     map<pair<LL,LL>,LL> myMap;
//     return getMaxAHelper(N,0,0,myMap);
    

// }

// int main() {
//     int tc;
//     // cin >> tc;
//     tc=1;
//     while(tc--) {
    
//         LL N=79;
//         // cin>>N;
//         cout<<getMaxA(N);
//         cout<<endl;
        
//     }
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;
#define LL long long int
#define FOR(a,b,c)   for (int (a)=(b); (a)<(c); (a)++)
#define FORN(a,b,c)  for (int (a)=(b); (a)<=(c); (a)++)
#define FORD(a,b,c)  for (int (a)=(b); (a)>=(c); (a)--)
#define REP(i,n)     FOR(i,0,n)
#define REPN(i,n)    FORN(i,1,n)
#define REPD(i,n)    FORD(i,n,1)


LL f(LL N,LL * arr)
{
    // cout<<N<<" "<<arr[7]<<endl;
    if(N<0) return 0;
    if(N>=0 and N<=6) return N;
    else 
    {
        // cout<<N<<" arr[N] : "<<arr[N]<<endl;
        if(arr[N]!=-1) return arr[N];
        else 
        {
            // cout<<"For N: "<<N<<" arr[N]= "<<arr[N]<<endl;
            arr[N]=max(f(N-3,arr)*2,max(f(N-4,arr)*3,f(N-5,arr)*4));
            return arr[N];
        }
    }
}

LL getMaxA(LL N)
{
    
    LL *arr=new LL[N+1];
    for(int i=0;i<N+1;i++){
        arr[i]=-1;
    }
    
    return f(N,arr);

}

int main() {
    int tc;
    cin >> tc;
    // tc=1;
    while(tc--) {
    
        LL N;
        cin>>N;
        cout<<getMaxA(N)<<" ";
        
        
    }
    return 0;
}