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

int main(){
	BinaryTreeNode<int>* root = takeInputLevelWise();
	cout<<endl;
	printLevelWise(root);
	delete root;
}

/*
                                1
                            /		\
                          2			  3
                        /	\		/	\
                       4	 5	  6      7
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

	1:L:2,R:3
	2:L:4,R:5
	3:L:6,R:7
	4:L:-1,R:-1
	5:L:8,R:9
	6:L:-1,R:-1
	7:L:-1,R:-1
	8:L:-1,R:-1
	9:L:-1,R:-1
 */


// ALTERNATE SOLUTION

// void printLevelWise(BinaryTreeNode<int>* root) {
// 	if (root == NULL){
// 		return;
// 	}
// 	queue<BinaryTreeNode<int>*> q;
// 	q.push(root);
// 	while (!q.empty()) {
// 		BinaryTreeNode<int>* node = q.front();
// 		q.pop();
// 		if (node == NULL) {
// 			cout << endl;
// 			if (!q.empty())
// 				q.push(NULL);
// 		}
// 		else {
// 			cout << node->data << ":";
// 			cout << "L:";
// 			if (node->left) {
// 				q.push(node->left);
// 				cout << node->left->data << ",";
// 			}
// 			else {
// 				cout << -1 << ",";
// 			}
// 			cout << "R:";
// 			if (node->right) {
// 				q.push(node->right);
// 				cout << node->right->data << endl;
// 			}
// 			else {
// 				cout << -1 << endl;
// 			}
// 		}
// 	}
// }
