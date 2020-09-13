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

#include <cstring>
#include <iostream>
using namespace std;

int i = 0;

int depthHelper(char str[]) {
    if (strlen(str) <= i) {
        return 0;
    }
    if (str[i] == 'l') {
        return 1;
    }
    i++;
    int dep1 = 1 + depthHelper(str);
    i++;
    int dep2 = 1 + depthHelper(str);
    return max(dep1, dep2);
}

int depth(char str[]) {
    return depthHelper(str) - 1;
}

int main() {
    char str[] = "nnllnll";
    cout << depth(str);
}
