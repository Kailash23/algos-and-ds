#include <vector>
using namespace std;

template <typename T>

class TreeNode {

  public:
    T data;                         // Data that node will have
    vector<TreeNode<T> *> children; // Dynamic array of type

    int childCount;

    TreeNode(T data) { //Constructor to initialize data to the node created node.
        this->data = data;
        childCount++;
    }

    int numChildren() {
        return children.size();
    }

    void addChild(TreeNode<T> *child) {
        children.push_back(child);
    }

    TreeNode<T> *getChild(int index) {
        return children[index];
    }

    void setChild(int index, TreeNode<int> *child) {
        children[index] = child;
    }

    ~TreeNode() {
        for (int i = 0; i < children.size(); i++) {
            delete children[i];
        }
    }
};
