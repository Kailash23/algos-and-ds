/*
   Code : Mirror

   Mirror the given binary tree. That is, right child of every nodes should become
   left and left should become right.

   Note : You don't need to print or return the tree, just mirror it.

   Input format :
   Line 1 : Elements in level order form (separated by space)
   (If any node does not have left or right child, take -1 in its place)

   Output format : Elements in level order form (Every level in new line)
 */

#include <iostream>
#include "BinaryTreeNode.h"
#include <queue>
using namespace std;

BinaryTreeNode<int>* takeInputLevelWise() {
	int rootData;
	cout<<"Enter root data"<<endl;
	cin>>rootData;
	if(rootData == -1) {             // if data is -1 consider it as no child node.
		return NULL;
	}

	BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
	queue<BinaryTreeNode<int>*> pendingNodes;               // queue used to input levelwise
	pendingNodes.push(root);

	while(pendingNodes.size() != 0) {
		BinaryTreeNode<int>* front = pendingNodes.front();
		pendingNodes.pop();

		cout<< "Enter left child of "<<front->data <<endl;
		int leftChildData;
		cin>>leftChildData;
		if(leftChildData != -1) {
			BinaryTreeNode<int>* child = new BinaryTreeNode<int>(leftChildData);
			front->left = child;
			pendingNodes.push(child);               // Push child node for inputing there child nodes.
		}

		cout<< "Enter right child of "<< front->data <<endl;
		int rightChildData;
		cin>>rightChildData;
		if(rightChildData != -1) {
			BinaryTreeNode<int>* child = new BinaryTreeNode<int>(rightChildData);
			front->right = child;
			pendingNodes.push(child);               // Push child node for inputing there child nodes.
		}
	}
	return root;
}

void mirrorBinaryTree(BinaryTreeNode<int>* root) {
	if(root == NULL) {
		return;
	}
	BinaryTreeNode<int>* temp = root->left;
	root->left = root->right;
	root->right = temp;
	mirrorBinaryTree(root->left);
	mirrorBinaryTree(root->right);
}

int main(){
	BinaryTreeNode<int>* root = takeInputLevelWise();
	cout<<"\nHeight of Binary Tree : "<<height(root);
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

							   |

							    1
						   /		\
						 3			  2
					   /	\		/	\
					  5	     4	  7      6
							   /   \
							  9	    8

	Height of Binary Tree :4
 */


//Alternate Solution (Mirror Tree)

// void mirrorBinaryTree(BinaryTreeNode<int>* root) {
//     if (root == NULL)
//         return;
//     if (root->left == NULL && root->right == NULL)
//         return;
//     mirrorBinaryTree(root->left);
//     mirrorBinaryTree(root->right);
//     BinaryTreeNode<int>* templeft = root->left;
//     root->left = root->right;
//     root->right = templeft;
// }
