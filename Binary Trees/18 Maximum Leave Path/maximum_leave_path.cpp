/*
   Maximum Leave Path

   Given a binary tree of N nodes, find and return the maximum sum path between
   wo leaves of the given tree.
   Given binary tree contains positive values only.
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

int sum(BinaryTreeNode<int> *root) {
    if (root == NULL) {
        return 0;
    }
    return root->data + max(sum(root->left), sum(root->right));
}

long long int maximumSumLeafpath(BinaryTreeNode<int> *root) {
    if (root == NULL) {
        return 0;
    }
    int option1 = sum(root->left) + sum(root->right);
    int option2 = maximumSumLeafpath(root->left);
    int option3 = maximumSumLeafpath(root->right);
    return max(root->data + option1, max(option2, option3));
}

int main() {
    BinaryTreeNode<int> *root = takeInputLevelWise();
    cout << endl;
    cout << maximumSumLeafpath(root);
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

     26
 */
