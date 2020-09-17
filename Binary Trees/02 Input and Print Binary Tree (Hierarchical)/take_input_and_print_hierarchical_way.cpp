/*
   Input and Print Binary tree using recursion.
 */

#include <iostream>
using namespace std;

#include "BinaryTreeNode.h"

void printTree(BinaryTreeNode<int> *root) {
    if (root == NULL) { // Base Case
        return;
    }
    cout << root->data << ":";
    if (root->left != NULL) { // Check if left exists or not
        cout << "L" << root->left->data;
    }
    if (root->right != NULL) { // Check if left exists or not
        cout << "R" << root->right->data;
    }
    cout << endl;
    printTree(root->left);
    printTree(root->right);
}

BinaryTreeNode<int> *takeInput() {
    int rootData;
    cout << "Enter data" << endl;
    cin >> rootData;
    if (rootData == -1) { // If user input -1 that means no child (return NULL)
        return NULL;
    }
    // ie. user didn't enter -1
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData); // Make new node having rootData.
    BinaryTreeNode<int> *leftChild = takeInput();                  // Calling to input left sub-tree.
    BinaryTreeNode<int> *rightChild = takeInput();                 // Calling to input right sub-tree.
    root->left = leftChild;                                        // Linking root node with leftChild.
    root->right = rightChild;                                      // Linking root node with rightChild.
    return root;
}

int main() {
    BinaryTreeNode<int> *root = takeInput();
    cout << endl;
    printTree(root);
    delete root;
}

/*
		   1
		/    \
	   2	   3
	 /   \	   /
	4     5   8
		 / \
	    6   7

	Enter data
	1
	Enter data
	2
	Enter data
	4
	Enter data
	-1
	Enter data
	-1
	Enter data
	5
	Enter data
	6
	Enter data
	-1
	Enter data
	-1
	Enter data
	7
	Enter data
	-1
	Enter data
	-1
	Enter data
	3
	Enter data
	8
	Enter data
	-1
	Enter data
	-1
	Enter data
	-1

	1:L2R3
	2:L4R5
	4:
	5:L6R7
	6:
	7:
	3:L8
	8:
 */
