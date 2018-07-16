#include<bits/stdc++.h>
using namespace std;

class Node{
public:
	int data;
	int rank;
	Node* parent;
	Node(int data){
		this->data=data;
		this->parent=this;
		this->rank=0;
	}

};

class disjointSet{
private:
	map<int,Node*> Map;
public:
	// gets data , makes a new node, and enters data, sets parent as parent and rank as zero. It is called only in the start of the algorithm

	void makeSet(int data)
	{
		Node*node=new Node(data);
		node->data=data;
		node->parent=node;
		node->rank=0;
		Map[data]=node;
	}

	void Union(int data1,int data2){
		Node*node1=Map[data1];
		Node*node2=Map[data2];
		Node* parent1=findSet(node1);
		Node* parent2=findSet(node2);
		if(parent1->data==parent2->data)
		{
			return ;
		}
		else if(parent1->rank>=parent2->rank){
			parent1->rank+=1;
			parent2->rank=0;
			parent2->parent=parent1;
		}
		else{
			parent2->rank+=1;
			parent1->rank=0;
			parent1->parent=parent2;
		}
		return;
	}
	int findSet(int data) // this function is overloaded 1 times so
	{
		return findSet(Map[data])->data;// returns parent->data
	}

	Node* findSet(Node*node)
	{
		Node*parent=node->parent;
		if(parent==node) return node;
		node->parent=findSet(node->parent); // path compression. So recursive function finds the parent of the node. We do the work non recursive for the root. we call the recursive function and ask them to bring me the parent, and we link the node to the parent and return the root's parent.
		return node->parent;
	}
};

class triple{
public:
	int first;
	int second;
	int third;
	triple(int f,int s,int t)
	{
		this->first=f;
		this->second=s;
		this->third=t;

	}
};

class comparitor{

public:
	bool operator()(const triple &t1,const triple &t2) 
	{
		return t1.third>t2.third;
	}

};



void kruskals(int **edges, int n){
	disjointSet s;
	priority_queue<triple,vector<triple>,comparitor> minHeap;
	for(int i=0;i<n;i++)
	{
		s.makeSet(i);
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(edges[i][j]!=INT_MIN)
			{
				// cout<<"creating pair : "<<i<<" and "<<j<<endl;
				triple t(i,j,edges[i][j]);
				minHeap.push(t);
			}
		}
	}
	int sum=0;
	while(!minHeap.empty())
	{
		// cout<<"here"<<endl;
		triple t=minHeap.top();
		minHeap.pop();
		int parent1=s.findSet(t.first);
		int parent2=s.findSet(t.second);
		if(parent1==parent2)
		{
			continue;
		}
		else{
			s.Union(t.first,t.second);
			cout<<t.first<< " -> "<<t.second<<endl;
			sum+=t.third;

		}
	}
cout<<sum<<endl;
	
}

int main()
{


	// disjointSet s;
	// s.makeSet(1);
	// s.makeSet(2);
	// s.makeSet(3);
	// s.makeSet(4);
	// s.makeSet(5);
	// cout<<s.findSet(1);
	// cout<<endl<<s.findSet(5)<<endl;
	// s.Union(1,2);
	// s.Union(4,5);
	// cout<<s.findSet(2)<<endl;
	// s.Union(1,5);
	// cout<<s.findSet(5)<<endl;
	int n,e;
	// cout<<"Enter vertices count and edge count: " ;
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
	// cout<<"Enter the edges: "<<endl;
	for(int i=0;i<e;i++){
		int u,v,w;
		// cout<<"enter u,v,w: ";
		cin>>u>>v>>w;
		if(u>=n ||v>=n){
			cout<<"Invalid input! Enter again!"<<endl;
			i--;
			continue;
		}
		edges[u][v]=w;
		
	}

	kruskals(edges,n);


	return 0;
}