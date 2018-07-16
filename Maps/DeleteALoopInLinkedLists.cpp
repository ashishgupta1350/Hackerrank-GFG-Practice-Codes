// #include<bits/stdc++.h>
//  using namespace std;
// /* Link list Node */
// struct Node
// {
//     int data;
//     struct Node* next;
// };
//  vector<int> _A_;
//  void removeLoop(struct Node *, struct Node *);
//  void removeTheLoop(Node *);
// void push(struct Node** head_ref, int new_data)
// {
//     /* allocate Node */
//     struct Node* new_Node =
//           (struct Node*) malloc(sizeof(struct Node));
 
//     /* put in the data  */
//     new_Node->data  = new_data;
 
//     /* link the old list off the new Node */
//     new_Node->next = (*head_ref);
 
//     /* move the head to point to the new Node */
//     (*head_ref)    = new_Node;
// }
// void removeTheLoop(struct Node *list);
// int __detectloop(struct Node *list)
// {
//     struct Node  *slow_p = list, *fast_p = list;
//     bool fA=0;
//     bool fB =0;
//     while (slow_p && fast_p && fast_p->next )
//     {
//         slow_p = slow_p->next;
//         fast_p  = fast_p->next->next;
//         if (slow_p == fast_p)
//         {
//            fA=1;
//         }
//     }
    
//     //Check for valid list
    
    
    
//     if(fA)
//     return 1;
//     else 
//     return 0;
// }

// #include<map>
// void removeTheLoop(Node *node)
// {
//      //identify the loop and kill it.
//      map<Node*, bool> myMap;
//      Node*temp=node;
//      Node* prev=NULL;
//      while(temp!=NULL && myMap[temp]!=false)
//      {
//          prev=temp;
//          myMap[temp]=true;
//          temp=temp->next;
//      }
//      if(temp!=NULL and prev!=NULL){ // it may happen that the ll didnt have a loop. in that case return the head, which in this case  is the node, else remove the pointer pointing to the repeated node:)
//          prev->next=NULL;
//      }
//      return ;
// }

#include<iostream>
using namespace std;
int main()
{
    int i=5;
    i=(i++)*(++i);
    cout<<i<<endl;
}