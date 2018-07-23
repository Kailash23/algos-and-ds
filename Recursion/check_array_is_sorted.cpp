#include<iostream>
using namespace std;
//1 One way
bool is_sorted(int a[], int size){
	if(size == 0 || size == 1){
		return true;
	}

	if(a[0]>a[1]){
		return false;
	}

	bool isSmallerSorted = is_sorted(a + 1, size -1);
	return isSmallerSorted;
}

//Another way
bool is_sorted2(int a[], int size){
	if(size == 0 || size == 1){
		return true;
	}

	bool isSmallerSorted = is_sorted2(a+1,size-1);
	if(!isSmallerSorted){
		return true;
	} else {
		return false;
	}
}

int main(){
int arr[] = {2,5,6,8,9,10,1};
int n = sizeof(arr)/sizeof(arr[0]);
bool is = is_sorted(arr,n);
is?cout<<"Array is sorted! ":cout<<"Array is not sorted"<<endl;
bool is2 = is_sorted2(arr,n);
is?cout<<"Array is sorted! ":cout<<"Array is not sorted"<<endl;
}
