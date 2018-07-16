// #include <iostream>
// using namespace std;
// #define LL long long int
// #define FOR(a,b,c)   for (int (a)=(b); (a)<(c); (a)++)
// #define FORN(a,b,c)  for (int (a)=(b); (a)<=(c); (a)++)
// #define FORD(a,b,c)  for (int (a)=(b); (a)>=(c); (a)--)
// #define REP(i,n)     FOR(i,0,n)
// #define REPN(i,n)    FORN(i,1,n)
// #define REPD(i,n)    FORD(i,n,1)


// class node{
// public:
//     int data;
//     node* next;

// public:
//     node(int data,node *next=NULL){
//         this->data=data;
//         this->next=next;
//     }
// };


// class Pair{
// public:
//     node*head;
//     node*tail;

//     Pair(node*head=NULL, node* tail= NULL){
//         this->head=head;
//         this->tail=tail;

//     }
// };

// node* takeInput(node *head)
// {
//     int n;
//     cin>>n;
//     while(n!=-1){

//         if(head==NULL){
//             head=new node(n);
//         }
//         else{
//             // traverse to the end of the ll and enter or enter at the head node, the data.
//             // we will enter data at the head of the linked list
//             node *newNode=new node(n);
//             // we created a new node
//             newNode->next=head;
//             head=newNode;
//         }
//         cin>>n;

//     }
//     return head;
// }

// void printLL(node *head){// recursive print
//     if (head==NULL) {
        
//         return ;}
//     cout<<head->data<<" ";

//     printLL(head->next);
//     return;
// }



// node* reverseLL_Advanced(node* head, int k)
// {
    
//     // reverse the first k elements of LL
//     // then head->next reverseLL_Advanced(next,k);
//     // return prev;

//     node *prev=NULL;
//     node*next=NULL;
//     node*curr=head;// that is how you reverse a LL
//     int count=0;
//     while(curr!=NULL && count<k)
//     {
//         next=curr->next;
//         curr->next=prev;
//         prev=curr;
//         curr=next;
//         count++;
//     }
//     if(next!=NULL)
//     head->next=reverseLL_Advanced(next,k);
//     return prev;

// }


// int main() {
//     //code
//     // node*head=NULL;
//     // head=takeInput(head);
//     // printLL(head);
//     // cout<<" length is "<<recLength(head)<<endl;
//     // head=deleteKey(head,2);
//     // cout<<"deleted 2 if exists: "<<endl;
//     // printLL(head);
//     // head=reverseLL(head);
//     // cout<<endl<<"printing reversed LL: ";
//     // printLL(head);
//     // cout<<endl;
//     node*head1=NULL;
//     // node*head2=NULL;
//     cout<<"Enter LL1: ";
//     head1=takeInput(head1);
//     reverseLL_Advanced(head1,3);
//     printLL(head1);
//     return 0;
// }

// C program to reverse a linked list in groups of given size
#include<stdio.h>
#include<stdlib.h>
 #include<iostream>
using namespace std;
#include<cstdio>
#include<map>
/* Link list node */
struct Node
{
    int data;
    struct Node* next;
};
 

/* Reverses the linked list in groups of size k and returns the 
   pointer to the new head node. */
struct Node *reverse (struct Node *head, int k)
{
    struct Node* current = head;
    struct Node* next = NULL;
    struct Node* prev = NULL;
    int count = 0;   
     
    /*reverse first k nodes of the linked list */
    while (current != NULL && count < k)
    {
        next  = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }
     
    /* next is now a pointer to (k+1)th node 
       Recursively call for the list starting from current.
       And make rest of the list as next of first node */
    if (next !=  NULL)
       head->next = reverse(next, k); 
 
    /* prev is new head of the input list */
    return prev;
}
 
/* UTILITY FUNCTIONS */
/* Function to push a node */
void push(struct Node** head_ref, int new_data)
{
    /* allocate node */
    struct Node* new_node =
            (struct Node*) malloc(sizeof(struct Node));
 
    /* put in the data  */
    new_node->data  = new_data;
 
    /* link the old list off the new node */
    new_node->next = (*head_ref);    
 
    /* move the head to point to the new node */
    (*head_ref)    = new_node;
}
 
/* Function to print linked list */
void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d  ", node->data);
        node = node->next;
    }
} 


/* Drier program to test above function*/
int main(void)
{
    /* Start with the empty list */
    struct Node* head = NULL;
  
     /* Created Linked list is 1->2->3->4->5->6->7->8->9 */
     push(&head, 9);
     push(&head, 8);
     push(&head, 7);
     push(&head, 6);
     push(&head, 5);
     push(&head, 4);
     push(&head, 3);
     push(&head, 2);
     push(&head, 1);  
 
     printf("\nGiven linked list \n");
     printList(head);
     head = reverse(head, 3);
 
     printf("\nReversed Linked list \n");
     printList(head);

     cout<<endl;


     // we will now detect a loop in the linked list
     map<node*,bool> visited;

 
     return(0);
}