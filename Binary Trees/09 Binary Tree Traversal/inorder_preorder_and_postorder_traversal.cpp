/*
   Tree Traversal
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

void inOrder(BinaryTreeNode<int> *root) {
    if (root == NULL) {
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void preOrder(BinaryTreeNode<int> *root) {
    if (root == NULL) {
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(BinaryTreeNode<int> *root) {
    if (root == NULL) {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

int main() {
    BinaryTreeNode<int> *root = takeInputLevelWise();
    cout << "\nInorder: ";
    inOrder(root);
    cout << "\nPreorder: ";
    preOrder(root);
    cout << "\nPostorder: ";
    postOrder(root);
    delete root;
}

/*
   Quick Input:
   1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
 */

/*
   Input:
                                1
                            /		\
                          2			  3
                        /	\		/	\
                       4	 5	  6      7
                                /   \
                               8	 9

 */

/*
   Inorder: 4 2 5 1 8 6 9 3 7
   Preorder: 1 2 4 5 3 6 8 9 7  (Root will be the first element in preorder)
   Postorder: 4 5 2 8 9 6 7 3 1 (Root will be the first element in postorder)
 */

/*
   Level order:- level1 nodes -> level2 nodes -> and so on
   Pre order  :- root -> left -> right
   Post order :- left -> right -> root
   In Order   :- left -> root -> right
 */
