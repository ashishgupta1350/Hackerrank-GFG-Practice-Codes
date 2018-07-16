
template<typename T>
class BTNode{
public:
	T data;
	BTNode<T> *left;
	BTNode<T> *right;
	BTNode(T data)
	{
		this->data=data;
		this->left=left;
		this->right=right;	
	}
};