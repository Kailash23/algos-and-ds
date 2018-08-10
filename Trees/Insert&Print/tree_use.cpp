#include <iostream>
#include "TreeNode.h"
using namespace std;

TreeNode<int>* takeInput(){
	int rootData;
	cout<<"Enter data"<<endl;
	cin>>rootData;
	TreeNode<int>* root = new TreeNode<int>(rootData);

	int numChild;
	cout<<"Enter num of children of " << rootData <<endl;
	cin>>numChild;
	for(int i = 0; i < numChild; i++) {
		TreeNode<int>* child = takeInput();
		root->children.push_back(child);
	}
	return root;
}

void printTree(TreeNode<int>* root) {
	if(root == NULL) {		//Side case
		return;
	}
	cout<< root->data<<":";
	for(int i = 0; i < root->children.size(); i++) {
		cout<< root->children[i]->data <<", ";
	}
	cout<<endl;
	for(int i = 0; i < root->children.size(); i++){
	    printTree(root->children[i]);
	}
}

int main(){
	TreeNode<int>* root = takeInput();
	printTree(root);
}
