/*
   Given an integer array A of size n. Find and print all the leaders present in the input array.
   An array element A[i] is called Leader, if all the elements following it (i.e. present at its right)
   are less than or equal to A[i].   Print all the leader elements separated by space and in the same
   order they are present in the input array.

	Sample Input 1 :
	6
	3 12 34 2 0 -1

	Sample Output 1 :
	34 2 0 -1


	Sample Input 2 :
	5
	13 17 5 4 6

	Sample Output 2 :
	17 6

 */

#include <iostream>
using namespace std;

void Leaders(int *arr, int len) {
    int i = 0;
    int flag = 0;
    while (i < len) {
        if (flag == 0) {
            flag = 1;
            while (arr[i] < arr[i + 1] && i < len) {
                i++;
            }
        }
        int j = i + 1;

        while (arr[i] >= arr[j] && j < len) {
            j++;
        }

        if (j == len) {
            cout << arr[i] << " ";
        }
        i++;
    }
}

int main() {
    int arr[] = {3, 12, 34, 2, 34, -1};
    int n = sizeof(arr) / sizeof(arr[0]);
    Leaders(arr, n);
}

/*
	Time Limit Exceeded: Not optimal solution

	void Leaders(int* arr,int len){
		int flag;
		for(int i=0; i<len; i++) {
			flag = 0;
			for(int j=i+1; j<len; j++) {
				if(arr[i]<arr[j]) {
					flag = 1;
				}
			}
			if(flag == 0) {
				cout<<arr[i]<<" ";
			}
		}
	}
*/
