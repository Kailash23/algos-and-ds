#include <string>
using namespace std;

template <typename V>
class MapNode {
  public:
    string key;
    V value;
    MapNode *next; // Address of next map node is stored here (Singly LL)

    MapNode(string key, V value) { // Constructor
        this->key = key;
        this->value = value;
        next = NULL;
    }

    ~MapNode() { // Recursive Destructor
        delete next;
    }
};

template <typename V>
class ourmap {
    MapNode<V> **buckets; // bucket array to store head of the linked list of type MapNode<V>*
    int count;            // To keep track of no of entry
    int numBuckets;       // bucket array size

  public:
    ourmap() {     // Constructor
        count = 0; // Initailly count is 0, cuz no elements
        numBuckets = 5;
        buckets = new MapNode<V> *[numBuckets]; // we created array of size 5 (Dynamic alloc of array)
        for (int i = 0; i < numBuckets; i++) {
            buckets[i] = NULL; // Initializing with NULL to avoid garbage address
        }
    }

    ~ourmap() { // Destructor
        for (int i = 0; i < numBuckets; i++) {
            delete buckets[i]; // Delete LL heads it and will delete all beacause Destructor is recursive.
        }
        delete[] buckets; // Then we can delete array buckets after deleting LL.
    }

    /*
	   Size
	 */
    int size() {
        return count; // return no of entries till now
    }

    /*
	   Generating Hash Code
	 */
  private:
    int getBucketIndex(string key) { // Hash Function has 2 Part - hash code and compression function
        int hashCode = 0;
        int currentCoeff = 1;
        for (int i = key.length() - 1; i >= 0; i--) {
            hashCode += key[i] * currentCoeff;
            hashCode = hashCode % numBuckets; // It might go out of integer range so we used %
            currentCoeff *= 37;               // Prime coeff will give equal distribution of entries in array
            currentCoeff = currentCoeff % numBuckets;
        }
        return hashCode % numBuckets;
    }

    /*
	   Insert
	 */
  public:
    void insert(string key, V value) {
        int bucketIndex = getBucketIndex(key);   // Get the index using key
        MapNode<V> *head = buckets[bucketIndex]; // Using bucketIndex get the head of the linked list
        while (head != NULL) {
            if (head->key == key) {  // If key already present update value
                head->value = value; // Update value & dont increase count
                return;
            }
            head = head->next;
        }

        head = buckets[bucketIndex];                    // If key not found get head again
        MapNode<V> *node = new MapNode<V>(key, value);  // Make new node with given key and value
        node->next = head;                              //newly inserted node point to head ie (insertion at beginning)
        buckets[bucketIndex] = node;                    // We have to update head in bucket as now first node is newly inserted node
        count++;                                        // as new entry is added (not updated) we must increment the count
        double loadFactor = (1.0 * count) / numBuckets; // 1.0 is multiplied for casting to double
        if (loadFactor > 0.7) {
            rehash();
        }
    }

    double getLoadFactor() {
        return (1.0 * count) / numBuckets;
    }

    /*
	   Rehashing
	 */
    void rehash() {
        MapNode<V> **temp = buckets;                // point temp to buckets array
        buckets = new MapNode<V> *[2 * numBuckets]; // Then buckets is pointed to other array twice of its previous size (empty one)
        for (int i = 0; i < 2 * numBuckets; i++) {  //garbage value to NULL
            buckets[i] = NULL;
        }
        int oldBucketCount = numBuckets; // oldBucketCount is eq to entries in temp array.
        numBuckets *= 2;                 // Doubling buckets as we are rehashing
        count = 0;                       // Make count to zero as we are rehashing

        for (int i = 0; i < oldBucketCount; i++) { // traversing each entries in temp array and put it in new  buckets array(double size then temp)
            MapNode<V> *head = temp[i];            // Get head of each LL present in temp array
            while (head != NULL) {
                string key = head->key;
                V value = head->value;
                insert(key, value); // It will insert in buckets which is pointed to new array
                head = head->next;
            }
        }
        for (int i = 0; i < oldBucketCount; i++) {
            MapNode<V> *head = temp[i]; //Get head one by one and delete
            delete head;                //This delete is recursive
        }
        delete[] temp; //Delete temp array as its work is done
    }

    /*
	   Retrieve value (search)
	 */
    V getValue(string key) {
        int bucketIndex = getBucketIndex(key);   //Get bucket index using key
        MapNode<V> *head = buckets[bucketIndex]; // Get head of LL at bucket index
        while (head != NULL) {
            if (head->key == key) {
                return head->value;
            }
            head = head->next;
        }
        return 0; // Default - Not found
    }

    /*
	   Delete and then return deleted value
	 */
    V remove(string key) {
        int bucketIndex = getBucketIndex(key);   // Find bucket index
        MapNode<V> *head = buckets[bucketIndex]; // Get head node at bucket index from buckets
        MapNode<V> *prev = NULL;                 // prev will be null initailly
        while (head != NULL) {
            if (head->key == key) {
                if (prev == NULL) {                    // If prev is NULL and and we are using prev->next we will get error
                    buckets[bucketIndex] = head->next; // prev is NULL only, if we find element at head (ie first node)
                } else {
                    prev->next = head->next; // This will point prev to node next to head.
                }
                V value = head->value; // Store deleted value in order to return before deleting head
                head->next = NULL;     // Have to do this to avoid recursive deletion of whole LL
                delete head;
                count--; // Decrement count as we deleted that entry
                return value;
            }
            prev = head; // prev is always before head and moving togther
            head = head->next;
        }
        return 0; // Signify invaid value ie we can't find value to be deleted.
    }
};
