#include<climits>

class StackUsingArray {
	int *data;
	int nextIndex;
	int capacity;

public:

	StackUsingArray(){
		data = new int[4];
		nextIndex = 0;
	}

	//Retrun the number of elements present in my StackUsingArray
	int size(){
		return nextIndex;
	}

	//Stack is empty or not
	bool isEmpty(){
		/*
		if(nextIndex == 0){
			return true;
		} else {
			return false;
		}
		*/
		return nextIndex == 0;
	}

	//Insert element
	void push(int element){
		if(nextIndex == capacity){
			int *newData = new int[2*capacity];
			for(int i = 0; i < capacity; i++){
			    newData[i] = data[i];
			}
			capacity *= 2;
			delete [] data;
			data = newData;
		}
		data[nextIndex] = element;
		nextIndex++;
	}

	//Delete the element
	int pop(){
		if(isEmpty()){
			cout<<"Stack is empty!"<<endl;
			return INT_MIN;
		}
		nextIndex--;
		return data[nextIndex];
	}

	int top(){
		if(isEmpty()){
			cout<<"Stack is empty!"<<endl;
			return INT_MIN;
		}
		return data[nextIndex-1];
	}
};
