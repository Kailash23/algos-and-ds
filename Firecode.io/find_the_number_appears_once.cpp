/*
Write a method that returns a number that appears only once in an array.
Assume the array will surely have a unique value. If the array is empty return 0.
Examples:

{1,2,3,4,1,2,4,3,5} ==> 5
 */

int single_number(int arr[], int sz){
	int k = 0;
	for(int i = 0; i < sz; i++) {
		k = k ^ arr[i];
	}
	return k;
}
