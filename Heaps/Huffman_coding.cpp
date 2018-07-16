	#include <iostream>
	using namespace std;
	#define LL long long int
	#define FOR(a,b,c)   for (int (a)=(b); (a)<(c); (a)++)
	#define FORN(a,b,c)  for (int (a)=(b); (a)<=(c); (a)++)
	#define FORD(a,b,c)  for (int (a)=(b); (a)>=(c); (a)--)
	#define REP(i,n)     FOR(i,0,n)
	#define REPN(i,n)    FORN(i,1,n)
	#define REPD(i,n)    FORD(i,n,1)
	#include<queue>
	class Node{
	    public:
	    char key;
	    int freq;
	    Node*left;
	    Node*right;
	    Node(char key='\0',int freq=0){
	        this->key=key;
	        this->freq=freq;
	        this->left=NULL;
	        this->right=NULL;
	        
	    }
	};
	void inOrderTraversal(Node* head,string code="")
	{
	    if(!head) return;
	    // head is there
	    if(head->key!='$'){
	        cout<<code<<" ";
	    }
	    
	    inOrderTraversal(head->left,code+'0');
	    inOrderTraversal(head->right,code+'1');
	    
	}
	template<typename T>
	bool comparitor(T a, T b)
	{
	    if(a->freq>b->freq)
	   	{return true;
	   	}
	   	else{
	   		return false;
	   	} // this is for the min heap
	}

	int main() {
		//creates a min heap
		
		int tc;
		cin>>tc;
		while(tc--){
		    priority_queue<Node*,vector<Node*>,comparitor<Node*>> pq;// min heap please, comparitor is just for node and not a template, though I could have easily created that.
		    string s;
		    cin>>s;
		    int len=s.length();
		    //int *freq=new int[len];
		    REP(i,len)
		    {
		        //cin>>freq[i];
		        int x;
		        cin>>x;
		        // create a node with freq [i] and push in the heap
		        Node *n=new Node(s[i],x);
		        pq.push(n);
		        
		    }
		    // this is done and the pq is set.
		    while(pq.size()!=1)
		    {
		        Node* a=pq.top();
		        pq.pop();
		        Node* b=pq.top(); 
		        pq.pop();
		        Node *newNode= new Node; // auto creates a node;
		        int newNodeFreq=a->freq+b->freq;
		        newNode->key='$';
		        newNode->freq=newNodeFreq;
		        if(a->freq<=b->freq) // the equal to sign is a must
		        {
		            newNode->left=a;
		            newNode->right=b;
		        }
		        else{
		            newNode->left=b;
		            newNode->right=a;
		        }
		        
		        pq.push(newNode);
		    }
		    // pq.top represents the head node.
		    inOrderTreaveral(pq.top());
		    cout<<endl;
		    //delete []freq;
		     // the only node represents a tree now.
		}
		
		// enter input
		
	}