/*
   Construct BST from a Sorted Array

   Given a sorted integer array A of size n which contains all unique elements.
   You need to construct a balanced BST from this input array. Return the root of constructed BST.
 */

#include <iostream>
#include <queue>
#include "BinaryTreeNode.h"
using namespace std;

BinaryTreeNode<int>* constructTreeHelper(int input[], int start, int end){
	if(end<start){
		return NULL;
	}

	int rootIndex = (start+end)/2;

	BinaryTreeNode<int>* root = new BinaryTreeNode<int>(input[rootIndex]);
	root->left = constructTreeHelper(input, start, rootIndex-1);
	root->right = constructTreeHelper(input,rootIndex+1, end);
	return root;
}

BinaryTreeNode<int>* constructTree(int *input, int n) {
	return constructTreeHelper(input,0,n-1);
}

void preOrderTraversal(BinaryTreeNode<int>* root){
	if(root == NULL){
		return;
	}
	cout<< root->data<<" ";
	preOrderTraversal(root->left);
	preOrderTraversal(root->right);
}

int main() {
	int input[] = {1,2,3,4,5,6,7};
	int size = sizeof(input)/sizeof(input[0]);
	BinaryTreeNode<int>* root = constructTree(input, size);
	preOrderTraversal(root);
}


/*
   Quick Input:
   8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
 */

/*
   4 2 1 3 6 5 7
 */
