#include<iostream>
using namespace std;
#include<bits/stdc++.h>
int main()
{
    int t;
    cin>>t;
    int **grid=new int*[1001];
    for(int i=0;i<1001;i++)
    {
        grid[i]=new int[1001];
    }
    grid[0][0]=1;
    int p=pow(10,9)+7;
    for(int n=0;n<1001;n++)
    {
        for(int k=0;k<1001;k++)
        {
            if(n==0||n<k)
            {
                grid[n][k]=0;
            }
            else if(n==k || k==0)
            {
                grid[n][k]=1;
            }
            else{

                grid[n][k]=(grid[n-1][k]+grid[n-1][n-k-2])%p;
                
            }
        }
    }
    // for(int i=0;i<4;i++)
    // {
    //     for(int j=0;j<4;j++)
    //     cout<<grid[i][j];
    //     cout<<endl;
    // }
    while(t--)
    {
        int n;
        int k;
        cin>>n>>k;
        cout<<grid[n][k]<<endl;
    }
}