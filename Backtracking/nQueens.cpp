#include<bits/stdc++.h>
using namespace std;

bool isSafe(vector<int> placed, int row,int col)
{
	if(placed.size()==0) return true;
	int n=placed.size();
	for(int i=0;i<n;i++)
	{
		if(placed[i]==col or i==row or i-placed[i]==row-col or i+placed[i]==row+col)
		{
			return false;
		}
	}
	return true;
}

void nQueens(int n,vector<int> &placed)
{
	if(placed.size()==n)
	{
		for(int i=0;i<n;i++) cout<<placed[i]<<" ";
			cout<<endl;
		return ;
	}
	int row=placed.size();
	for(int col=0;col<n;col++)
	{
		if(isSafe(placed,row,col))
		{
			placed.push_back(col);
			nQueens(n,placed);
			placed.pop_back();
		}
	}
	return;
	
}
int main()
{

	int tc=8;
	while(tc--)
	{
		int n = tc;

		cout<<"no of queens taken in main : "<<tc<<endl;
		vector<int> placed;
		nQueens(n,placed);
		cout<<endl;
	}




	return 0;
}