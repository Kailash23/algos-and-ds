#include <iostream>
#include <queue>
#include "TreeNode.h"

using namespace std;

/*
   Function to take input level wise using queue
 */
TreeNode<int>* takeInputLevelWise() {
	int rootData;
	cout<< "Enter root data: " <<endl;
	cin >> rootData;
	TreeNode<int>* root = new TreeNode<int>(rootData);		// Creating root node
	queue<TreeNode<int>*> pendingNodes;		// for taking input level wise we are using queue data structure having element of type TreeNode<int>*
	pendingNodes.push(root);		// Adding root node into queue for processing

	while (pendingNodes.size() != 0) {		// we can also queue's empty function
		TreeNode<int>* frontPointer = pendingNodes.front();		// Storing node at front of queue to frontPointer pointer of type TreeNode<T>* (frontPointer pointing to node in front of queue)
		pendingNodes.pop();		// Poping the front element
		cout<< "Enter num of children of " << frontPointer->data <<" : "<<endl;
		int numChild;
		cin >> numChild;
		for(int i = 0; i < numChild; i++) {
			int childData;
			cout<< "Enter child '"<< i+1 <<"' of "<< frontPointer->data <<" : "<<endl;
			cin >> childData;
			TreeNode<int>* child = new TreeNode<int>(childData);		// Creating child node
			frontPointer->children.push_back(child);		// Creating link between root and child
			pendingNodes.push(child);		//Pushing child nodes created into queue for there processing
		}
	}
	return root;
}

/*
   Pre-Order Traversal of genric tree using recursion.
 */
void preOrder(TreeNode<int>* root){
	if(root == NULL){
		return;
	}
	cout<<root->data<<" ";
	for(int i=0 ; i < root->children.size() ; i++){
		preOrder(root->children[i]);
	}
}

/*
   Post-Order Traversal of genric tree using recursion.
 */
void postOrder(TreeNode<int>* root){
	if(root == NULL){
		return;
	}
	for(int i=0 ; i < root->children.size() ; i++){
		postOrder(root->children[i]);
	}
	cout<<root->data<<" ";
}

/*
   In-Order Traversal of genric tree using queue.
 */
void inOrder(TreeNode<int>* root){
	if(root == NULL){
		return;
	}
	queue<TreeNode<int>*> pendingNodes;
	pendingNodes.push(root);

	while(pendingNodes.size() != 0){
		TreeNode<int>* frontPointer = pendingNodes.front();
		pendingNodes.pop();
		cout<<frontPointer->data<<" ";
		for(int i = 0 ; i < frontPointer->children.size() ; i++){
			pendingNodes.push(frontPointer->children[i]);
		}
	}
}

/*
   Tree input shortcut just paste below line
   1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 1 9 0
 */

int main(){
	TreeNode<int>* root = takeInputLevelWise();
	cout<< "Pre-order:";
	preOrder(root);
	cout<<"\nPost-order:";
	postOrder(root);
	cout<< "\nIn-order:";
	inOrder(root);
}
