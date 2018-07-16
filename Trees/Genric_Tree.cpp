#include <iostream>
using namespace std;
#define LL long long int
#define FOR(a,b,c)   for (int (a)=(b); (a)<(c); (a)++)
#define FORN(a,b,c)  for (int (a)=(b); (a)<=(c); (a)++)
#define FORD(a,b,c)  for (int (a)=(b); (a)>=(c); (a)--)
#define REP(i,n)     FOR(i,0,n)
#define REPN(i,n)    FORN(i,1,n)
#define REPD(i,n)    FORD(i,n,1)
#include<vector>
#include<queue>
template <typename T>
class TreeNode{
public:
    T data;
    vector<TreeNode*> children;

    TreeNode( T data)
    {
        this->data=data;
    }

};

// TreeNode use case

TreeNode <int>* takeInput()
{
     // recursive 
    // base case;
    //enter data, children count
    int data;
    cout<<"Enter data : ";
    cin>>data;
    
    cout<<"enter children count of "<<data<<" : ";
    int n;
    cin>>n;
    TreeNode<int>*root=new TreeNode<int>(data);
    REP(i,n){
        TreeNode <int>*child=takeInput();
        root->children.push_back(child);// that is violence right there!! Pushing around child is not good.
    }
    return root;
    
}

// Breadth First search in a tree( very easy)

void printBFS(TreeNode<int> *root)
{
    queue<TreeNode<int> *> q;
    q.push(root);
    while(!q.empty())
    {
        TreeNode<int>* head= q.front();
        q.pop();
        cout<<head->data<<" : ";
        for(int i=0;i<head->children.size();i++)
        {
            cout<<head->children[i]->data<<" ";
            q.push(head->children[i]); // this is it!
        }
        cout<<endl;
    }




}

void printTreeOrdered(TreeNode<int>* root)
{
    if(!root) return;
    cout<<root->data<<" : ";
    int n=root->children.size();
    REP(i,n){
        cout<<root->children[i]->data<<" ";
    }
    cout<<endl;
    REP(i,n)
    {
        printTreeOrdered(root->children[i]);
    }
}

void printTree(TreeNode<int>* root)
{
    if(!root) return;
    cout<<root->data<<" ";
    int n=root->children.size();
    REP(i,n)
    {
        printTree(root->children[i]);
    }
}

int main() {
	//code
    // TreeNode<int> root(10);
    // TreeNode<int> node1(20);
    // TreeNode<int> node2(30);
    // root.children.push_back(node1);

    // root.children.push_back(node2);

    TreeNode<int>*root1=takeInput();
    cout<<"Tree :: "<<endl;
    printTreeOrdered(root1);
    cout<<"Tree BFS:: "<<endl;
    printBFS(root1);
    cout<<endl;
    return 0;
}