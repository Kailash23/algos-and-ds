/*
   No of leaf node in a binary tree.
 */

#include "BinaryTreeNode.h"
#include <iostream>
using namespace std;

#include <queue>

BinaryTreeNode<int> *takeInputLevelWise() {
    int rootData;
    cout << "Enter root data" << endl;
    cin >> rootData;
    if (rootData == -1) { // if data is -1 consider it as no child node.
        return NULL;
    }

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> pendingNodes; // queue used to input levelwise
    pendingNodes.push(root);

    while (pendingNodes.size() != 0) {
        BinaryTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();

        cout << "Enter left child of " << front->data << endl;
        int leftChildData;
        cin >> leftChildData;
        if (leftChildData != -1) {
            BinaryTreeNode<int> *child = new BinaryTreeNode<int>(leftChildData);
            front->left = child;
            pendingNodes.push(child); // Push child node for inputing there child nodes.
        }

        cout << "Enter right child of " << front->data << endl;
        int rightChildData;
        cin >> rightChildData;
        if (rightChildData != -1) {
            BinaryTreeNode<int> *child = new BinaryTreeNode<int>(rightChildData);
            front->right = child;
            pendingNodes.push(child); // Push child node for inputing there child nodes.
        }
    }
    return root;
}

/*
   Function to count number of leaf nodes in a binary tree
 */
int numLeafNodes(BinaryTreeNode<int> *root) {
    if (root == NULL) { // Base case is needed in case of binary Tree.
        return 0;
    }
    if (root->left == NULL && root->right == NULL) {
        return 1;
    }
    return numLeafNodes(root->left) + numLeafNodes(root->right);
}

int main() {
    BinaryTreeNode<int> *root = takeInputLevelWise();
    cout << "\nNo of Leaf Nodes: " << numLeafNodes(root);
    delete root;
}

/*
   Quick Input:
   1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
 */

/*
                                1
                            /		\
                          2			  3
                        /	\		/	\
                       4	 5	  6      7
                                /   \
                               8	 9

   No of Leaf Nodes: 5
 */
