/**
 * Data Structures - binary search tree
 * binary_search_tree.cpp
 * Purpose: Implementation of Binary Search Tree
 *
 * @author Kailash Uniyal
 * @version 1.0 28/10/18
*/

#include <climits>
#include <iostream>
#include <queue>
using namespace std;

template <typename T>
class BinaryTreeNode {
  public:
    T data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
    ~BinaryTreeNode() {
        delete left;
        delete right;
    }
};

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
	   Function to take input levelwise
	   Elements in level order form (separated by space)
	   (If any node does not have left or right child, take -1 in its place)
	 */
    BinaryTreeNode<T> *takeInputLevelWiseHelper() {
        T rootData;
        cout << "Enter root data" << endl;
        cin >> rootData;
        if (rootData == -1) { // if data is -1 consider it as no child node.
            return NULL;
        }
        BinaryTreeNode<T> *root = new BinaryTreeNode<T>(rootData);
        queue<BinaryTreeNode<T> *> pendingNodes; // queue used to input levelwise
        pendingNodes.push(root);

        while (pendingNodes.size() != 0) {
            BinaryTreeNode<T> *front = pendingNodes.front();
            pendingNodes.pop();
            cout << "Enter left child of " << front->data << endl;
            T leftChildData;
            cin >> leftChildData;
            if (leftChildData != -1) {
                BinaryTreeNode<T> *child = new BinaryTreeNode<T>(leftChildData);
                front->left = child;
                pendingNodes.push(child); // Push child node for inputing there child nodes.
            }
            cout << "Enter right child of " << front->data << endl;
            T rightChildData;
            cin >> rightChildData;
            if (rightChildData != -1) {
                BinaryTreeNode<T> *child = new BinaryTreeNode<T>(rightChildData);
                front->right = child;
                pendingNodes.push(child); // Push child node for inputing there child nodes.
            }
        }
        return root;
    }

    void takeInputLevelWise() {
        root = takeInputLevelWiseHelper();
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

    void search(T data) {
        if (search(root, data)) {
            cout << "Found!" << endl;
        } else {
            cout << "Not Found!" << endl;
        }
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

    /*
	   Inorder traversal of BST
	 */
    void inOrder(BinaryTreeNode<T> *root) {
        if (root == NULL) {
            return;
        }
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }

    void inOrder() {
        inOrder(root);
    }

    /*
	   Preorder traversal of BST
	 */
    void preOrder(BinaryTreeNode<T> *root) {
        if (root == NULL) {
            return;
        }
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }

    void preOrder() {
        preOrder(root);
    }

    /*
	   Postorder traversal of BST
	 */
    void postOrder(BinaryTreeNode<T> *root) {
        if (root == NULL) {
            return;
        }
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }

    void postOrder() {
        postOrder(root);
    }

    /*
	   Check if the input tree is Binary Search Tree or not.
	 */
    bool isBST(BinaryTreeNode<T> *root, T min = INT_MIN, T max = INT_MAX) {
        if (root == NULL) {
            return true;
        }
        if (root->data < min || root->data >= max) {
            return false;
        }
        bool isLeftOk = isBST(root->left, min, root->data);
        bool isRightOk = isBST(root->right, root->data, max);
        return isLeftOk && isRightOk;
    }

    void isBST() {
        if (isBST(root)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    /*
	   Input BST using sorted array.
	   return root of BST formed.
	 */
    BinaryTreeNode<T> *constructTreeHelper(T *input, T start, T end) {
        if (end < start) {
            return NULL;
        }
        int rootIndex = (start + end) / 2;
        BinaryTreeNode<T> *root = new BinaryTreeNode<T>(input[rootIndex]);
        root->left = constructTreeHelper(input, start, rootIndex - 1);
        root->right = constructTreeHelper(input, rootIndex + 1, end);
        return root;
    }

    void constructTree(T *input, int n) {
        root = constructTreeHelper(input, 0, n - 1);
    }

    /*
	   Minimum element in BST
	 */
    T minimum(BinaryTreeNode<T> *root) {
        if (root == NULL) {
            return INT_MAX;
        }
        return min(root->data, min(minimum(root->left), minimum(root->right)));
    }

    void minimum() {
        cout << minimum(root);
    }

    /*
	   Maximum element in BST
	 */
    T maximum(BinaryTreeNode<T> *root) {
        if (root == NULL) {
            return INT_MIN;
        }
        return max(root->data, max(maximum(root->left), maximum(root->right)));
    }

    void maximum() {
        cout << maximum(root);
    }

    /*
	   Height of BST
	 */
    int height(BinaryTreeNode<T> *root) {
        if (root == NULL) {
            return 0;
        }
        return 1 + max(height(root->left), height(root->right));
    }

    void height() {
        cout << height(root);
    }

    /*
	   Number of nodes in BST
	 */
    int numNodes(BinaryTreeNode<T> *root) {
        if (root == NULL) {
            return 0;
        }
        return 1 + numNodes(root->left) + numNodes(root->right);
    }

    void numNodes() {
        cout << numNodes(root);
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

    tree->search(5);
    cout << endl
         << endl;

    tree->inOrder();
    cout << endl
         << endl;

    tree->preOrder();
    cout << endl
         << endl;

    tree->postOrder();
    cout << endl
         << endl;

    cout << "Is BST : ";
    tree->isBST();
    cout << endl;

    cout << "Height : ";
    tree->height();
    cout << endl;

    cout << "Number of nodes : ";
    tree->numNodes();
    cout << endl;

    cout << "Minimum element : ";
    tree->minimum();
    cout << endl;

    cout << "Maximum element : ";
    tree->maximum();
    cout << endl;

    int input[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(input) / sizeof(input[0]);
    tree->constructTree(input, size);
    tree->printTree();

    tree->takeInputLevelWise();
    tree->printTree();
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

   Found!


   1 3 5 6 8 9

   5 3 1 6 9 8

   1 3 8 9 6 5

   Is BST : Yes

   Height : 4
   Number of nodes : 6
   Minimum element : 1
   Maximum element : 9
   5: L:2,R:8
   2: L:1,R:3
   1:
   3: R:4
   4:
   8: L:6,R:9
   6: R:7
   7:
   9: R:10
   10:
   Enter root data
   1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
   Enter left child of 1
   Enter right child of 1
   Enter left child of 2
   Enter right child of 2
   Enter left child of 3
   Enter right child of 3
   Enter left child of 4
   Enter right child of 4
   Enter left child of 5
   Enter right child of 5
   Enter left child of 6
   Enter right child of 6
   Enter left child of 7
   Enter right child of 7
   Enter left child of 8
   Enter right child of 8
   Enter left child of 9
   Enter right child of 9
   1: L:2,R:3
   2: L:4,R:5
   4:
   5:
   3: L:6,R:7
   6: L:8,R:9
   8:
   9:
   7:
 */
