#include <iostream>
using namespace std;
#define LL long long int
#define FOR(a,b,c)   for (int (a)=(b); (a)<(c); (a)++)
#define FORN(a,b,c)  for (int (a)=(b); (a)<=(c); (a)++)
#define FORD(a,b,c)  for (int (a)=(b); (a)>=(c); (a)--)
#define REP(i,n)     FOR(i,0,n)
#define REPN(i,n)    FORN(i,1,n)
#define REPD(i,n)    FORD(i,n,1)
#include"treeNodeClass.h"
#include<stack>
void inorder(TreeNode<int>*root)
{
    stack <TreeNode<int> *> s;
    s.push(root);
    while(!s.empty())
    {
        TreeNode<int> * a=s.top();
        while(!a->left==NULL){
            s.push(a->left);
            a=a->left;
        }
        cout<<a->data<<" ";
        s.pop();
        if(a->right!=NULL)
        {
            s.push(a->right);

        }
    }

    cout<<endl;
    return;
}

int main() {
	//code
	
	


	return 0;
}