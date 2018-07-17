#include<iostream>
using namespace std;

class Node{
public:
	int data;
	Node*left;
	Node*right;
	int lh;
	int rh;// left subtree and right subtree heights

	Node(int data, int lh=0,int rh=0)
	{
		this->data=data;
		this->lh=lh;
		this->rh=rh;
	}
};

class AVL{
	public:
	Node*root; // root pointer
	int numNodes;
	AVL()
	{
		this->root=NULL;
		this->numNodes=0;
	}
	// left rotate and right rotate are private functions

// private:
	int height(Node*root)
	{
		if(!root) return 0;
		else return 1+max(root->lh, root->rh);// 1 for single node
	}
	Node* leftRotate(Node* root)
	{
		// this is why this->root is so important.
		Node*newRoot=root->right;// root is local to this function
		root->right=newRoot->left;
		newRoot->left=root;
		root->lh=height(root->left);
		root->rh=height(root->right);
		newRoot->lh=height(newRoot->left); // new root height depends on root's height, not vica versa
		newRoot->rh=height(newRoot->right);
		return newRoot;
	}

	Node* rightRotate(Node* root)
	{
		// this is why this->root is so important.
		Node*newRoot=root->left;// root is local to this function
		root->left=newRoot->right;
		newRoot->right=root;
		root->lh=height(root->left);
		root->rh=height(root->right);
		newRoot->lh=height(newRoot->left); // new root height depends on root's height, not vica versa
		newRoot->rh=height(newRoot->right);
		return newRoot;

	}
public:
	Node* insert(Node* root, int data)
	{
		// cout<<"here";
		// if(root) cout<<root->data<<" : is root->data and "<<data<<" is data to insert"<<endl;
		if(!root) return new Node(data,0,0);
		


		if(data<root->data)
		{
			root->left=insert(root->left,data);
		}
		else{
			root->right=insert(root->right,data);
		}
		int lh=height(root->left);
		int rh=height(root->right);
		cout<<data<<":  after calculating heights"<<endl;
		if(lh-rh > 1)
		{
			// ll insertion
			if(root->left->data>data)
			{
				root=rightRotate(root);
			}
			else{
				// LR rotation
				root->left=leftRotate(root->left);
				root=rightRotate(root);
			}
		}
		else if(rh-lh > 1)
		{
			if(root->right->data < data)
			{
				root= leftRotate(root);
			}
			else{
				root->right=rightRotate(root->right);
				root=leftRotate(root);

			}
		}
		root->lh=height(root->left);
		root->rh= height(root->right);
		cout<<"left and right heights are: "<<root->lh<<" "<<root->rh<<endl;

		return root;
	}
	void insert_avl(int data)
	{
		// cout<<"here";
		this->root=insert(this->root,data);
	}

};

int main(){

	AVL t;
	t.insert_avl(10);
	 t.insert_avl(20);
	t.insert_avl(30);
	cout<<"The head node is "<<t.root->data<<endl;
	t.insert_avl(5);
	cout<<"The head node is "<<t.root->data<<endl;
	t.insert_avl(3);
	cout<<"The head node is "<<t.root->data<<endl;

	// t.insert(25);
	t.insert_avl(1);
	cout<<"The head node is "<<t.root->data<<endl;

	cout<<t.height(t.root)<<endl;// this is working fine.
	// the ans is correct. the implementation of AVL is successful :D 

	return 0;

}