/*
   Longest Leaf to root path

   Given a binary tree, return the longest path from leaf to root. Longest means, a path which contain maximum number of nodes from leaf to root.
   Input format :

   Elements in level order form (separated by space)

   (If any node does not have left or right child, take -1 in its place)

   Line 1 : Binary Tree 1 (separated by space)

   Sample Input 1 :
   5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1

   Sample Output 1 :
   9
   3
   6
   5
 */

#include <iostream>
#include "BinaryTreeNode.h"
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<int> > ans;

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

void printPath(vector<int> vec){
	for(int i = 0; i < vec.size(); i++) {
		cout<< vec[i] <<endl;
	}
}

vector<int>* findMaxPathVector(){
	int maxSize = -1;
	vector<int>* maxVec;
	for(int i= 0; i < ans.size(); i++) {
		int size = ans[i].size();
		if(maxSize < size) {
			maxSize = ans[i].size();
			maxVec = &ans[i];
		}
	}
	reverse(maxVec->begin(), maxVec->end());
	return maxVec;
}

void longestPathHelper(BinaryTreeNode<int>* root, vector<int> path){
	if(root == NULL) {
		return;
	}
	path.push_back(root->data);
	if(root->left == NULL && root->right == NULL) {
		ans.push_back(path);
	} else {
		longestPathHelper(root->left, path);
		longestPathHelper(root->right, path);
	}
}

vector<int>* longestPath(BinaryTreeNode<int>* root) {
	vector<int> path;
	longestPathHelper(root, path);
	return findMaxPathVector();
}

int main(){
	BinaryTreeNode<int>* root = takeInputLevelWise();
	cout<<endl;
	vector<int>* result;
	result = longestPath(root);
	printPath(*result);
	delete root;
}

/*
   Quick Input:
   1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
 */

/*
                                1
                            /		\
                          2			  3
                        /	\		/	\
                       4	 5	  6      7
                                /   \
                               8	 9

         8
         6
         3
         1


 */

/*
Alternate Solution

	vector<int>* longestPath(BinaryTreeNode<int>* root){
		if (root == NULL) {
			return NULL;
		}
		if (!root->left && !root->right) {
			vector<int>* output = new vector<int>();
			output->push_back(root->data);
			return output;
		}
		vector<int>* leftAns = longestPath(root->left);
		vector<int>* rightAns = longestPath(root->right);
		if (!leftAns) {
			rightAns->push_back(root->data);
			return rightAns;
		}
		else if (!rightAns) {
			leftAns->push_back(root->data);
			return leftAns;
		}
		else {
			if (leftAns->size() < rightAns->size()) {
				rightAns->push_back(root->data);
				delete leftAns;
				return rightAns;
			}
			else {
				leftAns->push_back(root->data);
				delete rightAns;
				return leftAns;
			}
		}
	}

*/
