#include <iostream>
using namespace std;
#define LL long long int
#define FOR(a,b,c)   for (int (a)=(b); (a)<(c); (a)++)
#define FORN(a,b,c)  for (int (a)=(b); (a)<=(c); (a)++)
#define FORD(a,b,c)  for (int (a)=(b); (a)>=(c); (a)--)
#define REP(i,n)     FOR(i,0,n)
#define REPN(i,n)    FORN(i,1,n)
#define REPD(i,n)    FORD(i,n,1)
#include<map>

class node{
public:
    int data;
    node* next;

public:
    node(int data,node *next=NULL){
        this->data=data;
        this->next=next;
    }
};


class Pair{
public:
    node*head;
    node*tail;

    Pair(node*head=NULL, node* tail= NULL){
        this->head=head;
        this->tail=tail;

    }
};

node* takeInput(node *head)
{
    int n;
    cin>>n;
    while(n!=-1){

        if(head==NULL){
            head=new node(n);
        }
        else{
            // traverse to the end of the ll and enter or enter at the head node, the data.
            // we will enter data at the head of the linked list
            node *newNode=new node(n);
            // we created a new node
            newNode->next=head;
            head=newNode;
        }
        cin>>n;

    }
    return head;
}

node*deleteKey(node *head,int key){

    // we need two pointers. Its easy to delete.
    if (head==NULL) return head;
    if (head->data==key) {head=head->next;return head;}
    else 
        {node* prev= head;
        node*curr=head->next;
        while(curr!=NULL && curr->data!=key ){
            curr=curr->next;
            prev=prev->next;
        }

        if(curr==NULL){
            return head;
        }
        else{
            prev->next=curr->next;
            curr->next=NULL;
            delete curr;
            return head;
        }
    }
}



int length(node * head){
    int len=0;
    node *temp=head;
    while(temp!=NULL){
        len++;
        temp=temp->next;

    }
    return len;
}

int recLength(node *head){
    if(head==NULL){
        return 0;
    }
    return 1+recLength(head->next);


}

void printLL(node *head){// recursive print
    if (head==NULL) {
        
        return ;}
    cout<<head->data<<" ";

    printLL(head->next);
    return;
}


Pair* ReverseLL(Pair* ht){
    if(ht->head==NULL || ht->head->next==NULL) return ht;
    else{
        node* temp=ht->head;
        ht->head=ht->head->next;// this is the forward moving step in recursion.
        Pair* newHT= ReverseLL(ht);// calls recursion
        newHT->tail->next=temp;// gets output , does operations. 
        temp->next=NULL;
        newHT->tail=temp;
        return newHT;
    }
}
// we are making this by pairs to decrease the time complexity to minimum(optimal time complexity)

node*reverseLL(node*head)
{
    // find the tail of the linked list
    if (head==NULL)
    {
        return head;
    }
    node*temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    node*tail=temp;
    // creating a pair to initialize the linked list head and tail
    Pair* headTail= new Pair(head, tail);
    Pair* p=ReverseLL(headTail);
    return p->head; // every thinng is dynamically created to avoid confusion
}

node* mergeLL(node*a, node *b)
{
    if(a==NULL) return b;
    if(b==NULL) return a;

    node* dummy = new node(-1);// dummy is node for head and will be deleted once use is over
    node*tail=  dummy;
    while(1){
        if(a==NULL)
        {
            tail->next=b;
            break;
        }
        else if (b==NULL)
        {
            tail->next=a;
            break;
        }
        else{

            if(a->data<=b->data)
            {   
                // create a new node pointer 
                // add data to tail of dummy
                // advance a, but delete the current a node
                // done!
                cout<<a->data<<"   "<<b->data<<endl;
                node* newNode=a;
                a=a->next;
                newNode->next=NULL;
                tail->next=newNode;
                tail=tail->next;

            }
            else{
                node* newNode=b;
                b=b->next;
                newNode->next=NULL;
                tail->next=newNode;
                tail=tail->next;         
           }
        }
    }
    node*head= dummy->next;
    delete dummy;
    return head;
}


node* detectLoop(node*head)
{
    if(head==NULL) return head;// NULL signifies I dont find any loop
    map<node*,bool> myMap;

    node*temp=head;
    // bool flag=false;
   
    // this is c++ not struct of c. I feel it is bad to write it again and again.
    while(1)
    {
        // check that myMap.temp=
        if(temp->next==NULL) {
            return NULL;
        }
        myMap[temp]=true;
        if(myMap.find(temp->next)==myMap.end())
        {
            // not found
            temp=temp->next;
            continue;
        }
        else{
            return temp;
        }
    }

}   
 
 node* push(node*head,int data)
 {
    if(head==NULL)
    {
        head=new node(data);
        return head;
    }
    else{
        node*temp=new node(data);
        temp->next=head;
        head=temp;
        return head;
    }

 }

int main() {
    //code
    node*head=NULL;
    // head=takeInput(head);
    // printLL(head);
    // cout<<" length is "<<recLength(head)<<endl;
    // head=deleteKey(head,2);
    // cout<<"deleted 2 if exists: "<<endl;
    // printLL(head);
    // head=reverseLL(head);
    // cout<<endl<<"printing reversed LL: ";
    // printLL(head);
    // cout<<endl;
    // node*head1=NULL;
    // node*head2=NULL;
    // cout<<"Enter LL1: ";
    // head1=takeInput(head1);
    // cout<<"enter LL2: ";
    // // VV imp;
    // // remember to but the imput in 'reverse' direction because of the take input function!!!!!!!!
    // head2=takeInput(head2);
    // cout<<head1->data<< "   :: :: " <<head2->data<<endl;
    // head=mergeLL(head1,head2);
    // cout<<endl<<"printting the merged LL: ";
    // printLL(head);

    // LL construct
    head=push(head,10);
    head=push(head,5);
    head=push(head,3);
    head=push(head,3);
    head=push(head,2);
    head=push(head,1);
    node*temp=head;
    temp=temp->next->next->next->next;
    temp->next=head; // created a loop;

    cout<<endl<<"Lets check if the LL has a loop or not!: "<<endl;
    node* detect=detectLoop(head);
    if(detect==NULL)
    {
        cout<<"No loop was detected!"<<endl;
    }
    else{
        cout<<"Loop detected"<<endl;
        detect->next=NULL;
        cout<<"Confirming that no loop exists : ";
        detect=detectLoop(head);
        if(detect==NULL)
        {
            cout<<"confirmed"<<endl;
        }
        else{
            cout<<"your code is faulty : P"<<endl;
        }
    }
    return 0;
}