#include <iostream>
using namespace std;

#include <limits.h>
#include <queue>
#include <vector>

template <typename T>

class TreeNode {
  public:
    T data;
    vector<TreeNode<T> *> children;

    TreeNode(T data) {
        this->data = data;
    }

    ~TreeNode() {
        for (int i = 0; i < children.size(); i++) {
            delete children[i];
        }
    }
};

TreeNode<int> *takeInputLevelWise() {
    int rootData;
    cout << "Enter root data : " << endl;
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);
    queue<TreeNode<int> *> pendingNodes;
    pendingNodes.push(root);

    while (pendingNodes.size() != 0) {
        TreeNode<int> *frontPointer = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cout << "Enter number of child of root " << frontPointer->data << ":" << endl;
        cin >> numChild;
        for (int i = 0; i < numChild; i++) {
            int childValue;
            cout << "Enter value for child " << i + 1 << " : " << endl;
            cin >> childValue;
            TreeNode<int> *child = new TreeNode<int>(childValue);
            frontPointer->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}

TreeNode<int> *secondLargest(TreeNode<int> *root) {
    if (root == NULL) { // If root is NULL, simply return NULL!
        return NULL;
    }
    // Value
    int first = INT_MIN;
    int second = INT_MIN;
    // Node
    TreeNode<int> *max;
    TreeNode<int> *secondMax;

    queue<TreeNode<int> *> pendingNodes;
    pendingNodes.push(root);

    first = root->data; // Currently first will have root's data as we are considering only root as of now.
    max = root;

    while (pendingNodes.size() != 0) {
        TreeNode<int> *frontPointer = pendingNodes.front();
        pendingNodes.pop();
        for (int i = 0; i < frontPointer->children.size(); i++) {
            if (frontPointer->children[i]->data > first && frontPointer->children[i]->data > second) { // node having data greater than both first and second
                second = first;                                                                        // first will become second
                secondMax = frontPointer;
                first = frontPointer->children[i]->data; // new node will become first as it is greater than both
                max = frontPointer->children[i];
            } else if (frontPointer->children[i]->data < first && frontPointer->children[i]->data > second) { //node having data smaller than first but greater then scond
                secondMax = frontPointer->children[i];                                                        // Changes will be done to only second
                second = frontPointer->children[i]->data;
            }
            pendingNodes.push(frontPointer->children[i]); // psuhing nodes to queue for there for traversing and comparing them them.
        }
    }
    return secondMax; // return second max value
}

/*
   Tree input shortcut just paste any of below lines
   1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 1 9 0
 */
int main() {
    TreeNode<int> *root = takeInputLevelWise();
    cout << "Second largest: " << endl;
    TreeNode<int> *secMax;
    secMax = secondLargest(root);
    cout << secMax->data << endl;
}

/*
   Second largest:
   8
 */
