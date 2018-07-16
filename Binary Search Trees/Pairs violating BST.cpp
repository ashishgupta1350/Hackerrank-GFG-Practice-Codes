

//Author- Sajal Agrawal
//sajal.agrawal1997@gmail.com
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
int indx,ans;
struct Node{
    int data;
    Node *left,*right;
    Node(int d){
        data=d;
        left=right=NULL;
    }
};
int pairsViolatingBST(Node *root,int n);
void insert(Node *root,int a,int b,char ch);
int main() {
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
    indx=0;
    ans=0;
        Node *root=NULL;
        for(int j=0;j<n;j++){
            int a,b;
            char ch;
            cin>>a>>b>>ch;
            if(root==NULL){
                root=new Node(a);
                switch(ch){
                    case 'L':root->left=new Node(b);
                            break;
                    case 'R':root->right=new Node(b);
                            break;
                }
            }else{
                insert(root,a,b,ch);
            }
        }
    cout<<pairsViolatingBST(root,n)<<" ";
    }
  return 0;
}
void insert(Node *root,int a,int b,char ch){
    if(root==NULL)return;
    if(root->data==a){
        switch(ch){
            case 'L':root->left=new Node(b);
                    break;
            case 'R':root->right=new Node(b);
                    break;
        }
    }else{
        insert(root->left,a,b,ch);
        insert(root->right,a,b,ch);
    }
}






// struct Node{
//     int data;
//     Node *left,*right;
//     Node(int d){
//         data=d;
//         left=right=NULL;
//     }
// }; 

#include<vector>

void inOrder(Node*root,vector<int>* v)
{
    if(!root) return;
    inOrder(root->left,v);
    v->push_back(root->data);
    inOrder(root->right,v);
    return;
}

int pairsViolatingBST(Node *root,int n){
          /*Your code here */
          vector<int> *v= new vector<int>;
          inOrder(root,v);
          // vector is ready
        //   pair<int,int>
        //   vector<pair<int,int>>vp;
          int count=0;
          for(int i=0;i<n;i++)
          {
              for(int j=i+1;j<v->size();j++)
              {
                  if(v[i]>v[j])
                  {
                      count++;
                    //   pair<int,int> p(v[i],v[j]);
                    //   vp.push_back(p);
                  }
              }
          }
          return count;
}