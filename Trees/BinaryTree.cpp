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

int height( BTNode<int>* root)
{
	if(! root) return 0;
	return 1+max(height(root->left) ,  height(root->right));
}

void mirror(BTNode<int>* root)
{
	if(!root) return ;
	mirror(root->left);
	mirror(root->right);
	swap(root->left,root->right);
	return ;
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

void inorder(BTNode<int>*root)
{
    stack <BTNode<int> *> s;
    s.push(root);
    BTNode<int> * a=root;
    while(1)
    {        
        while(a!=NULL){
        	
            s.push(a);
            a=a->left;
        }
        if(!s.empty())
        {
        	a=s.top();
        	s.pop();
        	cout<<a->data<<" ";
        }
       else{
       	break;
       }
        if(a->right!=NULL)
        {
            s.push(a->right);

        }
    }

    cout<<endl;
    return;
}

BTNode<int> * makeTree(){
	BTNode<int> *root=new BTNode<int> (10);// construct a tree
	BTNode<int> *root1=new BTNode<int> (10);// construct a tree
	BTNode<int> *root2=new BTNode<int> (10);// construct a tree
	BTNode<int> *root3=new BTNode<int> (10);// construct a tree
	BTNode<int> *root4=new BTNode<int> (10);// construct a tree
	root->left=root1;
	root->right=root2;
	root1->left=root3;
	root1->right=root4;
	return root;
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

}

bool printAncestors(BTNode<int> *root,int key)
{
	if(root==NULL) return false;
	if(root->data==key) {
		//cout<<"root->key"<<" ";
		return true;
	}
	if(printAncestors(root->left,key)){
		cout<<root->data<<" ";
		return true;
	}
	else if(printAncestors(root->right,key)){
		cout<<root->data<<" ";
		return true;
	}
	return false;


}


bool checkIdentical(BTNode<int> *root1, BTNode<int> *root2)
{
	if(root1==NULL && root2==NULL) return true;
	if(root1==NULL && root2!=NULL) return false;
	else if(root1!=NULL && root2==NULL) return false;
	else{
		if(root1->data==root2->data){
			bool isTrue1=checkIdentical(root1->left,root2->left);
			if(isTrue1){
				bool isTrue2=checkIdentical(root1->right,root2->right);
				if (isTrue2){
					return true;
				}

				else return false;
				}
		}
		else return false;
		}
	return false;	
}


bool checkSubtreeWithinTree(BTNode<int> *root1, BTNode<int> *root2)
{
	if(root1==NULL && root2==NULL) return true;
	if(checkIdentical(root1,root2)){
		return true;
	}
	else{
		bool true1=checkSubtreeWithinTree(root1->left,root2);
		if(true1) return true;

		bool true2=checkSubtreeWithinTree(root1->right,root2);
		if(true2) return true;

		return false;
	}
	return false;
}



int main() {
	//code
	
	// int tc;
 //    // cout << "enter tc : ";
 //    cin >> tc;
 //    for (int i = 0; i < tc; i++) {
    
 //    	int n;
 //    	cin >> n;
 //    	int *arr = new int[n];
 //    	for (int i = 0; i < n; i++)
 //    	{
 //    		cin >> arr[i];
 //    	}
    // }
    BTNode<int> *root=takeInput();
    // print(root);
    // mirror(root);
    // print(root);
    cout<<endl;
    cout<<"diameter:: "<<endl;
    cout<<diameter(root)<<endl;

    cout<<"printAncestors:: "<<endl;
    if(printAncestors(root,5)){
    	cout<<endl;
    }
    else cout<<"No key found"<<endl;
	return 0;
}