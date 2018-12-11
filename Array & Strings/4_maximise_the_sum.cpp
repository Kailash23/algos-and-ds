/*
   Given 2 sorted arrays (in increasing order), find a path through the intersections
   that produces maximum sum and return the maximum sum. That is, we can switch from
   one array to another array only at common elements.If no intersection element is
   present, we need to take sum of all elements from the array with greater sum.

    Sample Input :
    6
    1 5 10 15 20 25
    5
    2 4 5 9 15

    Sample Output :
    81
 */

#include <iostream>
using namespace std;

long maxPathSum(int ar1[], int ar2[], int m, int n){
	long maxSum = 0, s1 = 0, s2 = 0;
	int i = 0, j = 0;

	while(i < m && j < n) {
		if(ar1[i] < ar2[j]) {
			s1 += ar1[i++];
		} else if(ar1[i] == ar2[j]) {
			s1 += ar1[i++];
			s2 += ar2[j++];
			maxSum += max(s1,s2);
			s1 = 0;
			s2 = 0;
		} else {
			s2 += ar2[j++];
		}
		cout << s1 << ":" << s2 << endl;
	}

	while (i < m) {
		s1 += ar1[i];
		i++;
	}

	while (j < n) {
		s2 += ar2[j];
		j++;
	}
	maxSum += max(s1,s2);
	return maxSum;
}

int main(){
	int ar1[] = {2,2,5,4,6,7};
	int m = sizeof(ar1) / sizeof(ar1[0]);

	int ar2[] = {1,9,5,3,3,0};
	int n = sizeof(ar2) / sizeof(ar2[0]);

	cout << maxPathSum(ar1, ar2, m, n);
}

/*
   81

   We start from array 2 and take sum till 5 (sum = 11). Then we'll switch to array at element 10 and take till 15. So sum = 36. Now, no elements left in array after 15, so we'll continue in array 1. Hence sum is 81
 */
