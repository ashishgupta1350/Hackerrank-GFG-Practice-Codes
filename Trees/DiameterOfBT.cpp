#include<iostream>
using namespace std;
#define LL long long int
#define FOR(a,b,c)   for (int (a)=(b); (a)<(c); (a)++)
#define FORN(a,b,c)  for (int (a)=(b); (a)<=(c); (a)++)
#define FORD(a,b,c)  for (int (a)=(b); (a)>=(c); (a)--)
#define REP(i,n)     FOR(i,0,n)
#define REPN(i,n)    FORN(i,1,n)
#define REPD(i,n)    FORD(i,n,1)
#include<stack>
template<typename T>
class BTNode{
public:
	T data;
	BTNode<T> *left;
	BTNode<T> *right;
	bool visited;
	BTNode(T data)
	{
		this->data=data;
		this->left=left;
		this->right=right;	
		this->visited=false;
	}
};

BTNode<int>* takeInput()
{
	int data;
	cout<<"data: ";
	cin>>data;
	if(data==-1)
	{
		return NULL;
	}
	// create a BTNode
	BTNode<int>* root= new BTNode<int> (data);
	cout<<" Enter Left of data "<<data<<" ";
	root->left=takeInput();
	cout<<" Enter Right of data "<<data<<" ";
	root->right=takeInput();
	return root;
}

void print(BTNode<int>* root)
{
	if(! root) return ;
	//else 
	cout<<root->data<<" : ";
	if(root->left){
		cout<<" L "<<root->left->data;
	}
	if(root->right)
	{
		cout<<" R "<<root->right->data;
	}
	cout<<endl;
	print(root->left);
	print(root->right);
	return;
}

BTNode<int> * makeTree(){
	BTNode<int> *root=new BTNode<int> (10);// construct a tree
	BTNode<int> *root1=new BTNode<int> (20);// construct a tree
	BTNode<int> *root2=new BTNode<int> (30);// construct a tree
	BTNode<int> *root3=new BTNode<int> (40);// construct a tree
	BTNode<int> *root4=new BTNode<int> (50);// construct a tree
	root->left=root1;
	root->right=root2;
	root1->left=root3;
	root1->right=root4;
	return root;
}


int height( BTNode<int>* root)
{
	if(! root) return 0;
	return 1+max(height(root->left) ,  height(root->right));
}

int diameter(BTNode<int> * root)
{
	if (root==NULL) return 0;
	int d1=diameter(root->left);
	int d2=diameter(root->right);
	int h1=height(root->left);
	int h2=height(root->right);
	int h=h1+h2;// is the main diameter passing through the root

	if(h>max(d1,d2)){
		return h;
	}
	else{
		return max(d1,d2);
	}
	cout<<"here<";

}


/// CODE IS WORKING, THE MAIN FUNCTION IS NOT WORKING FOR SOME REASON.


int main()
{
	
    BTNode<int> *root=makeTree();
 //    BTNode<int> *root=new BTNode<int> (10);// construct a tree
	// BTNode<int> *root1=new BTNode<int> (20);// construct a tree
	// BTNode<int> *root2=new BTNode<int> (30);// construct a tree
	// BTNode<int> *root3=new BTNode<int> (40);// construct a tree
	// BTNode<int> *root4=new BTNode<int> (50);// construct a tree
	// root->left=root1;
	// root->right=root2;
	// root1->left=root3;
	// root1->right=root4;
	// cout<<"here"<<endl;

	if(root!=NULL)
    	cout<<height(root)<<endl;
    else{ 
    	cout<<"root is null"<<endl;}

}