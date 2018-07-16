/*
// Sample code to perform I/O:
#include <stdio.h>

int main(){
	int num;
	scanf("%d", &num);              			// Reading input from STDIN
	printf("Input number is %d.\n", num);       // Writing output to STDOUT
}

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/

// Write your code here
#include<iostream>
using namespace std;

void bombCircle(int x, int y,int r, int **bombs)
{
    // you will get the x and y and return the bomb radius
    for(int i=x-r;i<=x+r;i++)
    {
        for(int j=y-r;j<=y+r;j++)
        if(i<=1000 && i>=1 && j<=1000 && j>=1)
        {
            if( (i-x)*(i-x) + (j-y)*(j-y) <= r*r)
            {
                bombs[i][j]+=1;
            }
            
        }
    }
    return;
}

int main()
{
    int n;
    cin>>n;
    int **bombs=new int *[1000];
    int count=0;
    for(int i=0;i<=n;i++)
    {
        bombs[i]=new int [1001];
    }
    for(int i=0;i<=1000;i++)
    {
        for(int j=0;j<=1000;j++)
        {
            bombs[i][j]=0;
        }
    }
    for(int i=1;i<=n;i++)
    {
        int x,y;
        cin>>x>>y;
        int r;
        cin>>r;
        bombCircle(x,y,r,bombs);
    }
    
    for(int i=1;i<=1000;i++)
    {
        for(int j=1;j<=1000;j++)
        {
            if(bombs[i][j]>=2)
            {
                count+=1;
            }
        }
    }
    cout<<count<<endl;
}