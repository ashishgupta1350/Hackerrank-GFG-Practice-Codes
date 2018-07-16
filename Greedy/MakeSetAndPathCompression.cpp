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

// void kruskals(int **edges, int n){



	
// }

int main()
{


	disjointSet s;
	s.makeSet(1);
	s.makeSet(2);
	s.makeSet(3);
	s.makeSet(4);
	s.makeSet(5);
	cout<<s.findSet(1);
	cout<<endl<<s.findSet(5)<<endl;
	s.Union(1,2);
	s.Union(4,5);
	cout<<s.findSet(2)<<endl;
	s.Union(1,5);
	cout<<s.findSet(5)<<endl;



	return 0;
}