#include <bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	struct node *next, *prev;
};
// Split a doubly linked list (DLL) into 2 DLLs of
// half sizes
struct node *splitList(struct node *head);
// Function to merge two DLLs
struct node *merge(struct node *first, struct node *second);
struct node *mergeSort(struct node *head)
{
	if (!head || !head->next)
		return head;
	struct node *second = splitList(head);
	head = mergeSort(head);
	second = mergeSort(second);
	return merge(head, second);
}
void insert(struct node **head, int data)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = data;
	temp->next = temp->prev = NULL;
	if (!(*head))
		(*head) = temp;
	else
	{
		temp->next = *head;
		(*head)->prev = temp;
		(*head) = temp;
	}
}
void print(struct node *head)
{
	struct node *temp = head;
	while (head)
	{
		cout<<head->data<<' ';
		temp = head;
		head = head->next;
	}
	cout<<endl;
	while (temp)
	{
		cout<<temp->data<<' ';
		temp = temp->prev;
	}
	cout<<endl;
}
// Utility function to swap two integers
void swap(int *A, int *B)
{
	int temp = *A;
	*A = *B;
	*B = temp;
}
// Driver program
int main(void)
{
    long test;
    cin>>test;
    while(test--)
    {
        int n, tmp;
        struct node *head = NULL;
        cin>>n;
        while(n--){
            cin>>tmp;
            insert(&head, tmp);
        }
        head = mergeSort(head);
        print(head);
    }
	return 0;
}



/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*
Structure of the node of the list is as
struct node
{
	int data;
	struct node *next, *prev;
};
*/
// Split a doubly linked list (DLL) into 2 DLLs of
// half sizes
struct node *splitList(struct node *head)
{
    // Code here
    if(!head) return head;
    struct node*rabbit=head;
    struct node*tortoise=head;
    while(rabbit!=NULL)
    {
        rabbit=rabbit->next;
        tortoise=tortoise->next;
        if(!rabbit){
            break;
        }
        else
         rabbit=rabbit->next;
    }
    return tortoise;
    
}
// Function to merge two DLLs
struct node *merge(struct node *first, struct node *second)
{
    // Code here
    if(!first) return second;
    if(!second) return first;
    struct node*dummyNode = new struct node;
    dummyNode->data=-1;
    dummyNode->next=NULL;
    dummyNode->prev=NULL;
    struct node*head=dummyNode;
    struct node*tail=dummyNode;
    while(first!=NULL && second!=NULL){
        cout<<first->data<<" ";
        if(first->data<=second->data){
            tail->next=first;
            first->prev=tail;
            first=first->next;
            tail=tail->next;
        }
        else{
            tail->next=second;
            second->prev=tail;
            second=second->next;
            tail=tail->next;
            
        }
    }
    if(!first)
    {
        tail->next=second;
    }
    else if(!second)
    {
        tail->next=first; 
    }
    return head->next;
    
}