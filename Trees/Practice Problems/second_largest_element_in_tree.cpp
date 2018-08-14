#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

template <typename T>

class TreeNode {
	public:
	T data;
	vector<TreeNode<T>*> children;

	TreeNode(T data){
		this->data = data;
	}

	~TreeNode() {
		for(int i = 0 ; i < children.size() ; i++){
			delete children[i];
		}
	}
};

TreeNode<int>* takeInputLevelWise(){
	int rootData;
	cout<<"Enter root data : "<<endl;
	cin>>rootData;
	TreeNode<int>* root = new TreeNode<int>(rootData);
	queue<TreeNode<int>*> pendingNodes;
	pendingNodes.push(root);

	while(pendingNodes.size() != 0){
		TreeNode<int>* frontPointer = pendingNodes.front();
		pendingNodes.pop();
		int numChild;
		cout<<"Enter number of child of root "<< frontPointer->data <<":"<<endl;
		cin>>numChild;
		for(int i = 0; i < numChild ; i++){
			int childValue;
			cout<<"Enter value for child " << i + 1 << " : "<<endl;
			cin>>childValue;
			TreeNode<int>* child = new TreeNode<int>(childValue);
			frontPointer->children.push_back(child);
			pendingNodes.push(child);
		}
	}
	return root;
}

TreeNode<int>* secondLargest(TreeNode<int>* root){
	if(root == NULL){
		return NULL;
	}
	int first = INT_MIN;
	int second = INT_MIN;

	TreeNode<int>* max;
	TreeNode<int>* secondMax;

	queue<TreeNode<int>*> pendingNodes;
	pendingNodes.push(root);

	first = root->data;
	max = root;

	while(pendingNodes.size() != 0){

		TreeNode<int>* frontPointer = pendingNodes.front();
		pendingNodes.pop();

		for(int i = 0; i < frontPointer->children.size() ; i++){

			if(frontPointer->children[i]->data > first && frontPointer->children[i]->data > second){
				second = first;
				secondMax = frontPointer;
				first = frontPointer->children[i]->data;
				max = frontPointer->children[i];
			} else if (frontPointer->children[i]->data < first && frontPointer->children[i]->data > second){
					secondMax = frontPointer->children[i];
					second = frontPointer->children[i]->data;
			}
			pendingNodes.push(frontPointer->children[i]);
		}
	}
	return secondMax;
}

/*
   Tree input shortcut just paste any of below lines
   1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 1 9 0

   4 3 3 2 1 2 2 4 1 6 1 7 0 0 0 0
 */
int main(){
	TreeNode<int>* root = takeInputLevelWise();
	cout<<"Second largest: "<<endl;
	TreeNode<int>* secMax;
	secMax = secondLargest(root);
	cout<< secMax->data <<endl;
}
