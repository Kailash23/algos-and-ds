#include <vector>
using namespace std;

template <typename T>

class TreeNode {
	public:
		T data;		// Data that node will have
		vector<TreeNode<T>*> children;		// Dynamic array of type TreeNode<T>*. 'children' will store the address of its leaf node.
		//vector<TreeNode*> children;		// We dont need to specify datatype <T>

		TreeNode(T data) {		//Constructor to initialize data to the node created node.
			this->data = data;		// Data initialization
		}

		~TreeNode() {			// Just call delete on root of tree - This will delete the whole tree recursively.
	        for (int i = 0; i < children.size(); i++) {
	            delete children[i];		// call on root node will also call delete on all children of that node.
	        }
	    }
};
