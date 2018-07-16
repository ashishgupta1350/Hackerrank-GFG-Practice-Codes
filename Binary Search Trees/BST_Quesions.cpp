#include<iostream>
using namespace std;
template <typename T>
class BTNode{
public:
	T data;
	BTNode<int> *left;
	BTNode<int> *right;

	BTNode(T data)
	{
		this->data=data;
		this->left=NULL;
		this->right=NULL;

	}
};
void printElementsBetween(BTNode<int> *root,int k1,int k2)
{
	if(! root) return;
	// if(root->data==k1 || root->data==k2){
	// 	cout<<
	// }
	if(root->data<k1)
	{
		printElementsBetween(root->right,k1,k2);
	}
	else if(root->data>k2)
	{
		printElementsBetween(root->left,k1,k2);
	}
	else if(root->data>k1 && root->data<k2){
		cout<<root->data<<" ";
		printElementsBetween(root->left,k1,root->data);
		printElementsBetween(root->right,root->data,k2);
		return;
	}

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
 
class IsBSTMaxMin{
	public:

	int Max;
	int Min;
	bool isBST;
	IsBSTMaxMin(int Max, int Min, bool isBST=true){
		this->Max=Max; this->Min=Min;
		this->isBST=isBST;
	}

};
// O(n) is the complexity of the solution.
IsBSTMaxMin checkBSTHelper(BTNode<int> *root){
	if(root==NULL){
		IsBSTMaxMin retClass(INT_MIN, INT_MAX,true);
		return retClass;
	}
	IsBSTMaxMin left=checkBSTHelper(root->left);
	IsBSTMaxMin right=checkBSTHelper(root->right);
	if(left.isBST && right.isBST && left.Max<root->data && right.Min>=root->data){
		// update the class values and return your answer.
		// make a class variable:
		IsBSTMaxMin result(1,2,true);// initialzied with garbage type values
		result.isBST=true;
		result.Min=min(min(left.Min,right.Min),root->data);
		result.Max=min(min(left.Max,right.Max),root->data);
		return result;
	}
	else{
		IsBSTMaxMin result(1,2,true);// initialzied with garbage type values
		result.isBST=false;
		result.Min=min(min(left.Min,right.Min),root->data);
		result.Max=min(min(left.Max,right.Max),root->data);
		return result;

	}

}

class LLNode{
public:
	int data;
	LLNode*left;
	LLNode(int data)
	{
		this->data=data;

	}
}
// preorder traversal and construct a sorted LL from this 
LLNode createLL(BTNode<int> *root)
{
	if(root== NU)
}

 bool checkBST(BTNode<int> *root){
 	if (root==NULL) return true;
 	IsBSTMaxMin ans= checkBSTHelper(root);
 	return ans.isBST;
 }

int main()
{
	// premade bst here
	BTNode<int> *root=new BTNode<int>(10);
	BTNode<int> *root1=new BTNode<int>(5);
	BTNode<int> *root2=new BTNode<int>(4);
	BTNode<int> *root3=new BTNode<int>(6);
	BTNode<int> *root4=new BTNode<int>(15);
	BTNode<int> *root5=new BTNode<int>(19);
	root->left=root1;
	root->right=root0;
	root4->right=root5;
	root1->left=root2;
	root1->right=root3;
	printElementsBetween(root,0,20);
	cout<<endl;
	cout<<" printing Check BST : ";
	if(checkBST(root)==true) cout<< "true";
	else cout<< "false";
	cout<<endl;

	return 0;
}