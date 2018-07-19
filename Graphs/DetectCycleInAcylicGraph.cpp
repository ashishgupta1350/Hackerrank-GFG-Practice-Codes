#include<bits/stdc++.h>
using namespace std;

void printThe(stack<int> s)
{
	cout<<"Found Cycle: ";
	while(!s.empty())
	{
		cout<<s.top()<<" ";
		s.pop();
	}
	return;
}

/*
4
4
1 2
2
3
3 4
4 1
currentVertex is : 1
neighbour is : 1
neighbour is : 2
currentVertex is : 2
neighbour is : 1
Found Cycle: 1 2 1 neighbour is : 3
neighbour is : 4
currentVertex is : 4
neighbour is : 1
Found Cycle: 1 4 2 1
*/
void detectCycleInAcyclicGraph(bool **edges,int n,int currentVertex,bool*visited,stack<int> &s,int parent) // current vertex is 1 
{
	if(visited[currentVertex]) return;
	// cout<<"currentVertex is : "<<currentVertex<<endl;
	visited[currentVertex]=true;
	s.push(currentVertex);
	for(int i=1;i<=n;i++)
	{
		// cout<<"neighbour is : "<<i<<endl;

		if(edges[currentVertex][i]==true && i!=currentVertex && i!=parent)
		{
			if(visited[i]) {s.push(i);printThe(s); s.pop();return;}
			else{
				// s.push(i);
				detectCycleInAcyclicGraph(edges,n,i,visited,s,currentVertex);
				// s.pop();
			}

		}
	}
	s.pop();
	return;


}

int main()
{
	bool **edges;
	int v;
	int e;
	cin>>v>>e;
	edges=new bool*[v+1];
	for(int i=0;i<=v;i++)
	{
		edges[i]=new bool[v+1];
	}
	for(int i=1;i<=v;i++)
	{
		for(int j=1;j<=v;j++)
		{
			edges[i][j]=false;
		}
	}
	for(int i=0;i<e;i++) // v is n is no. of vertices to enter
	{
		int x;
		int y; // enter x y point representing vertex to vertex edge
		cin>>x>>y;
		if(x<=0 || x>v ||y <=0 || y>v)
		{
			cout<<"Incorrect vertex encountered. Please enter again!"<<endl;
			i--;
			continue;
		}
		edges[x][y]=true;edges[y][x]=true;
	}
	bool *visited=new bool[v+1];
	for(int i=0;i<=v;i++)
	{
		visited[i]=false;
	}
	stack<int> s;
	detectCycleInAcyclicGraph(edges,v,1,visited,s,-1); // current vertex is 1 



}