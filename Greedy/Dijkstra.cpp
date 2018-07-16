#include<bits/stdc++.h>
using namespace std;

#include<climits>

			// relax(minVert,i,d,visited,myMap,edges);


void printMap(map<int,int>myMap)
{
	//nothing
}

void relax(int u,int v,int *d,bool*visited,map<int,int> myMap,int **edges)
{
	if(d[u]+edges[u][v]<d[v])
	{
		//updating the distance to the required value
		d[v]=d[u]+edges[u][v];
		myMap[v]=u;
	}
	return;
}
void relax(int u,int v,int *d,int **edges)
{
	if(d[u]+edges[u][v]<d[v])
	{
		//updating the distance to the required value
		d[v]=d[u]+edges[u][v];
		// myMap[v]=u;
	}
	return;
}


void dijkstra(int **edges,int n,int sv,bool *visited,int *d,map<int,int>myMap,vector<pair<int,int>> v)
{
	// v is the vector containing the pairs
	int minVert=-1;
	int minDist=INT_MAX;
	for(int i=0;i<n;i++)
	{
		if(!visited[v[i].first])
		{
			if(v[i].second<minDist)
			{
				minDist=v[i].second;
				minVert=v[i].first;
			}
		}
	}
	visited[minVert]=true;
	if(minVert==-1){
		printMap(myMap);
		// do the operations 
		return;
	}
	for(int i=0;i<n;i++)
	{
		if(edges[minVert][i]>=0 && !visited[i])
		{
			relax(minVert,i,d,visited,myMap,edges);
		}
	}

}

bool bellmanFord(int **edges,int n,int sv,bool *visited,int *d,map<int,int>myMap,vector<pair<int,int>> v)
{
	for(int i=0;i<n-1;i++)
	{

		for(int j=0;j<n;j++)
		{
			for(int k=0;k<n;k++)
			{
				if(edges[j][k]!=INT_MIN)
				{
					relax(j,k,d,edges);
				}
			}
		}

	}
	for(int j=0;j<n;j++)
		{
			for(int k=0;k<n;k++)
			{
				if(edges[j][k]!=INT_MIN && d[j]+edges[j][k]<d[k])
					return false;
			}
		}
	return true;
}

int main()
{
	int n,e;
	cout<<"Enter vertices count and edge count: " ;
	cin>>n>>e;
	int **edges=new int *[n];
	bool*visited=new bool[n];
	int *d=new int[n];
	map<int,int> myMap;//=new map<int,int>;
	vector<pair<int,int>> v;//=new vector<pair<int,int>>;
	
	for(int i=0;i<n;i++)
	{
		edges[i]=new int[n];
		visited[i]=false;
		d[i]=INT_MAX;

	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			edges[i][j]=INT_MIN;
		}
	}
	cout<<"Enter the edges: "<<endl;
	for(int i=0;i<e;i++){
		int u,v,w;
		cout<<"enter u,v,w: ";
		cin>>u>>v>>w;
		if(u>=n ||v>=n){
			cout<<"Invalid input! Enter again!"<<endl;
			i--;
			continue;
		}
		edges[u][v]=w;
		
	}
	int sv;
	cout<<"enter sv : ";
	cin>>sv;
	d[sv]=0;
	for(int i=0;i<n;i++)
	{
		pair<int,int> p(i,d[i]);
		v.push_back(p);
	}
	// dijkstra(edges,n,sv,visited,d,myMap,v);
	cout<<bellmanFord(edges,n,sv,visited,d,myMap,v)<<endl;
	if(bellmanFord(edges,n,sv,visited,d,myMap,v)==true)
		for(int i=0;i<n;i++)
		{
			cout<<i<<" : "<<d[i]<<endl;
		}
	return 0;

}