#include <string>
using namespace std;

template <typename V>
class MapNode {
  public:
	string key;
	V value;
	MapNode* next;

	MapNode(string key, V value){           //Constructor
		this->key = key;
		this->value= value;
		next = NULL;
	}

	~MapNode(){         //Recursive destructor
		delete next;
	}
};

template <typename V>
class ourmap {
	MapNode<V>** buckets;       // Array to store LL head, LL head MapNode<V>*
	int count;          // Used to track num of entries in hashmap
	int numBuckets;         // Size of our hashmap

  public:
	ourmap(){				// Constructor
		count = 0;            // Initailly count is 0, cuz no elements
		numBuckets = 5;
		buckets = new MapNode<V>*[numBuckets];       // we created array of size 5 (Dynamic alloc of array)
		for(int i = 0; i < numBuckets; i++) {
			buckets[i] = NULL;          // Initializing with NULL
		}
	}

	~ourmap(){                  // Destructor
		for(int i = 0; i < numBuckets; i++) {       // Delete LL heads it and will delete all
			delete buckets[i];                  // nodes cause destructor is recursive.
		}
		delete [] buckets;          // Then we can delete array buckets after deleting LL.
	}

	/*
	   Size
	 */
	int size(){
		return count;           // return no of entries till now
	}

	/*
	   Generating hash code
	 */
	private:
	int getBucketIndex(string key){
		int hashCode = 0;
		int currentCoeff = 1;
		for(int i = key.length() - 1; i >= 0; i--) {
			hashCode += key[i] * currentCoeff;
			hashCode %= numBuckets;		 // It might go out of integer range so we used %
			currentCoeff *= 37;          // Prime coeff will give equal distribution of entries in array
			currentCoeff %= numBuckets;
		}
		return hashCode % numBuckets;
	}

	public:
	double getLoadFactor(){
		return (1.0 * count) / numBuckets;
	}

	/*
	   Rehashing
	 */
	void rehash(){
		MapNode<V>** temp = buckets;            // point temp to buckets array
		buckets = new MapNode<V>*[2 * numBuckets];            // Then buckets is pointed to other array twice of its previous size (empty one)
		for(int i = 0; i < 2 * numBuckets; i++) {         //garbage value to NULL
			buckets[i] = NULL;
		}
		int oldBucketCount = numBuckets;            // oldBucketCount is eq to entries in temp array.
		numBuckets *= 2;          // Doubling buckets as we are rehashing
		count = 0;          // Make count to zero as we are rehashing

		for(int i = 0; i < oldBucketCount; i++) {       // traversing each entries in temp array and put
			                                        // it in new  buckets array(double size then temp)
			MapNode<V>* head = temp[i];         // Get head of each LL present in temp array
			while(head != NULL) {
				string key = head->key;
				V value = head->value;
				insert(key, value);          // It will insert in buckets which is pointed to new array
				head = head->next;
			}
		}
		for(int i = 0; i < oldBucketCount; i++) {
			MapNode<V>* head = temp[i];         //Get head one by one and delete
			delete head;            //This delete is recursive
		}
		delete [] temp;         //Delete temp array as its work is done
	}

	/*
	   Insert
	 */
  public:
	void insert(string key, V value){
		int bucketIndex = getBucketIndex(key);
		MapNode<V>* head = buckets[bucketIndex];      //Get the head at bucket index
		while(head != NULL) {
			if(head->key == key) {          //If key already present update value
				head->value = value;         //Update value & dont increase count
				return;
			}
			head = head->next;
		}

		head = buckets[bucketIndex];            //If key not found get head again
		MapNode<V>* node = new MapNode<V>(key, value);          //and make new node with given key and value
		node->next = head;
		buckets[bucketIndex] = node;            //Adjust links (next) to place new node at bucketIndex
		count++;            //To count how many entries in our map
		double loadFactor = (1.0 * count) / numBuckets;         //1.0 is multiplied for casting to double
		if(loadFactor > 0.7) {
			rehash();
		}
	}

	/*
	   Retrieve value (search)
	 */
	V getValue(string key){
		int bucketIndex = getBucketIndex(key);          //Get bucket index using key
		MapNode<V>* head = buckets[bucketIndex];            //Get head of LL at bucket index
		while(head != NULL) {
			if(head->key == key) {
				return head->value;
			}
			head = head->next;
		}
		return 0;
	}

	/*
	   Delete and then return deleted value
	 */
	V remove(string key){
		int bucketIndex = getBucketIndex(key);          //Find bucket index
		MapNode<V>* head = buckets[bucketIndex];            //Get head node at bucket index
		MapNode<V>* prev = NULL;            //prev will be null initailly
		while(head != NULL) {
			if(head->key == key) {
				if(prev == NULL) {          //If prev is NULL and and we are using prev->next we will get error
					buckets[bucketIndex] = head->next;          //prev is NULL only if we find element at head (ie first node)
				} else {
					prev->next = head->next;
				}
				V value = head->value;          //Store deleted value in order to return before deleting head
				head->next = NULL;          //Have to do this to avoid recursive deletion of whole LL
				delete head;
				count--;            //Decrement count as we deleted that entry
				return value;
			}
			prev = head;            //prev is always before head and moving togther
			head = head->next;
		}
		return 0;           //Signify invaid value ie we can't find value to be deleted.
	}
};
