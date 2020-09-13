#include "TreeNode.h"
#include <iostream>
using namespace std;

#include <queue>

/*
   Function to take input level wise using queue
 */
TreeNode<int> *takeInputLevelWise() {
    int rootData;
    cout << "Enter root data: " << endl;
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData); // Creating root node
    queue<TreeNode<int> *> pendingNodes;               // for taking input level wise we are using queue data structure having element of type TreeNode<int>*
    pendingNodes.push(root);                           // Adding root node into queue for processing

    while (pendingNodes.size() != 0) {                      // we can also queue's empty function
        TreeNode<int> *frontPointer = pendingNodes.front(); // Storing node at front of queue to frontPointer pointer of type TreeNode<T>* (frontPointer pointing to node in front of queue)
        pendingNodes.pop();                                 // Poping the front element
        cout << "Enter num of children of " << frontPointer->data << " : " << endl;
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++) {
            int childData;
            cout << "Enter child '" << i + 1 << "' of " << frontPointer->data << " : " << endl;
            cin >> childData;
            TreeNode<int> *child = new TreeNode<int>(childData); // Creating child node
            frontPointer->children.push_back(child);             // Creating link between root and child
            pendingNodes.push(child);                            //Pushing child nodes created into queue for there processing
        }
    }
    return root;
}

/*
   Pre-Order Traversal of genric tree using recursion.
 */
void preOrder(TreeNode<int> *root) {
    if (root == NULL) { // root is null, simply return!
        return;
    }
    cout << root->data << " "; // Print root first then call recursion on child nodes
    for (int i = 0; i < root->children.size(); i++) {
        preOrder(root->children[i]);
    }
}

/*
   Post-Order Traversal of genric tree using recursion.
 */
void postOrder(TreeNode<int> *root) {
    if (root == NULL) { // root is null, simply return!
        return;
    }
    for (int i = 0; i < root->children.size(); i++) { // Recursion on child nodes first
        postOrder(root->children[i]);
    }
    cout << root->data << " "; // Then print data
}

/*
   In-Order Traversal of genric tree using queue.
 */
void inOrder(TreeNode<int> *root) {
    if (root == NULL) {
        return;
    }
    queue<TreeNode<int> *> pendingNodes; // For level order print we will use queue.
    pendingNodes.push(root);
    while (pendingNodes.size() != 0) {
        TreeNode<int> *frontPointer = pendingNodes.front();
        pendingNodes.pop();
        cout << frontPointer->data << " "; // Print data first then push child nodes into queue for there printing
        for (int i = 0; i < frontPointer->children.size(); i++) {
            pendingNodes.push(frontPointer->children[i]);
        }
    }
}

/*
   Tree input shortcut just paste below line
   1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 1 9 0
 */

int main() {
    TreeNode<int> *root = takeInputLevelWise();
    cout << "Pre-order:";
    preOrder(root);
    cout << "\nPost-order:";
    postOrder(root);
    cout << "\nIn-order:";
    inOrder(root);
}

/*
				1
		   /    |    \
		 2      3      4
	   /  \   /   \
      5    6 7     8
	                 \
					  9

   Pre-order:1 2 5 6 3 7 8 9 4      (Root first then leaf node)
   Post-order:5 6 2 7 9 8 3 4 1		(Leaf node first then root node)
   In-order:1 2 3 4 5 6 7 8 9		(Level order)
 */
