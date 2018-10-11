/*
   Code : Diameter of Binary Tree

   The diameter of a tree (sometimes called the width) is the number of nodes on
   the longest path between two end nodes.

   				   O
				 /   \
				O      O   Diameter - 6
		      /	  \
			 O 	   O
		    / 		\
		   O		 O
		  /			  \
		 O	 			O
 */

#include <iostream>
#include "BinaryTreeNode.h"
using namespace std;

#include <queue>

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
			pendingNodes.push(child);            // Push child node for inputing there child nodes.
		}
	}
	return root;
}

/*
   Function to calculate diameter and height of binary tree.
   Time Complexity - O(n)
 */

pair<int, int> heightDiameter(BinaryTreeNode<int>* root){
	if(root == NULL){		// If tree is NULL then we will return pair having height and diameter as 0. (Constant work in comparision)
		pair<int, int> p;
		p.first = 0;	// Height
		p.second = 0;	// Diameter
		return p;
	}

	pair<int,int> leftAns = heightDiameter(root->left);		// Recursive call to the left subtree asking for pair of height and diameter.
	pair<int,int> rightAns = heightDiameter(root->right);		// Recursive call to the right subtree asking for pair of height and diameter.

	int ld = leftAns.second;		// Extracting values from above pairs (Constant work)
	int lh = leftAns.first;
	int rd = rightAns.second;
	int rh = rightAns.first;

	int height = 1 + max(lh, rh);		// Height will be 1 + max of (left subtree height , right subtree height)
	int diameter = max(lh + rh, max(ld, rd));	// Diameter will be the max of (sum of height of left subtree and right subtree, left subtree diameter & right subtree diameter)

	pair<int, int> p;		// pair - Inbuild class  max - inbuild function
	p.first = height;
	p.second = diameter;
	return p;
}

int main(){
	BinaryTreeNode<int>* root = takeInputLevelWise();
	cout << endl;
	pair<int, int> p = heightDiameter(root);
	cout << "Height: " << p.first <<endl;
	cout << "Diameter: " << p.second <<endl;
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

	Height: 4
	Diameter: 5

 */

/*
   Solution:

   1. Base Case:
   		NULL -> 0,0

   2. Hypothesis
   		ld,lh,rd,rh

   3.
   	  h = 1 + max (lh,rh)
	  d = max(lh + rh, ld, rd)

 */
