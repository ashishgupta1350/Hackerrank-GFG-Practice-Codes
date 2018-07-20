#include<bits/stdc++.h> // this is for competitive programming
using namespace std;
class trieNode{
public:
	char ch; // character that the trieNode represents
	map<char,trieNode*> hMap; // hash map. Not using unordered map because in the future we may use the sorted nature of the map
	bool isEnd;// represents that the word has ended at this node
	trieNode(char ch,bool isEnd=false)
	{
		this->ch=ch;
		this->isEnd=isEnd;
	}
};
trieNode* createNode(char ch,bool isEnd=false)
{
	trieNode* tn=new trieNode(ch,isEnd);
	return tn;
}
class Trie{
	trieNode*root;
	trieNode* state;// optimizations for trie class for advanced lookups
public:
	Trie()
	{
		root=createNode('$');
		state=NULL;
	}
	void Insert(string s);
	void Delete(string s);
	bool Search(string s);
	vector<string> AdvanceSearch(string s);

// private:
	// void destroy(trieNode*root,string s) // needs improvement
	// {
	// 	if(! root || s.size()==0) return;
	// 	destroy(s.substr(1),root->hMap[s[0]]);
	// 	delete root;
	// 	return;

	// }
// public:



};

void Trie::Insert(string s)
{
	
	trieNode*temp=root;
		for(unsigned int i=0;i<s.length();i++)
		{
			char ch=s[i];
			// cout<<"processing : "<<s[i]<<" ";
			// cout<<temp->hMap.count(ch)<<endl;
			if( temp!=NULL && temp->hMap.count(ch)>0)
			{
				temp=temp->hMap[ch];
			}
			else{
				trieNode* n=createNode(ch);
				temp->hMap[ch]=n;
				temp=temp->hMap[ch];
			}

		}
		// check this
		if(temp!=NULL){
			temp->isEnd=true;
		}
		return;
}

void Trie::Delete(string s)
{
	trieNode*temp=root;
	for(int i=0;i<s.length();i++)
	{
		char ch=s[i];
		if(temp->hMap.find(ch)!=temp->hMap.end())
		{
			temp=temp->hMap[ch];
		}
		else return;
	}
	// check this
	if(temp!=NULL && temp->isEnd==true){
		temp->isEnd=false;
		// if(temp->hMap.size()==0)
		// {

		// }
	}
	return;
}
bool Trie::Search(string s)
{
	trieNode*temp=root;
	for(int i=0;i<s.length();i++)
	{
		char ch=s[i];
		if(temp->hMap.find(ch)!=temp->hMap.end())
		{
			temp=temp->hMap[ch];
		}
		else return false;
	}
	// check this
	if(temp!=NULL && temp->isEnd==true){
		return true;
	}
	return false;
}

void getStrings(trieNode*root, vector<string> &remainingWords,string s)
{
	if(root->hMap.size()==0)
	{
		if(root->isEnd)
			remainingWords.push_back(s);
		return; // this is return call
	}
	else if(root->isEnd==true)
	{
			remainingWords.push_back(s); // this will push the current string s as well
	}

	for(auto it=root->hMap.begin();it!=root->hMap.end();it++)
	{
		getStrings(root->hMap[it->first],remainingWords,s+it->first);
	}
	return;
}

vector<string> Trie:: AdvanceSearch(string s){

	trieNode*temp=root;
	vector<string> remainingWords;

	for(int i=0;i<s.length();i++)
	{
		char ch=s[i];
		if(temp->hMap.find(ch)!=temp->hMap.end())
		{
			temp=temp->hMap[ch];
		}
		else return remainingWords;
	}
	// if(temp!=NULL && temp->isEnd==true){
	// 	remainingWords.push_back(s);
	// }
	// we pushed the last word in the remainingWords, now time to push rest of the words that follow temp;
	getStrings(temp,remainingWords,s);// s + something will be pushed inside it
	return remainingWords;

}







int main()
{

	Trie t;
	t.Insert("ABC");
	t.Insert("ABCD");
	t.Insert("CAT");
	cout<<boolalpha;
	cout<<t.Search("ABCD")<<endl;
	t.Delete("ABCD");
	cout<<t.Search("ABCD")<<endl;
	t.Insert("ABCD");
	

	// trieNode*tn;
	vector<string> v=t.AdvanceSearch("ABC");
	for(int i=0;i<v.size();i++)
	{
		cout<<v[i]<<" ";
	}
	cout<<endl;

	cout<<"---End---"<<endl;
	return 0;
}


