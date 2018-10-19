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
	~TreeNode() {
        for (int i = 0; i < children.size(); i++) {
            delete children[i];
        }
    }
};
