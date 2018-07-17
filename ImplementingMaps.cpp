#include<iostream>
using namespace std;

//template <typename T>
template<typename V>
class mapNode{
	public:
	string key;
	V value;
	mapNode<V>*next;
	mapNode(string key,V value)
	{
		this->key=key;
		this->data=data;
		this->next=NULL;
	}
	~mapNode()
	{
		delete(next); // this is important 
	}
};
template<typename V>
class Map{
	mapNode<V>**buckets;
	int count;
	int numBuckets;
public:
	Map()
	{
		this->numBuckets=5;
		this->buckets=new mapNode<V>*[numBuckets];
		for(int i=0;i<numBuckets;i++)
		{
			buckets[i]=NULL;
		}
		this->count=0;
	}
	void getSize()
	{
		return this->count;
	}
	void insert(string key,V value)
	{
		int bucketIndex=getBucketIndex(key);
		mapNode<V> *head=buckets[bucketIndex];
		while(head!=NULL)
		{
			if(head->key==key) {head->value=value;return;}
			head=head->next;
		}
		head=buckets[bucketIndex];
		mapNode<V>*node=new mapNode<V>(key,value);
		node->next=head;
		buckets[bucketIndex]=node;
		count++;
		return;
	}
	V getValue(string key)
	{
		int bucketIndex=getBucketIndex(key);
		mapNode<V> * head=Map[bucketIndex];
		while(head!=NULL)
		{
			if(head->key==key) return head->value;
			head=head->next;
		}
		return -1;
	}
	int getSize()
	{
		return count;
	}
	// bool search(string key)
	// {
	// 	int bucketIndex=getBucketIndex(key);
	// same as above only
	// }
private:
	int getBucketIndex(string key)
	{
		int hashCode=0;
		int currentCoeff=1;
		int p=37;
		for(int i=key.length();i>=0;i--)
		{
			hashCode+=key[i]*currentCoeff;
			hashCode%=numBuckets;
			currentCoeff *=37;
			currentCoeff%=numBuckets;
		}
		return hashCode%numBuckets;
	}
	// void insert()



};


int main()
{





	return 0;
}