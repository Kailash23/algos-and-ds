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
	for(int i = 0; i < root->children.size(); i++) {
	    printTree(root->children[i]);				// Recursive call on child nodes
	}
}

int main(){
	TreeNode<int>* root = takeInput();
	cout<<endl;
	printTree(root);
}


/*
   Enter data
   1
   Enter num of children of 1
   3
   Enter data
   2
   Enter num of children of 2
   2
   Enter data
   5
   Enter num of children of 5
   0
   Enter data
   6
   Enter num of children of 6
   0
   Enter data
   3
   Enter num of children of 3
   2
   Enter data
   7
   Enter num of children of 7
   0
   Enter data
   8
   Enter num of children of 8
   1
   Enter data
   9
   Enter num of children of 9
   0
   Enter data
   4
   Enter num of children of 4
   0

   1:2, 3, 4,
   2:5, 6,
   5:
   6:
   3:7, 8,
   7:
   8:9,
   9:
   4:

   			1
	   /    |    \
     2      3      4
   /  \   /   \
  5    6 7     8
         		\
		         9

 */
