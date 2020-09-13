/*
   Code: BST Class

   Implement the BST class which includes following functions -
   1. search
   Given an element, find if that is present in BSt or not. Return true or false.

   2. insert -
   Given an element, insert that element in the BST at the correct position. Assume
   unique elements will be given.

   3. delete -
   Given an element, remove that element from the BST. If the element which is to be
   deleted has both children, replace that with the minimum element from right sub-tree.

   4. printTree (recursive) -
   Print the BST in ithe following format -
   For printing a node with data N, you need to follow the exact format -
   N:L:x,R:y
   wherer, N is data of any node present in the binary tree. x and y are the values of
   left and right child of node N. Print the children only if it is not null.
   There is no space in between.
   You need to print all nodes in the recursive format in different lines.
 */

#include "BinaryTreeNode.h"
#include <iostream>
using namespace std;

template <typename T>
class BST {
  public:
    BinaryTreeNode<T> *root;

    BST() {
        root = NULL;
    }

    ~BST() {
        delete root;
    }

    /*
	   Given an element, find if that is present in BST or not.
	   Return true or false.
	 */
    bool search(BinaryTreeNode<T> *root, T element) {
        if (root == NULL) {
            return false;
        }
        if (root->data == element) {
            return true;
        }
        if (root->data < element) {
            return search(root->right, element);
        } else {
            return search(root->left, element);
        }
    }

    bool search(int data) {
        return search(root, data);
    }

    /*
	   Given an element, insert that element in the BST at the correct position.
	   Assume unique elements will be given.
	 */
    BinaryTreeNode<T> *insert(T element, BinaryTreeNode<T> *node) {
        if (node == NULL) {
            BinaryTreeNode<T> *newNode = new BinaryTreeNode<T>(element);
            return newNode;
        }
        if (element < node->data) {
            node->left = insert(element, node->left);
        } else {
            node->right = insert(element, node->right);
        }
        return node;
    }

    void insert(T data) {
        this->root = insert(data, this->root);
    }

    /*
	   Print the BST
	   Format : N:L:x,R:y
	 */
    void printTree(BinaryTreeNode<T> *root) {
        if (root == NULL) {
            return;
        }
        cout << root->data << ": ";
        if (root->left != NULL) {
            cout << "L:" << root->left->data << ",";
        }
        if (root->right != NULL) {
            cout << "R:" << root->right->data;
        }
        cout << endl;
        printTree(root->left);
        printTree(root->right);
    }

    void printTree() {
        printTree(this->root);
    }

    /*
	   Given an element, remove that element from the BST. If the element which is
	   to be deleted has both children, replace that with the minimum element from
	   right sub-tree.
	 */
    BinaryTreeNode<T> *deleteData(T data, BinaryTreeNode<T> *node) {
        if (node == NULL) {
            return NULL;
        }
        if (data > node->data) {
            node->right = deleteData(data, node->right);
            return node;
        } else if (data < node->data) {
            node->left = deleteData(data, node->left);
            return node;
        } else {
            if (node->left == NULL && node->right == NULL) {
                delete node;
                return NULL;
            } else if (node->left == NULL) {
                BinaryTreeNode<T> *temp = node->right;
                node->right = NULL;
                delete node;
                return temp;
            } else if (node->right == NULL) {
                BinaryTreeNode<T> *temp = node->left;
                node->left = NULL;
                delete node;
                return temp;
            } else {
                BinaryTreeNode<T> *minNode = node->right;
                while (minNode->left != NULL) {
                    minNode = minNode->left;
                }
                T rightMinData = minNode->data;
                node->data = rightMinData;
                node->right = deleteData(rightMinData, node->right);
                return node;
            }
        }
    }

    void deleteData(T data) {
        root = deleteData(data, root);
    }
};

int main() {
    BST<int> *tree = new BST<int>();
    tree->insert(5);
    tree->insert(3);
    tree->insert(6);
    tree->insert(1);
    tree->insert(9);
    tree->insert(10);
    tree->insert(8);

    tree->printTree();
    cout << endl;
    tree->deleteData(10);

    tree->printTree();

    cout << endl;
    cout << tree->search(5) << endl;
}

/*
   5: L:3,R:6
   3: L:1,
   1:
   6: R:9
   9: L:8,R:10
   8:
   10:

   5: L:3,R:6
   3: L:1,
   1:
   6: R:9
   9: L:8,
   8:

   1
 */
