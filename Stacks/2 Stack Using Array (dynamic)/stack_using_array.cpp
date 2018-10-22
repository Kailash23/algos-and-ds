#include<climits>

class StackUsingArray {
	int *data;
	int nextIndex;
	int capacity;

	public:
		StackUsingArray(){
			data = new int[4];
			nextIndex = 0;
			capacity = 4;
		}

		/*
		   Return the number of elements present in stack
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
	       Insert element into stack
		 */
		void push(int element){
			if(nextIndex == capacity){
				int *newData = new int[2 * capacity];
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

		/*
		   Delete top element
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
		   Return top element
		 */
		int top(){
			if(isEmpty()){
				cout << "Stack is empty!" << endl;
				return INT_MIN;
			}
			return data[nextIndex-1];
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
