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

void printTree(BinaryTreeNode<int>* root) {
	if(root == NULL) {               // Base Case
		return;
	}
	cout<< root->data <<":";
	if(root->left != NULL) {         // Check if left exists or not
		cout<< "L" <<root->left->data;
	}
	if( root->right != NULL) {       // Check if left exists or not
		cout<< "R" <<root->right->data;
	}
	cout<<endl;
	printTree(root->left);
	printTree(root->right);
}

int main(){
	BinaryTreeNode<int>* root = takeInputLevelWise();
	cout<<endl;
	printTree(root);
	delete root;
}

/*
						1
					/		\
				  2			  3
				/	\		/	\
			   4	 5	  6  	 7
			   	   /   \
				  8		9


   Enter root data
   1
   Enter left child of 1
   2
   Enter right child of 1
   3
   Enter left child of 2
   4
   Enter right child of 2
   5
   Enter left child of 3
   6
   Enter right child of 3
   7
   Enter left child of 4
   -1
   Enter right child of 4
   -1
   Enter left child of 5
   8
   Enter right child of 5
   9
   Enter left child of 6
   -1
   Enter right child of 6
   -1
   Enter left child of 7
   -1
   Enter right child of 7
   -1
   Enter left child of 8
   -1
   Enter right child of 8
   -1
   Enter left child of 9
   -1
   Enter right child of 9
   -1

   1:L2R3
   2:L4R5
   4:
   5:L8R9
   8:
   9:
   3:L6R7
   6:
   7:
 */
