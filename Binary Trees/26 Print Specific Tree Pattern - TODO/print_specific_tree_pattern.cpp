/*
   Print Specific Tree Pattern

   Given a "complete" binary tree , print the following pattern using its all nodes.
   root element
   first element of second level
   last element of  of second level
   first element of the of the third level
   last element of the third level
   second element of the third level
   second from last element of the third level
   ..... So on.

   Example :
   For tree :

							  1
						  /		  \
					   2	         3
					/	  \	      /   	\
				  4			5    6		 7
   	  	   	  	/   \     /	  \ /	\ /		\
			  8		9	10	 11 12 13 14	15

   The pattern should be:
   1 2 3 4 7 5 6 8 15 9 14 10 13 11 12

   Input Format
   Line 1: Nodes in level order form (separated by space). If any node does not have left or right child, take -1 in its place

   Output Format
   Required pattern

   Constraint
   Given binary tree is complete
   1 <= Number of Nodes <= 10^6
   1 <= value of each node <= 10^8

   Sample Input 1
   1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
   -1 -1 -1 -1 -1 -1

   Sample Output 1
   1 2 3 4 7 5 6 8 15 9 14 10 13 11 12
 */

/*
 template<typename T>

 class BinaryTreeNode {
     public :
     T data;
     BinaryTreeNode<T> *left;
     BinaryTreeNode<T> *right;

     BinaryTreeNode(T data) {
         this -> data = data;
         left = NULL;
         right = NULL;
     }
 };
 */

/*
   Code works only for complete binary tree as is required by the question
 */

#include <queue>

void printSpecificPattern(BinaryTreeNode<int> *root) {

    if (root == NULL) {
        return;
    }
    cout << root->data << " ";

    //Create an two empty queues and enqueue root's left and right child respectively
    queue<BinaryTreeNode<int> *> Q1, Q2;

    if (root->left != NULL) {
        Q1.push(root->left);
    }

    if (root->right != NULL) {
        Q2.push(root->right);
    }

    // Run till queue is not empty

    while (!Q1.empty() || !Q2.empty()) {

        //Calc no of nodes in current level
        int n1 = Q1.size();
        int n2 = Q2.size();

        // process every nodes in current level
        while (n1 > 0 || n2 > 0) {
            if (n1 > 0) {

                // pop front node from first queue and print it
                BinaryTreeNode<int> *x = Q1.front();
                Q1.pop();

                cout << x->data << " ";

                //push left and right child of x to first queue
                if (x->left != NULL) {
                    Q1.push(x->left);
                }

                if (x->right != NULL) {
                    Q1.push(x->right);
                }
                n1--;
            }
            if (n2 > 0) {
                //pop front node from second queue and print it
                BinaryTreeNode<int> *y = Q2.front();
                Q2.pop();

                cout << y->data << " ";

                //push right and left child of y to second queue
                if (y->right != NULL) {
                    Q2.push(y->right);
                }

                if (y->left != NULL) {
                    Q2.push(y->left);
                }
                n2--;
            }
        }
    }
}
