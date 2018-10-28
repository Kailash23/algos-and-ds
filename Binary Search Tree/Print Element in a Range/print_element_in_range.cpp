/*
   Code: Print Elements in Range

   Given a Binary Search Tree and two integers k1 and k2, find and print the
   elements which are in range k1 and k2 (both inclusive).
   Print the elements in increasing order.

   Input format :
   Line 1 : Elements in level order form (separated by space)
   (If any node does not have left or right child, take -1 in its place)
   Line 2 : Two Integers k1 and k2
   Output Format :
   Required elements (separated by space)

   Sample Input :
   8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
   6 10
   Sample Output :
   6 7 8 10
 */

#include <iostream>
#include "BinaryTreeNode.h"
using namespace std;

#include <queue>

BinaryTreeNode<int>* takeInputLevelWise() {
	int rootData;
	cout << "Enter root data : " << endl;
	cin >> rootData;
	if(rootData == -1) {
		return NULL;
	}
	BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
	queue<BinaryTreeNode<int>*> pendingNodes;
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
			pendingNodes.push(child);
		}
		cout << "Enter right child of " << root->data << endl;
		int rightChildData;
		cin >> rightChildData;
		if(rightChildData != -1) {
			BinaryTreeNode<int>* child = new BinaryTreeNode<int>(rightChildData);
			front->right = child;
			pendingNodes.push(child);
		}
	}
	return root;
}

/*
   This method is applicatble to only binary saearch tree.
   Optimized solution- as we dont need to traverse all nodes.
   But this will not give output in acending order.
 */
void elementsInRangeK1K2(BinaryTreeNode<int>* root, int k1, int k2) {
	if(root == NULL){
		return;
	}
	if(root->data >= k1 && root->data <= k2){
		cout << root->data << " ";
	}
	if(root->data > k1){
		elementsInRangeK1K2(root->left, k1, k2);
	}
	if(root->data <= k2){
		elementsInRangeK1K2(root->right, k1, k2);
	}
}

int main() {
	BinaryTreeNode<int>* root = takeInputLevelWise();
	int k1 = 6;
	int k2 = 10;
	elementsInRangeK1K2(root, k1, k2);
}


/*
   Quick Input:
   8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
   k1 = 6
   k2 = 10

   6 7 8 10
 */

 /*
	This method is applicatble for both binary and binary search tree as it
	traversing all the node of tree and doing comparision.

	void elementsInRangeK1K2(BinaryTreeNode<int>* root, int k1,int k2){
		if(root == NULL) {
			return;
		}
		elementsInRangeK1K2(root->left, k1, k2);
		if(k1 <= root->data && root->data <= k2) {
			cout << root->data << " ";
		}
		elementsInRangeK1K2(root->right, k1, k2);
	}
  */

/*

   void elementsInRangeK1K2(BinaryTreeNode<int>* root, int k1, int k2){
	    if(root == NULL){
	        return;
	    }
	    if(root->data >= k1 && root->data<=k2){
	        elementsInRangeK1K2(root->left, k1, k2);
	        cout << root->data << " ";
	        elementsInRangeK1K2(root->right, k1, k2);
	        return;
	    }
	    if(root->data < k1){
	        elementsInRangeK1K2(root->right, k1, k2);
	        return;
	    }
	    if(root->data >= k2){
	        elementsInRangeK1K2(root->left, k1, k2);
	        return;
	    }
   }
 */
