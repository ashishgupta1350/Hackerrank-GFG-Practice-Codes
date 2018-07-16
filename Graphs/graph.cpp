#include<iostream>
using namespace std;

bool hasPath(int **edges, int n,bool *visited,int sv,int ev)
{
	if (sv==ev) return true;
	visited[sv]=true;
	for(int i=0;i<n;i++)
	{
		if(edges[sv][i]==1 && i!=sv ){
			if(!visited[i])
			{
				return hasPath(edges,n,visited,i,ev);
			}
		}
	}
	return false;
}

int main()
{
	int n;
	cin>>n;
	int **edges = new int*[n];
	for(int i=0;i<n;i++)
	{
		edges[i]=new int[n];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			edges[i][j]=0;
		}
	}
	for(int i=0;i<n;i++)
	{
		int x;
		int y;
		cout<<"enter edge : ";
		cin>>x>>y;
		edges[x][y]=1;
		edges[y][x]=1;
	}
	// this completes out graph creation
	bool *visited=new bool[n];
	for(int i=0;i<n;i++)
	{
		visited[i]=false;

	}
	cout<<hasPath(edges,n,visited,2,5);



	return 0;
}