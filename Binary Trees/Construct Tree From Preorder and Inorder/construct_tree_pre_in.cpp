/*
   Code: Construct Tree from Preorder and Inorder

   Given Preorder and Inorder traversal of a binary tree, create the binary tree
   associated with the traversals.You just need to construct the tree and return the root.
   Note: Assume binary tree contains only unique elements.
   Input format :

   Line 1 : n (Total number of nodes in binary tree)
   Line 2 : Pre order traversal
   Line 3 : Inorder Traversal

   Output Format :
   Elements are printed level wise, each level in new line (separated by space).

   Sample Input :
   12
   1 2 3 4 15 5 6 7 8 10 9 12
   4 15 3 2 5 1 6 10 8 7 9 12

   Sample Output :
   1
   2 6
   3 5 7
   4 8 9
   15 10 12
 */

#include <iostream>
#include "BinaryTreeNode.h"
#include <queue>
using namespace std;

void printLevelWise(BinaryTreeNode<int>* root) {
	if(root == NULL) {
		return;
	}

	queue<BinaryTreeNode<int>*> pendingNodes;
	pendingNodes.push(root);

	while(pendingNodes.size() != 0) {
		BinaryTreeNode<int>* front = pendingNodes.front();
		pendingNodes.pop();

		cout<<front->data<<":";
		if(front->left != NULL) {
			cout<<"L:"<<front->left->data;
			pendingNodes.push(front->left);
		} else {
			cout<<"L:-1";
		}
		if(front->right != NULL) {
			cout<<",R:"<<front->right->data;
			pendingNodes.push(front->right);
		} else {
			cout<<",R:-1";
		}
		cout<<endl;
	}
}

BinaryTreeNode<int>* buildTreeHelper(int* in, int* pre, int inS, int inE, int preS, int preE){
	if(inS > inE) {      // Means array is empty.
		return NULL;
	}

	int rootData = pre[preS];       // Root of the tree is the first element of preorder traversal array.(don't use 0 (index))
	int rootIndex = -1;
	for(int i = inS; i <= inE; i++) {
		if(in[i] == rootData) {
			rootIndex = i;
			break;
		}
	}
	// If rootData is -1 at this point then invalid inputs in array.
	int LinS = inS;
	int LinE = rootIndex - 1;
	int RinS = rootIndex + 1;
	int RinE = inE;
	int LpreS = preS + 1;
	int LpreE = LpreS + (LinE - LinS);
	int RpreS = LpreE + 1;
	int RpreE = preE;
	BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
	root->left = buildTreeHelper(in, pre, LinS, LinE, LpreS, LpreE);
	root->right = buildTreeHelper(in, pre, RinS, RinE, RpreS, RpreE);
	return root;
}

/*
						    (rootIndex)
			(inS)				 R				      (inE)
   Inorder: (LinS) 4 2 5 (LinE) (1) (RinS) 8 6 9 3 7 (RinE)

   			 (preS)										 (preE)
   Preorder: (1) (LpreS) 2 4 5 (LpreE) (RpreS) 3 6 8 9 7 (RpreE)
  			  R

 */

BinaryTreeNode<int>* buildTree(int *preorder, int preLenght, int *inorder, int inLength) {
	return buildTreeHelper(inorder, preorder, 0, inLength-1, 0, preLenght-1);
}

int main(){
	int in[] = {4,2,5,1,8,6,9,3,7};
	int pre[] = {1,2,4,5,3,6,8,9,7};
	int size = sizeof(pre)/sizeof(pre[0]);
	BinaryTreeNode<int>* root = buildTree(pre, size, in, size);
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

 // Alternate Solution

 // BinaryTreeNode<int>* construct(int* preorder, int preStart, int preEnd, int* inorder, int inStart, int inEnd) {
 // 	if (preStart > preEnd || inStart > inEnd) {
 // 		return NULL;
 // 	}
 // 	int val = preorder[preStart];
 // 	BinaryTreeNode<int>* p = new BinaryTreeNode<int>(val);
 // 	int k = 0;
 // 	for (int i = inStart; i <= inEnd; i++) {
 // 		if (val == inorder[i]) {
 // 			k = i;
 // 			break;
 // 		}
 // 	}
 // 	p->left = construct(preorder, preStart + 1, preStart + (k - inStart), inorder, inStart, k - 1);
 // 	p->right = construct(preorder, preStart + (k - inStart) + 1, preEnd, inorder, k + 1, inEnd);
 // 	return p;
 // }
 //
 // BinaryTreeNode<int>* buildTree(int* preorder, int preLenght, int* inorder, int inLength){
 // 	int preStart = 0;
 // 	int preEnd = preLenght - 1;
 // 	int inStart = 0;
 // 	int inEnd = inLength - 1;
 // 	return construct(preorder, preStart, preEnd, inorder, inStart, inEnd);
 // }
