template <typename T>
class BinaryTreeNode {
public:
	T data;
	BinaryTreeNode<int>* left;
	BinaryTreeNode<int>* right;

	BinaryTreeNode(T data){
		this->data = data;
		left = NULL;
		right = NULL;
	}
};
