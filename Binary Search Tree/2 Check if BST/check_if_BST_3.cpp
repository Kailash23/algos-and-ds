/*
   Check if a Binary Tree is BST

   Given a binary tree with N number of nodes, check if that input tree is BST
   (Binary Search Tree) or not. If yes, return true, return false otherwise.

   Duplicate elements should be in right subtree.
 */

#include <iostream>
#include "BinaryTreeNode.h"
using namespace std;

#include <queue>
#include <climits>

BinaryTreeNode<int>* takeInputLevelWise() {
	int rootData;
	cout << "Enter root data" << endl;
	cin >> rootData;
	if(rootData == -1) {             // if data is -1 consider it as no child node.
		return NULL;
	}
	BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
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
   Function to check whether tree is BST or not.
   Time Complexity - O(n)
   We are doing only constant work like comparision, making and assigning class object.
   And we are calling recursion on both left and right - 2T(n/2)

		T(n) = 2T(n/2) + k
		=>	O(n)
 */

class IsBSTReturn {
  public:
	bool isBST;
	int maximum;
	int minimum;
};

IsBSTReturn isBST(BinaryTreeNode<int>* root) {
	if(root == NULL) {     // Constant Work
		IsBSTReturn output;
		output.isBST = true;
		output.minimum = INT_MAX;
		output.maximum = INT_MIN;
		return output;
	}
	IsBSTReturn leftOutput = isBST(root->left);       // T(n/2)
	IsBSTReturn rightOutput = isBST(root->right);     // T(n/2)

	int minimum = min(root->data, min(leftOutput.minimum, rightOutput.minimum));       // These 3 lines were doing constant work
	int maximum = max(root->data, max(leftOutput.maximum, rightOutput.maximum));
	bool isBSTFinal = (root->data > leftOutput.maximum) && (root->data <= rightOutput.minimum) && leftOutput.isBST && rightOutput.isBST;

	IsBSTReturn output;        // Constant Work - all lines below
	output.minimum = minimum;
	output.maximum = maximum;
	output.isBST = isBSTFinal;
	return output;
}

int main(){
	BinaryTreeNode<int>* root = takeInputLevelWise();
	IsBSTReturn output;
	output = isBST(root);
	cout << output.isBST;
}

/*
   Quick Input:
   8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
   1
 */
