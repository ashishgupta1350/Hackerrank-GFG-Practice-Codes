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


template <typename T>
class node{
public:
    T data;
    node<T>* next;

public:
    node(T data,node<T> *next=NULL){
        this->data=data;
        this->next=next;
    }
};

// 
template<typename T>
class List
{
private:

    node<T> *head;
    node<T> *tail;
    int size;
public:
    List(){
        this->head=NULL;
        this->tail=NULL;
        size=0;
    }
    void push_back(T data)
    {
        if(this->head==NULL)
        {
            this->head=new node<T> (data);
            this->tail=this->head;
        }
        else{
            node<T>* newNode=new node<T>(data);
            this->tail->next=newNode;
            this->tail=newNode;
        }
    }

    void printLLHelper(node<T> *head){// recursive print
    if (head==NULL) {
        return ;}
    cout<<head->data<<" ";
    printLLHelper(head->next);
    }
    void printLL()
    {
        printLLHelper(this->head);
        cout<<endl;
    }
    void pop_front()
    {
        this->head=this->head->next;// I know, the Node needs to be deallocated and deleted.

    }
    T front()
    {
        if(this->head==NULL)
        {
            cout<<"LL is empty"<<endl;
            return -1;
        }
        else{
            return this->head->data;
        }
    }
};

int main()
{
    List<double> myList;
    myList.push_back(10.2);
    myList.push_back(10.2);
    myList.push_back(9.2);
    myList.push_back(11.222);
    myList.push_back(0.2);
    myList.printLL();
    cout<<myList.front()<<endl;
}