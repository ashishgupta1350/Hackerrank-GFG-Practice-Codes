#include<iostream>

using namespace std;
int josephus(int n, int k);
int main() {
  // your code goes here
  int t;
  // cin>>t;
  t=1;
  while(t--)
  {
    int n,k;
    // cin>>n>>k;
    n=5;k=3;
    cout<<josephus(n,k)<<endl;
  }
  return 0;
}


int josephus(int n, int k)
{
   //Your code here
   bool *arr=new bool[n];
   for(int i=0;i<n;i++)
   {
       arr[i]=true;
   }
   int si=0;
   int countNull=0;
   while(countNull!=n-1)
   {
    // cout<<countNull<<endl;
       for(int i=1;i<k;i++)
       {
           if(arr[si]==0)
           {
               si=(si+1)%n;
               i--;
           }
           else{
               si=(si+1)%n;
           }
       }
       while(arr[si]!=1)
       {
           si=(si+1)%n;
       }
       arr[si]=0;
       si=(si+1)%n;
       countNull++;
   }
   for(int i=0;i<n;i++)
   {
       if(arr[i]!=0)
       {
           return i+1;
       }
   }
   
   return -1;
}
