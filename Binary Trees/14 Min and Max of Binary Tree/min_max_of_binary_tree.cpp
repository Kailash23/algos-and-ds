/*
   Min and Max of Binary Tree

   Given a binary tree, find and return the min and max data value of given binary tree.
   Return the output as an object of PairAns class, which is already created.

   Input format :
   Elements in level order form (separated by space)
   (If any node does not have left or right child, take -1 in its place)

   Output Format :
   Max and min (separated by space)

   Sample Input :
   8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1

   Sample Output :
   14 1
 */

#include "BinaryTreeNode.h"
#include <iostream>

using namespace std;

#include <limits.h>
#include <queue>

class PairAns {
  public:
    int min;
    int max;
};

BinaryTreeNode<int> *takeInputLevelWise() {
    int rootData;
    cout << "Enter root data" << endl;
    cin >> rootData;
    if (rootData == -1) { // if data is -1 consider it as no child node.
        return NULL;
    }

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> pendingNodes; // queue used to input levelwise
    pendingNodes.push(root);

    while (pendingNodes.size() != 0) {
        BinaryTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();

        cout << "Enter left child of " << front->data << endl;
        int leftChildData;
        cin >> leftChildData;
        if (leftChildData != -1) {
            BinaryTreeNode<int> *child = new BinaryTreeNode<int>(leftChildData);
            front->left = child;
            pendingNodes.push(child); // Push child node for inputing there child nodes.
        }

        cout << "Enter right child of " << front->data << endl;
        int rightChildData;
        cin >> rightChildData;
        if (rightChildData != -1) {
            BinaryTreeNode<int> *child = new BinaryTreeNode<int>(rightChildData);
            front->right = child;
            pendingNodes.push(child); // Push child node for inputing there child nodes.
        }
    }
    return root;
}

PairAns minMax(BinaryTreeNode<int> *root) {
    if (root == NULL) {
        PairAns pair;
        pair.min = INT_MAX;
        pair.max = INT_MIN;
        return pair;
    }

    PairAns leftAns = minMax(root->left);
    PairAns rightAns = minMax(root->right);

    int lm = leftAns.min;
    int rm = rightAns.min;
    int lM = leftAns.max;
    int rM = rightAns.max;

    int minimum = min(min(lm, rm), root->data);
    int maximum = max(max(lM, rM), root->data);

    PairAns ans;
    ans.min = minimum;
    ans.max = maximum;
    return ans;
}

int main() {
    BinaryTreeNode<int> *root = takeInputLevelWise();
    cout << endl;
    PairAns p = minMax(root);
    cout << "Min: " << p.min << endl;
    cout << "Max: " << p.max << endl;
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
	Min: 1
	Max: 9
 */

/*
	Alternate Solution

	#include <climits>

	PairAns minMax(BinaryTreeNode <int> * root) {
		PairAns p;
		p.min = INT_MAX;
		p.max = INT_MIN;
		if (root == NULL) return p;
		PairAns leftPair = minMax(root->left);
		PairAns rightPair = minMax(root->right);
		p.max = max(max(leftPair.max, rightPair.max), root->data);
		p.min = min(min(leftPair.min, rightPair.min), root->data);
		return p;
	}
*/
