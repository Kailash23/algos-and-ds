/*
   Print Level Order Traversal line by line

   Given a binary tree, print level order traversal in a way that nodes of all levels are printed in separate lines.
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


/*
	Time Complexity of this solution is O(n^2)
*/
int height(BinaryTreeNode<int>* root){
	if(root == NULL) {
		return 0;
	}
	return 1 + max(height(root->left), height(root->right));
}

void printLevelOrderHelper(BinaryTreeNode<int>* root, int level){
	if(root == NULL) {
		return;
	}
	if(level == 1) {
		cout<<root->data<<" ";
	} else if(level > 1) {
		printLevelOrderHelper(root->left, level-1);
		printLevelOrderHelper(root->right, level-1);
	}

}

void printLevelOrder(BinaryTreeNode<int>* root){
	int h = height(root);
	for(int i = 1; i <= h; i++) {
		printLevelOrderHelper(root,i);
		cout<<endl;
	}
}

int main(){
	BinaryTreeNode<int>* root = takeInputLevelWise();
	printLevelOrder(root);
	delete root;
}

/*
   Quick Input:
   1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
 */

/*
   Input:
                                1
                            /		\
                          2			  3
                        /	\		/	\
                       4	 5	  6      7
                                /   \
                               8	 9

 */

/*
   1
   2 3
   4 5 6 7
   8 9
 */
