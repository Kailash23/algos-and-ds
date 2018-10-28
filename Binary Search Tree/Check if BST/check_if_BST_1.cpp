/*
   Check if a Binary Tree is BST

   Given a binary tree with N number of nodes, check if that input tree is BST
   (Binary Search Tree) or not. If yes, return true, return false otherwise.

   Duplicate elements should be in right subtree.
 */

#include <iostream>
#include "BinaryTreeNode.h"
using namespace std;
using namespace std::chrono;

#include<climits>
#include <queue>
#include <chrono>

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

vector<int> bst;

bool checkVector(vector<int> vec){
	for(int i = 1; i < vec.size(); i++){
	    if(!(vec[i - 1] < vec[i])){
			return false;
		}
	}
	return true;
}

void inOrderBST(BinaryTreeNode<int>* root) {
	if(root == NULL){
		return;
	}
	inOrderBST(root->left);
	bst.push_back(root->data);
	inOrderBST(root->right);
}

bool isBST(BinaryTreeNode<int> *root){
	inOrderBST(root);
	return checkVector(bst);
}

int main(){
	BinaryTreeNode<int>* root = takeInputLevelWise();
    auto start = high_resolution_clock::now();
	bool ans = isBST(root);
	auto stop = high_resolution_clock::now();
 	auto duration = duration_cast<microseconds>(stop - start);
	cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
	if(ans){
		cout << "It's BST!";
	} else {
		cout << "It's not BST!";
	}
}

/*
   Quick Input:
   8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
   It's BST!
 */

/*
   Solution:
   Do inorder traversal of the BST and store the elments one by one in an array.
   The array will now contain sorted elements of tree in ascending order if its a BST.
   If not in acending order its not BST.
 */



/*
	bool checkBst(BinaryTreeNode < int > * root, int minima, int maxima) {
		if (root == NULL) {
			return true;
		}
		if (root->data < minima || root->data > maxima) return false;
		bool leftSearch = checkBst(root->left, minima, root->data);
		bool rightSearch = checkBst(root->right, root->data, maxima);
		return leftSearch & rightSearch;
	}

	bool isBST(BinaryTreeNode <int>* root) {
		return checkBst(root, INT_MIN, INT_MAX);
	}
 */
