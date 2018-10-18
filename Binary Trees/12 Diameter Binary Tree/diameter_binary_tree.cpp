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
		 O	 		   O
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
   Function to calculate height of a binary tree.
   Time Complexity - O(n)
   We are visiting each node of the tree.
   On each node we are checking root == NULL and doing addition (1) to max node.
   Constant work is done. (nk)
 */

int height(BinaryTreeNode<int>* root){
	if(root == NULL) {
		return 0;
	}
	return 1 + max(height(root->left), height(root->right));    // Height will be the 1 + max among (height of left subtree) and (height right subtree).
}

/*
   Function to calculate diameter of binary tree. Diameter of tree not neccessarily
   passes through root.

   Time Complexity - O(n * h)

   We are calling 2 height function for finding diameter and then 2 diameter
   calls on n/2 elements (if balanced tree)
   We are working on n-1 nodes for calculating height as we are not taking root
   in it so (-1 from n).
   So we are doing (kn + k) work for calc height.(+k for base case and max func work)

   				O							 O
			/		\						  \
		  O			  O						    O
		/	\		/	\						 \
	   O 	 O	   O	 O						   O
	   												\
		T(n) = kn + 2T(n/2)							  O
 ~Recurence Relation of Merge Sort					   \
			O(nlogn)			    				     O
														  \
		Height = log(n)						     		  	O
		Work = n * log(n)									 \
															   O

													T(n) = kn + T(n-1)
										 	~Recurence Relation of Bubble Sort
														O(n^2)
													Height = n
													Work = n * n

					So, Time Complexity = O (n * h)
					n -> no of nodes in tree
					h -> height of tree

		Generally, we can acheive O(n) time complexity in tree problems.

 */

/*
   We are repeating same work again and again first root is calling left and right for
   height (option1) and for calc diameter its calling left and right again for height.
   (option1 and option 2). Which inc no of function calls. And thus time complexity.
   Best solution will be if we ask for both height and diameter to left and right at the
   same time.
 */
int diameter(BinaryTreeNode<int>* root){
	if(root == NULL) {
		return 0;
	}

	int option1 = height(root->left) + height(root->right);     // Sum of height of left and right subtree.
	int option2 = diameter(root->left);     // This recursive call will call height function 2 times again. Which leads to inc time complexity.
	int option3 = diameter(root->right);
	return max(option1, max(option2, option3));     // diameter will be the max of option1, option2 & option3.
}

int main(){
	BinaryTreeNode<int>* root = takeInputLevelWise();
	cout << endl;
	cout << "Diameter : " << diameter(root);
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

   Diameter : 5
 */

/*
   Solution:
   1. Calculate leftHeight + rightHeight
   2. Calculate leftDiameter
   3. Calculate rightDiameter
   (Maximum of these will be the answer)
 */

/*
   (Increasing order of time complexity)
   O(1) - constant time
   O(logN) - logarithmic
   O(N) - linear
   O(NlogN) - loglinear
   O(N^2) - quadratic (followed by other polynomial times e.g., O(N3) - cubic, etc.)
   O(2^N) - exponential time
 */
