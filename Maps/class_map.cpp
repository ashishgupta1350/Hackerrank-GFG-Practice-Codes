#include<iostream>
using namespace std;
//#include<math>
template <typename T>
class mapNode{
public:
	string key;
	T value;
	mapNode<T>*next;
	mapNode(string key, T value)
	{
		this->key=key;
		this->value=value;
		this->next=NULL;
	}
};
template<typename T>
class Map{
public:
	int bucketSize;
	mapNode<T> **buckets;
	int count;
	Map()
	{
		this->bucketSize=15;
		this->buckets=new mapNode<T> *[15];
		this->count=0;
		// check this
	}
	int  findBucketIndex(string key)
	{
		int p=37;
		int hashCode=0;
		int num=1;
		int n=key.length()-1;
		while(n--){
			hashCode+=key[n]*num;
			hashCode%=this->bucketSize;
			num%=this->bucketSize;
			num*=p;
		}
		return hashCode%this->bucketSize;

	}
	void insert(string key,T value)
	{
		int bucketIndex= findBucketIndex( key);
		mapNode<T>*head=this->buckets[bucketIndex];
		while(head)
		{
			if(head->key==key)
			{
				head->value=value;
				return;

			}
			head=head->next;
		}
		//else key is not found;
		head=this->buckets[bucketIndex];
		mapNode<T> *newNode=new mapNode<T>(key,value);
		newNode->next=head;
		buckets[bucketIndex]=newNode;
		count++;

	}
	int size(){
		return this->count;
	}




};
#include<cstring>
int main()
{

	string s="ashish";
	Map<int> m;
	cout<<m.count<<endl;
	m.insert("ashish",100);
	cout<<m.count<<endl;
	
	return 0;
}