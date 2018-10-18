#include <iostream>
#include "BinaryTreeNode.h"
using namespace std;

#include <queue>

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

void PrintDiagonal(BinaryTreeNode<int>* root) {
	if (root == NULL) {
		return;
	}
	queue<BinaryTreeNode<int>*> q;
	while (root != NULL) {
		cout << root->data << " ";
		if (root->left) {
			q.push(root->left);
		}
		root = root->right;
	}
	cout << endl;
	while (!q.empty()) {
		int size = q.size();
		while (size > 0) {
			root = q.front();
			q.pop();
			while (root != NULL) {
				cout << root->data << " ";
				if (root->left) {
					q.push(root->left);
				}
				root = root->right;
			}
			size--;
		}
		cout << endl;
	}
	cout << endl;
}

int main(){
	BinaryTreeNode<int>* root = takeInputLevelWise();
	PrintDiagonal(root);
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
   1 3 7
   2 5 6 9
   4 8
 */



/* Alternate Solution (Taking too much time)

   void PrintDiagonal(BinaryTreeNode<int>* root) {
        queue<BinaryTreeNode<int>*> q;
        BinaryTreeNode<int>* dummyNode;

        while(root){
                q.push(root);
                root = root->right;
        }

        q.push(dummyNode);

        while(q.size() != 1){
                BinaryTreeNode<int>* front = q.front();
                q.pop();
                if(front != dummyNode){
                        cout<< front->data <<" ";
                        BinaryTreeNode<int>* node = front->left;
                        while(node){
                                q.push(node);
                                node = node->right;
                        }
                } else {
                        q.push(dummyNode);
                        cout<<endl;
                }
        }
   }
 */



/* Alternate Solution

 void PrintDiagonal(BinaryTreeNode<int>* root) {
	if(root == NULL) {
		return;
	}
	queue<BinaryTreeNode<int>*> q;
	q.push(root);
	while(q.back()->right) {
		q.push(q.back()->right);
	}
	while(!q.empty()) {
		if(q.front()->left) {
			q.push(q.front()->left);
			while (q.back()->right) {
				q.push(q.back()->right);
			}
		}
		cout<< q.front()->data <<" ";
		q.pop();
	}
}
 */
