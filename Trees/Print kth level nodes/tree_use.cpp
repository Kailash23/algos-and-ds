/*
   Second Largest Element In Tree

   Given a generic tree, find and return the node with second largest value in given tree.
   Return NULL if no node with required value is present.
   Input format :

   Line 1 : Elements in level order form separated by space (as per done in class). Order is -

   Root_data, n (No_Of_Child_Of_Root), n children, and so on for every element

   Sample Input 1 :
   10 3 20 30 40 2 40 50 0 0 0 0
   Sample Output 1 :
   40
 */

#include <iostream>
#include <queue>
#include "TreeNode.h"

using namespace std;

/*
   Function to take input level wise using queue
 */
TreeNode<int>* takeInputLevelWise(){
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
   This function will print kth level node (level ~ depth)
   root node is considered as level 0.
   We will call same function on child nodes of theroot by decrementing value
   of level(k) by 1.
   And Display node only if value of k is 0.
 */
void printAtLevelK(TreeNode<int>* root, int k){
	if(root == NULL){		//Side case -> if root is NULL return (to avoid this 'root->data')
		return;
	}

	if(k == 0){
		cout<< root->data <<endl;
		return;
	}

	for(int i=0 ;i < root->children.size(); i++){
		printAtLevelK(root->children[i], k-1);
	}
}

/*
   Printing will done in Level Wise (Queue is used in order to print in level wise)
   root : child 1 , child 2
   child 1 : child 1.1 , child 1.2
   child 2 : child 2.1 , child 2.2
 */
void printTree(TreeNode<int>* root) {

	if(root == NULL) {		//Side case // if root is NULL return (to avoid this 'root->data')
		return;
	}

	queue<TreeNode<int>*> pendingNodes;		// We are maintaining nodes whose child is to be printed (in order to print level wise)
	pendingNodes.push(root);		// Pushing root node to queue

	while(pendingNodes.size() != 0){
		TreeNode<int>* frontPointer = pendingNodes.front();		// Taking front out from queue  (frontPointer is pointing to node which is in front of queue)
		pendingNodes.pop();		// Poping the front node (poping ie deletion is done from front in queue)
		cout<< frontPointer->data <<":";
		for(int i = 0; i < frontPointer->children.size(); i++){
			if(i == frontPointer->children.size()-1){		// if last child node don't print comma at end
            	cout<< frontPointer->children[i]->data;			// Displaying child nodes
          	} else {
		    	cout<< frontPointer->children[i]->data <<",";		// Displaying child nodes
          	}
		}
		cout<<endl;
		for(int i = 0; i < frontPointer->children.size(); i++){
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
	printTree(root);
	int k;
	cout<< "Enter level k :";
	cin>>k;
	printAtLevelK(root, k);
}
