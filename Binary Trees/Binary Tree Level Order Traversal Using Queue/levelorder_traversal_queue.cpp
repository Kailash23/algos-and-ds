/*
   Print Level Order Traversal line by line

   Given a binary tree, print level order traversal in a way that nodes of all levels are printed in separate lines.
 */

#include <iostream>
#include "BinaryTreeNode.h"
#include <queue>
using namespace std;

BinaryTreeNode<int>* takeInputLevelWise() {
	int rootData;
	cout << "Enter root data" << endl;
	cin >> rootData;
	if(rootData == -1) {             // if data is -1 consider it as no child node.
		return NULL;
	}
	BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);		// Root node creation

	queue<BinaryTreeNode<int>*> pendingNodes;               // queue used to input levelwise
	pendingNodes.push(root);

	while(pendingNodes.size() != 0) {
		BinaryTreeNode<int>* front = pendingNodes.front();
		pendingNodes.pop();

		cout << "Enter left child of " << front->data << endl;
		int leftChildData;
		cin >> leftChildData;
		if(leftChildData != -1) {
			BinaryTreeNode<int>* child = new BinaryTreeNode<int>(leftChildData);
			front->left = child;
			pendingNodes.push(child);               // Push child node for inputing there child nodes.
		}

		cout << "Enter right child of " << front->data << endl;
		int rightChildData;
		cin >> rightChildData;
		if(rightChildData != -1) {
			BinaryTreeNode<int>* child = new BinaryTreeNode<int>(rightChildData);
			front->right = child;
			pendingNodes.push(child);               // Push child node for inputing there child nodes.
		}
	}
	return root;
}

/*
   Time Complexity : O(n)
 */
void printLevelOrder(BinaryTreeNode<int>* root){
	if(root == NULL) {
		return;
	}
	queue<BinaryTreeNode<int>*> pendingNodes;
	pendingNodes.push(root);

	while(pendingNodes.size() != 0) {
		int nodeCount = pendingNodes.size();
		while(nodeCount > 0) {
			BinaryTreeNode<int>* front = pendingNodes.front();
			pendingNodes.pop();
			cout << front->data << " ";
			if(front->left != NULL) {
				pendingNodes.push(front->left);
			}
			if(front->right != NULL) {
				pendingNodes.push(front->right);
			}
			nodeCount--;
		}
		cout << endl;
	}
}

int main(){
	BinaryTreeNode<int>* root = takeInputLevelWise();
	printLevelOrder(root);
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
   1
   2 3
   4 5 6 7
   8 9
 */
