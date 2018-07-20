#include<iostream>
using namespace std;
#include<vector>
// class matrix{
// public:
// 	int row;int col;int **mat;
// 	matrix(int row,int col)
// 	{
// 		mat=new int*[row];
// 		for(int i=0;i<row;i++)
// 		{
// 			mat[i]=new int [col];
// 		}
// 	}

// 	void input()
// 	{
// 		for(int i=0;i<row;i++)
// 		{
// 			for(int j=0;j<col;j++)
// 			{
// 				cin>>matrix[i][j];
// 			}
// 		}
// 	}
// 	int determinantHelper(int **mat,int n,int row,vector<int> skipList)
// 	{

// 	}
// 	int determinant()
// 	{

// 	}

// 	~matrix()
// 	{

// 	}
// };

int getCol(vector<int> skipList,int n)
{
	int col=-1;
	int arr[n];
	for(int i=0;i<n;i++)
	{
		arr[i]=0;
	}
	for(int i=0;i<skipList.size();i++)
	{
		arr[skipList[i]]++; // array of skipped column + =1;
	}
	for(int i=0;i<n;i++)
	{
		if(arr[i]==0) return i;
	}
	return -1;
}

bool checkCol(vector<int> skipList,int n,int col)
{
	for(int i=0;i<skipList.size();i++)
	{
		if(skipList[i]==col) return false;
	}
	return true;

}
int determinant(int **mat,int n, int row,vector<int> &skipList)
{
	if(n==0) return 0;
	if(skipList.size()==n-1)
	{
		int col= getCol(skipList,n);
		return mat[row][col];
	}
	int det=0;
	int mult=1;
	for(int col=0;col<n;col++)
	{
		if(checkCol(skipList,n,col))// if the col is valid
		{
			skipList.push_back(col);
			det+=mat[row][col] * mult*determinant(mat,n,row+1,skipList);
			mult*=-1;
			skipList.pop_back();
		}
	}
	return det;

}

int main()
{
	int **mat;
	int row=2;int col=2;
	int n;
	mat=new int*[row];
	for(int i=0;i<row;i++)
	{
		mat[i]=new int[col];
	}
	mat[0][0]=5;
	mat[1][0]=2;
	mat[0][1]=20;
	mat[1][1]=4;
	n=min(row,col);
	vector<int> skipList;
	cout<<determinant(mat,n,0,skipList);
	return 0;


}