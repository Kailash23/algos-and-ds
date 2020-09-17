#include "TreeNode.h"
#include <iostream>
using namespace std;

int main() {
    TreeNode<int> *root = new TreeNode<int>(1);  //root
    TreeNode<int> *node1 = new TreeNode<int>(2); //child
    TreeNode<int> *node2 = new TreeNode<int>(3); //child
    root->children.push_back(node1);             // Making link of child 1 to root (linking means pushback in dynamic array)
    root->children.push_back(node2);             // Making link of child 2 to root
}
