#include<bits/stdc++.h>
using namespace std;
#define LL long long int
#define FOR(a,b,c)   for (int (a)=(b); (a)<(c); (a)++)
#define FORN(a,b,c)  for (int (a)=(b); (a)<=(c); (a)++)
#define FORD(a,b,c)  for (int (a)=(b); (a)>=(c); (a)--)
#define REP(i,n)     FOR(i,0,n)
#define REPN(i,n)    FORN(i,1,n)
#define REPD(i,n)    FORD(i,n,1)
// maps will be used
string bringString(string s,int i,int j)
{
    string retString="";
    while(i<=j)
    {
        retString+=s[i];
        i++;
    }
    return retString;
}

bool test(map<char,int> sMap,map<char,int> tMap)
{
    for(auto it=tMap.begin();it!=tMap.end();it++)
    {
        char ch=it->first;
        int count=it->second;
        // cout<<ch<<" "<<count<<endl;
        if(sMap.find(ch)==sMap.end() or sMap[ch]<count)
        {
            // cout<<" returning false"<<endl;
            return false;
        }
        
    }
    return true;
}
string bringSmallest(string s,string t)
{
    // create a hash map of t(targeted string , whose characters are to be matched. This map will not change)
    map<char,int> tMap;
    cout<<boolalpha;
    int i=0;
    while(t[i]!='\0')
    {
        tMap[t[i]]+=1;
        i++;
    } 
    // cout<<"here"<<endl;

     map<char,int> sMap;
    i=0;int j=0;int sLen=INT_MAX;int cLen=0;string sString;// current len, smallest len
    int n=s.length();
    // cout<<"here"<<endl;

    while(j<n)
    {
        char ch=s[j];
        cLen++;
        sMap[ch]++;
        bool isTrue=test(sMap,tMap);
        // cout<<j<<" "<<isTrue<<endl;
       
        // check if increment of a character led us to find the string or not.
        if(isTrue)
        {
          
            j++; // j has to be increased for future purpose
            
           sLen=cLen;
           sString=bringString(s,i,j);
            break;
        }                
        j++;
    }
    if(sLen==INT_MAX or j>=n)
    {
        
        return sString;
    }
    while(i<n && j<n)
    {
        cout<<"i and j are "<<i<<" "<<j<<endl;
                char ch=s[i];
        sMap[ch]-=1;
        cLen-=1;
        if(tMap.find(ch)==tMap.end())
        {
            i++;continue;
        }
        if(sMap[ch]>=tMap[ch])
        {
            if(cLen<sLen)
            {
                sLen=cLen;
                sString=bringString(s,i,j);
            }
        }
        else{
            while(j<n && s[j]!=ch)
            {
                sMap[ch]+=1;
                cLen+=1;
                j++;
            }
            if(j==n)
            {
                return sString;
            }
        }
        i++;
        
    }
   return sString;
}

int main() {
	int tc;
    cin >> tc;
    while(tc--) {
    
    	string s="this is test string";
    	string t="tist";
    	// cin>>s;
    	// cin>>t;
    	string ans=bringSmallest(s,t);
    	cout<<ans<<endl;
    	
    }
	return 0;
}