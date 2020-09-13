#include <climits>

template <typename T>

class StackUsingArray {
    T *data;
    int nextIndex;
    int capacity;

  public:
    StackUsingArray() { // Constructor
        data = new T[4];
        nextIndex = 0;
        capacity = 4;
    }

    /*
	   Return the number of elements present in stack
	 */
    int size() {
        return nextIndex;
    }

    /*
	   Stack is empty or not
	 */
    bool isEmpty() {
        /*
		if(nextIndex == 0) {
			return true;
		}
		else {
			return false;
		}
		OR
		*/
        return nextIndex == 0;
    }

    /*
	   Insert element into stack
	 */
    void push(T element) {
        if (nextIndex == capacity) {
            T *newData = new T[2 * capacity];
            for (int i = 0; i < capacity; i++) {
                newData[i] = data[i];
            }
            capacity *= 2;
            delete[] data;
            data = newData;
        }
        data[nextIndex] = element;
        nextIndex++;
    }

    /*
	   Delete top element
	 */
    T pop() {
        if (isEmpty()) {
            cout << "Stack is empty " << endl;
            return 0;
        }
        nextIndex--;
        return data[nextIndex];
    }

    /*
	   Return top element
	 */
    T top() {
        if (isEmpty()) {
            cout << "Stack is empty " << endl;
            return 0; //If is empty return 0
        }
        return data[nextIndex - 1];
    }
};
