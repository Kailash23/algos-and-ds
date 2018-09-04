#include <iostream>
#include <queue>
#include "TreeNode.h"

using namespace std;

/*
   Function to take input of generic tree level wise using queue.
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
   Function to return the level having maximum number of node.
   Without using any predefind funstion of TreeNode class.
   TODO: Using Predefinded function
 */
int getMaxNodeIndex(vector<int> v){
	int max = -1;
	int index = -1;
	for(int i = 0 ; i < v.size(); i++){
		int n = v[i];
		if(max < n){
			max = n;
			index = i;
		}
	}
	return index;
}

int maxLevel(TreeNode<int>* root){
	if(root == NULL) {
		return 0;
	}
	vector<int> nodeCount;

	queue<TreeNode<int>*> pendingNodes;
	pendingNodes.push(root);

	while(pendingNodes.size() != 0) {
		int count = pendingNodes.size();
		nodeCount.push_back(count);
		while (count>0) {
			TreeNode<int>* front = pendingNodes.front();
			pendingNodes.pop();
			for(int i=0; i < front->children.size(); i++) {
				pendingNodes.push(front->children[i]);
			}
			count--;
		}
	}
	return getMaxNodeIndex(nodeCount);

}

int main(){
	TreeNode<int>* root = takeInputLevelWise();
	cout<<maxLevel(root);
	delete root;	// This will recursively delete the whole tree.
}


/*
   Quick Input
   1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 1 9 0
 */

/*
  Input:

             1
        /    |    \
      2      3      4
    /  \   /   \
   5    6 7     8
		         \
		          9
  Output:
  2

*/

/*

ALTERNATE SOLUTION

int maxLevel(TreeNode<int>* root){
    if (root == NULL){
        return -1;
    }
    int currNodeCount = 1;
    int level = 0;
    int max = 1;
    int level_no = 0;
    if (root->numChildren() == 0) {
        return level_no;
    }
    queue<TreeNode<int>*> q;
    q.push(root);
    while (!q.empty()) {
        int size = q.size();
        currNodeCount = 0;
        for (int i = 0; i < size; i++) {
            TreeNode<int>* temp = q.front();
            q.pop();
            currNodeCount += temp->numChildren();
            for (int i = 0; i < temp->numChildren(); i++) {
                q.push(temp->getChild(i));
            }
        }
        if (currNodeCount > max) {
            max = currNodeCount;
            level_no = level + 1;
        }
        level++;
    }
    return level_no;
}

*/
