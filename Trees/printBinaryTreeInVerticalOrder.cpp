{
#include <bits/stdc++.h>
using namespace std;
/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};
void verticalOrder(Node *root);
/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
struct Node* newNode(int data)
{
  struct Node* node = (struct Node*)
                       malloc(sizeof(struct Node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return(node);
}
/* Driver program to test size function*/
int main()
{
  int t;
  struct Node *child;
  scanf("%d
", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d
",&n);
     struct Node *root = NULL;
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);
        if (m.find(n1) == m.end())
        {
           parent = newNode(n1);
           m[n1] = parent;
           if (root == NULL)
             root = parent;
        }
        else
           parent = m[n1];
        child = newNode(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
     }
     verticalOrder(root);
     cout << endl;
  }
  return 0;
}

}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* A binary tree node has data, pointer to left child
   and a pointer to right child 
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */
/* Should print vertical order such that each vertical line
   is separated by $ */
#include<algorithm>
void verticalOrderHelper(Node* root,int right,vector<pair<Node*,int>> &v ){
    if(root==NULL) return ;
    pair<Node*,int> p(root,right);
    v.push_back(p);
    verticalOrderHelper(root->left,right-1,v);
    verticalOrderHelper(root->right,right+1,v);
    return;
    
}
bool sortbysec(const pair<Node*,int> &a,
              const pair<Node*,int> &b)
{
    return (a.second < b.second);
}

void verticalOrder(Node *root)
{
    //Your code here
    vector<pair<Node*,int>> v;
    int right=0;
    verticalOrderHelper(root,right,v);
    // sort the vector on the basis of the second value of the vector<pair>
    int n=v.size();
    sort(v.begin(),v.end(),sortbysec)
    for(int i=0;i<n;i++)
    {
        cout<<v[i].second<<" ";
    }
    cout<<endl;
    return;
    
    
    
}