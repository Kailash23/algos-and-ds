#include <iostream>
#include "TreeNode.h"
using namespace std;

/*
   This function will take input in heirrarical order (not level wise)
 */
TreeNode<int>* takeInput(){
	int rootData;
	cout<<"Enter data"<<endl;
	cin>>rootData;
	TreeNode<int>* root = new TreeNode<int>(rootData);		// Creating root node with rootData

	int numChild;
	cout<<"Enter num of children of " << rootData <<endl;
	cin>>numChild;
	for(int i = 0; i < numChild; i++) {
		TreeNode<int>* child = takeInput();		// Creating child node (recursion)
		root->children.push_back(child);		// Creating link (root->child)
	}
	return root;		// return root
}

/*
   Printing will be done in heirarchical order (Recursion is used in order to print in heirarchical)
   root : child 1 , child 2
   child 1 : child 1.1 , child 1.2
   child 1.1 : child 1.1.1 , child 1.1.2
 */
void printTree(TreeNode<int>* root) {
	if(root == NULL) {		//Side case -> if root is NULL return (to avoid this 'root->data')
		return;
	}
	cout<< root->data <<":";
	for(int i = 0; i < root->children.size(); i++) {
		cout<< root->children[i]->data <<", ";		// Displaying child nodes
	}
	cout<<endl;
	for(int i = 0; i < root->children.size(); i++){
	    printTree(root->children[i]);				// Recursive call on child nodes
	}
}

int main(){
	TreeNode<int>* root = takeInput();
	printTree(root);
}
