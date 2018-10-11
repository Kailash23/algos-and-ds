template <typename T>

class BinaryTreeNode {
     public:		// Making these fields public so that we don't need to make getter and setter
         	T data;
         	BinaryTreeNode* left;	// Pointer of type BinaryTreeNode to store left node's address.
         	BinaryTreeNode* right;	// Pointer of type BinaryTreeNode to store right node's address.

         	BinaryTreeNode(T data){
         		this->data = data;
         		left = NULL;	// No need to type this->left as we dont have variable of same name like as variable data (above).
         		right = NULL;
         	}

         	~BinaryTreeNode(){
         		delete left;
         		delete right;
         	}
};
