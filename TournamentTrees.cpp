#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#include<list>
class Node{
public:
	int idx;
	Node*left;
	Node*right;
	Node(int idx)
	{
		this->idx=idx;
		this->left=NULL;
		this->right=NULL;
	}

};
Node* createNode(int idx)
{
	Node*n=new Node(idx);
	return n; 
}
// we have an array of size n. We have to make a tree
// we first create the first level of the tree and push
// it into the list, then while lists size is not 1, we continue 
// to pop the list 2 elements at a time and make new nodes. These Nodes are
// again pushed to the list

void getSecondMinimum(Node*root,int *arr,int &res)
{
	if(!root ||(root->left==NULL and root->right==NULL)) return; // there cant be any second maximim is this thing
	// ans is 
	if(arr[root->left->idx]<res && arr[root->idx]!=arr[root->left->idx])
	{
		res=arr[root->left->idx];
		getSecondMinimum(root->left,arr,res);
	}
	else if(arr[root->right->idx]<res && arr[root->idx]!=arr[root->right->idx])
	{
		res=arr[root->right->idx];
		getSecondMinimum(root->right,arr,res);
	}
	return;
}
void findSecondMinimim(int *arr,int n)
{
	list<Node*> li;
	Node*root=NULL;

	for(int i=0;i<n;i+=2)
	{

		Node*a=createNode(i);
		Node*b=NULL;
		if(i+1<n)
		{
			b=createNode(i+1);
			root=(arr[a->idx]<arr[b->idx])? createNode(a->idx): createNode(b->idx);
			root->left=a;
			root->right=b;
			cout<<arr[root->idx]<<endl;
			li.push_back(root);
		}
		else{
			li.push_back(a);
		}

	}
	int lsize=li.size();
	while(lsize!=1)
	{
		// get the last index of the list
		// for odd lists
		int last=0;
		if(lsize&1) last=lsize-2;
		else last= lsize-1;
		for(int i=0;i<last;i+=2)
		{
			Node*a=li.front();
			li.pop_front();
			Node*b=li.front();
			li.pop_front();
			root=(arr[a->idx]<arr[b->idx])? createNode(a->idx):createNode(b->idx);
			root->left=a;
			root->right=b;
			li.push_back(root);
		}
		if(lsize & 1)// if the list size was odd, then place the top node at the last 
		{
			Node*a=li.front();
			li.pop_front();
			li.push_back(a);
		}
		lsize=li.size();
	}

	// the minimum of the array is 
	int res=INT_MAX;
	cout<<"minimum : "<<arr[root->idx]<<endl;
	getSecondMinimum(root,arr,res);
	cout<<"second Minimim: "<<res<<endl;
}


int main()
{
	// for(int i=2;i<10;i++)
	// {
	// 	cout<<i<<" & "<<1<<" is : "<<(i & 1)<<endl;
	// }
	int arr[] = {61, 6, 100, 9, 10, 12,1, 17};
	int n=sizeof(arr)/sizeof(arr[0]);
	findSecondMinimim(arr,n);


	return 0;
}