/*
   Construct Tree from Postorder and Inorder

   Given Postorder and Inorder traversal of a binary tree, create the binary
   tree associated with the traversals.You just need to construct the tree and
   return the root.
   Note: Assume binary tree contains only unique elements.

   Input format :
   Line 1 : n (Total number of nodes in binary tree)
   Line 2 : Post order traversal
   Line 3 : Inorder Traversal

   Output Format :
   Elements are printed level wise, each level in new line (separated by space).

   Sample Input :
   8
   8 4 5 2 6 7 3 1
   4 8 2 5 1 6 3 7

   Sample Output :
   1
   2 3
   4 5 6 7
   8
 */

#include "BinaryTreeNode.h"
#include <iostream>
using namespace std;

#include <queue>

void printLevelWise(BinaryTreeNode<int> *root) {
    if (root == NULL) {
        return;
    }

    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);

    while (pendingNodes.size() != 0) {
        BinaryTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();

        cout << front->data << ":";
        if (front->left != NULL) {
            cout << "L:" << front->left->data;
            pendingNodes.push(front->left);
        } else {
            cout << "L:-1";
        }
        if (front->right != NULL) {
            cout << ",R:" << front->right->data;
            pendingNodes.push(front->right);
        } else {
            cout << ",R:-1";
        }
        cout << endl;
    }
}

BinaryTreeNode<int> *buildTreeHelper(int *in, int *pos, int inS, int inE, int posS, int posE) {
    if (inS > inE) { // Means array is empty.
        return NULL;
    }

    int rootData = pos[posE]; // Root of the tree is the last element of postorder traversal array.
    int rootIndex = -1;
    for (int i = inS; i <= inE; i++) {
        if (in[i] == rootData) {
            rootIndex = i;
            break;
        }
    }
    // If rootData is -1 at this point then invalid inputs in array.

    int LinS = inS;
    int LinE = rootIndex - 1;
    int RinS = rootIndex + 1;
    int RinE = inE;
    int LposS = posS;
    int LposE = LposS + (LinE - LinS);
    int RposS = LposE + 1;
    int RposE = posE - 1;
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    root->left = buildTreeHelper(in, pos, LinS, LinE, LposS, LposE);
    root->right = buildTreeHelper(in, pos, RinS, RinE, RposS, RposE);
    return root;
}

/*
						    (rootIndex)
	        (inS)				 R				      (inE)
   Inorder: (LinS) 4 2 5 (LinE) (1) (RinS) 8 6 9 3 7 (RinE)


			   (posS)		             					(posE)
   Postorder:  (LposS) 4 5 2 (LposE) (RposS) 8 9 6 7 3 (RposE) (1)
  			  					                                R

			  Inorder:   4 2 5 1 8 6 9 3 7
		      Postorder: 4 5 2 8 9 6 7 3 1
 */

BinaryTreeNode<int> *getTreeFromPostorderAndInorder(int *postorder, int postLength, int *inorder, int inLength) {
    return buildTreeHelper(inorder, postorder, 0, inLength - 1, 0, postLength - 1);
}

int main() {
    int in[] = {4, 2, 5, 1, 8, 6, 9, 3, 7};
    int post[] = {1, 2, 4, 5, 3, 6, 8, 9, 7};
    int size = sizeof(post) / sizeof(post[0]);
    BinaryTreeNode<int> *root = getTreeFromPostorderAndInorder(post, size, in, size);
    printLevelWise(root);
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

   1:L:2,R:3
   2:L:4,R:5
   3:L:6,R:7
   4:L:-1,R:-1
   5:L:-1,R:-1
   6:L:8,R:9
   7:L:-1,R:-1
   8:L:-1,R:-1
   9:L:-1,R:-1
 */
