// for a tree and a given node n, find the sum of nodes distance k away
#include<iostream>
using namespace std;
class Node{
public:
	int data;Node* left;Node* right;
	Node(int data=0)
	{
		this->data=data;
		this->left=NULL;
		this->right=NULL;
	}
};

void getNodesAtK(Node*root,int k,int &sum)
{
	if(root==NULL or k<0) return;
	if(k==0)
	{
		sum+=root->data;
	}
	getNodesAtK(root->left,k-1,sum);
	getNodesAtK(root->right,k-1,sum);
}
int sum=0;


int getSum(Node* root,int k,int n)
{

	//go till n
	if(root==NULL) return -1;

	else if(root->data==n)
	{
		getNodesAtK(root,k,sum);
		return 0;
	}
	int x=getSum(root->left, k, n);
	if(x!=-1)
	{
		if(1+x==k)
		{
			sum+=root->data;
		}
		else if(1+x<=k)
		{
			getNodesAtK(root->right,k-1-x,sum);
		}
		return 1+x;
	}
	int y=getSum(root->right, k, n);
	if(y!=-1)
	{
		if(1+y==k)
		{
			sum+=root->data;
		}
		else if(1+x<=k)
		{
			getNodesAtK(root->left,k-1-y,sum);
		}
		return 1+y;
	}
	return -1;

}

int main()
{

	int n;
	cin>>n;
	int k;cin>>k;
	// construct tree
	Node*root=new Node(10);
	Node*a=new Node(20);
	Node*b=new Node(30);
	Node*c=new Node(40);
	root->left=a;
	root->right=b;
	a->left=c;

	getSum(root,k,n);
	cout<<sum<<endl;


}