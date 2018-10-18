/*
        A rooted binary tree is called “nice”, if every node is either a leaf, or has exactly two children.
        For example, the following tree is nice,
                                                          n
                                                        /   \
                                                   l     n
                                                                / \
                                                           n   l
                                                          / \
                                                         l   l
        and the following tree is not,
                                                         n
                                                        / \
                                                  n     n
                                                 /
                                                l
        The leaves of a nice binary tree are labeled by the letter ‘l’, and other nodes are labeled by the letter ‘n’.
        Given the pre-order traversal of a nice binary tree as a string, you are required to find the depth of the tree.
        Output one line for each test case, containing a single integer, the depth of tree.

        Sample Input 1:   nlnll
        Sample Output 1:  2
        Sample Input 2:   nll
        Sample Output 2:  1
 */

#include <iostream>
using namespace std;

int height;
int pos;

void depthHelper(int depth, char str[]){
	pos++;
	height = max(depth, height);
	if(str[pos] == '\0') {
		return;
	}
	if(str[pos] == 'l') {
		return;
	}
	if(str[pos] == 'n') {
		depthHelper(depth+1,str);
		depthHelper(depth+1,str);
	}
}

int depth(char str[]) {
	depthHelper(0,str);
	return height;
}


int main(){
	height = 0;
	pos = -1;
	char str[] = "nnllnll";
	cout<< depth(str);
}
