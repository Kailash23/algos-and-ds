/*
   Boundary Traversal

   Given a binary tree having N nodes, print its boundary traversal.
   Output should be in anticlock wise.
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

/*
   Function to print left boundary of tree which didn't include leaf node.
   Printing is done top to bottom fashion (ie root to leaf) in order to achieve
   anticlock wise printing.
   So we printing root's data first BEFORE recursive calls on left and right.
 */
void printLeft(BinaryTreeNode<int> *root) {
    if (root == NULL) {
        return;
    }
    if (root->left != NULL || root->right != NULL) { // Print data only if either left and right subtree is present.(ie root is not leaf node in order to avoid duplicacy of node data)
        cout << root->data << " ";
    }
    if (root->left != NULL) { // recursive call to left node if it is present.
        printLeft(root->left);
    } else if (root->left == NULL && root->right != NULL) { // Recursive call on right node only when left node is absent.
        printLeft(root->right);
    }
    // else -> nodes having neither left nor right child ie leaf nodes we dont want to traverse them and print them (avoiding dublicates)
}

void printLeaf(BinaryTreeNode<int> *root) {
    if (root == NULL) {
        return;
    }
    if (root->left == NULL && root->right == NULL) { // Print data only when root has no child (ie. root is leaf node)
        cout << root->data << " ";
    }
    printLeaf(root->left);  // Traverse left subtree for the search of leaf node
    printLeaf(root->right); // Traverse left subtree for the search of leaf node
}

/*
   Function to print right boundary of tree which did't include leaf node.
   Printing is done bottom to top fashion (ie leaf to root) in order to achieve
   anticlock wise printing.
   So we printing root's data AFTER recursive calls on left and right.
 */
void printRight(BinaryTreeNode<int> *root) {
    if (root == NULL) {
        return;
    }
    if (root->right != NULL) {
        printRight(root->right);
    } else if (root->right == NULL && root->left != NULL) {
        printRight(root->left);
    }
    if (root->left != NULL || root->right != NULL) {
        cout << root->data << " ";
    }
    // else -> nodes having neither left nor right child ie leaf nodes we dont want to traverse them and print them (avoiding dublicates)
}

void solve(BinaryTreeNode<int> *root) {
    cout << root->data << " ";
    printLeft(root->left);
    printLeaf(root);
    printRight(root->right);
}

int main() {
    BinaryTreeNode<int> *root = takeInputLevelWise();
    cout << endl;
    solve(root);
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
   1 2 4 5 8 9 7 3

 */
