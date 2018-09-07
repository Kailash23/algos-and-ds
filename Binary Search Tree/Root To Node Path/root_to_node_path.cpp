/*
Find Path in BST

Given a BST and an integer k. Find and return the path from the node with data k and root (if a node with data k is present in given BST). Return null otherwise.
Assume that BST contains all unique elements.
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

vector<int>* getRootToNodePath(BinaryTreeNode<int>* root, int data){
	if(root == NULL){
		return NULL;
	}

	if(root->data == data){
		vector<int>* output = new vector<int>();
		output->push_back(root->data);
		return output;
	}

	vector<int>* leftOutput = getRootToNodePath(root->left, data);
	if(leftOutput != NULL){
		leftOutput->push_back(root->data);
		return leftOutput;
	}

	vector<int>* rightOutput = getRootToNodePath(root->right, data);
	if(rightOutput != NULL){
		rightOutput->push_back(root->data);
		return rightOutput;
	} else {
		return NULL;
	}
}

int main(){
	BinaryTreeNode<int>* root = takeInputLevelWise();
	vector<int>* result = getRootToNodePath(root,2);
	for(int i=0; i < result->size(); i++){
		cout<< result->at(i)<<" ";
	}
}

/*
   Quick Input:
   8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
   2
 */

/*
   2 5 8
 */
