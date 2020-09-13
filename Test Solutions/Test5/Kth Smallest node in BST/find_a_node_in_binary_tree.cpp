/*
   Kth smallest node in BST

   Given a BST and an integer K, you need to find the Kth smallest element present in the BST. Return INT_MIN if that is not present in the BST.
 */

#include "BinaryTreeNode.h"
#include <iostream>
#include <queue>
using namespace std;

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

void inorderTraversal(BinaryTreeNode<int> *root, vector<int> &v) {
    if (root == NULL) {
        return;
    }
    inorderTraversal(root->left, v);
    v.push_back(root->data);
    inorderTraversal(root->right, v);
}

int findNode(BinaryTreeNode<int> *root, int k) {
    vector<int> v;
    inorderTraversal(root, v);
    return v[k - 1];
}

int main() {
    BinaryTreeNode<int> *root = takeInputLevelWise();
    cout << endl;
    int k = 3;
    cout << findNode(root, k);
    delete root;
}

/*
   Quick Input:
   8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
   k = 3

   6
 */

/*
Solution:
   Do inorder traversal of the BST and store the elments one by one in an array.
   The array will now contain sorted elements of tree in ascending order.
   return the (k-1)th index of the array.
 */
