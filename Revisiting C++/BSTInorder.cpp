#include<bits/stdc++.h>
using namespace std;
class treeNode{
public:
	int data;
	treeNode*left;
	treeNode*right;
	treeNode(int data)
	{
		this->data=data;
		this->left=NULL;
		this->right=NULL;
	}

};
int inorderSuccessor(treeNode*root,int data , stack<pair<treeNode *,bool>> &s)
{
	if(root==NULL)
	{
		return -1; // we didnot even find the data
	}
	if(root->data==data)
	{
		// there are 2 options

		if(root->right!=NULL)
		{
			treeNode* temp=root->right;
			while(temp->left!=NULL)
			{
				temp=temp->left;
			}
			return temp->data;
		}
		else{
			while(!s.empty() && s.top().second==1)
			{
				s.pop();
			}
			if(s.empty())
			{
				return -1;
			}
			else{
				return s.top().first->data;// that means , on this root, we went left, so print its data
			}

		}

	}
	else if(root->data>data)
	{
		pair<treeNode *,bool> p(root,false);
		s.push(p);
		return inorderSuccessor(root->left,data,s);
	}
	else 
	{
		pair<treeNode*,bool> p(root,true);
		s.push(p);
		return inorderSuccessor(root->right,data,s);
	}

}
int main()
{
	treeNode *root=new treeNode(10);
	treeNode *left=new treeNode(5);
	treeNode *right=new treeNode(13);
	root->left=left;
	root->right=right;
	left=new treeNode(1);
	right=new treeNode(6);
	root->left->left=left;
	root->left->right=right;

	root->right->right=new treeNode(27);
	stack<pair<treeNode*,bool>> s;
	cout<<inorderSuccessor(root,6,s);
	return 0;

}