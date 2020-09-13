/*
   Given a binary tree, print out all of its root-to-leaf paths one per line.
 */

#include "BinaryTreeNode.h"
#include <iostream>
using namespace std;

#include <queue>
#include <vector>

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

void printPath(vector<int> vec) {
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
}

void printAllRootToLeafPathsHelper(BinaryTreeNode<int> *root, vector<int> path) {
    if (root == NULL) {
        return;
    }
    path.push_back(root->data);
    if (root->left == NULL && root->right == NULL) {
        printPath(path);
        cout << endl;
    } else {
        printAllRootToLeafPathsHelper(root->left, path);
        printAllRootToLeafPathsHelper(root->right, path);
    }
}

void printAllRootToLeafPaths(BinaryTreeNode<int> *root) {
    vector<int> path;
    printAllRootToLeafPathsHelper(root, path);
}

int main() {
    BinaryTreeNode<int> *root = takeInputLevelWise();
    printAllRootToLeafPaths(root);
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

   1 2 4
   1 2 5
   1 3 6 8
   1 3 6 9
   1 3 7

 */
