#include<climits>

class StackUsingArray {
	int *data;
	int nextIndex;
	int capacity;

	public:
		StackUsingArray(int totalSize){
			data = new int[totalSize];		// dynamic allocation
			nextIndex = 0;
			capacity = totalSize;	// Initializing with totalSize given by the user
		}

		/*
		   Retrun the number of elements present in my StackUsingArray
		 */
		int size(){
			return nextIndex;
		}

		/*
		   Stack is empty or not
		 */
		bool isEmpty(){
			/*
			if(nextIndex == 0){
				return true;
			} else {
				return false;
			}
			OR
			*/
			return nextIndex == 0;
		}

		/*
		   Insert element
		 */
		void push(int element){
			if(nextIndex == capacity){
				cout << "Stack is Full !" << endl;
				return;
			}
			data[nextIndex] = element;
			nextIndex++;
		}

		/*
		   Delete the element
		 */
		int pop(){
			if(isEmpty()){
				cout << "Stack is empty!" << endl;
				return INT_MIN;
			}
			nextIndex--;
			return data[nextIndex];
		}

		/*
		   Return the topmost element of the stack
		 */
		int top(){
			if(isEmpty()){
				cout << "Stack is empty!" << endl;
				return INT_MIN;
			}
			return data[nextIndex - 1];
		}
};

/*
   Using Array

   push - O(1)
   pop - O(1)
   top - O(1)
   size - O(1)
   isEmpty - O(1)
 */
