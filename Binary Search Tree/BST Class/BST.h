class BST {
	BinaryTreeNode<int>* root;

	public:
	BST(){
		root = NULL;
	}

	~BST(){
		delete root;
	}

	private:
	BinaryTreeNode<int>* deleteData(int data, BinaryTreeNode<int>* node){
		if(root == NULL){
			return NULL;
		}

		if(data > node->data){
			node->right = deleteData(data, node->right);
			return node;
		} else if(data < node->data){
			node->left = deleteData(data, node->left);
			return node;
		} else {
			if(node->left == NULL && node->right == NULL){
				delete node;
				return NULL;
			} else if (node->left == NULL) {
				BinaryTreeNode<int>* temp = node->right;
				node->right = NULL;
				delete node;
				return temp;
			} else if(node->right == NULL) {
				BinaryTreeNode<int>* temp = root->left;
				root->left = NULL;
				delete node;
				return temp;
			} else {

			}
		}
	}
}
