/**
 * Data Structures - hashmap
 * hashmap.cpp
 * Purpose: Implementation of Hashmap
 *
 * @author Kailash Uniyal
 * @version 1.0 30/10/18
*/

#include <iostream>
using namespace std;

template <typename T>
class MapNode {
  public:
	  const string key;
	  T value;
	  MapNode<T>* next;

	  MapNode(const string &key, const T &value): key(key) {
		  this->value = value;
		  next = NULL;
	  }

	  ~MapNode(){
		  delete this->next;
	  }
};

template <typename T>
class Hashmap {
  private:
	MapNode<T>** buckets;
	int count;
	int numBuckets;

  public:
	Hashmap(){
		this->count = 0;
		this->numBuckets = 5;
		this->buckets = new MapNode<T>*[this->numBuckets];
		for(int i = 0; i < this->numBuckets; i++){
		    this->buckets[i] = NULL;
		}
	}

	Hashmap(const Hashmap &h) {
		this->count = h.count;
		this->numBuckets = h.numBuckets;
		this->buckets = new MapNode<T>*[this->numBuckets];
		for(int i = 0; i < this->numBuckets; i++){
		    this->buckets[i] = h.buckets[i];
		}
	}

	~Hashmap(){
		for(int i = 0; i < this->numBuckets; i++){
		    delete this->buckets[i];
		}
		delete [] this->buckets;
	}

	int size(){
		return this->count;
	}

  private:
	int getBucketIndex(string key){
		int hashCode = 0;
		int currentCoeff = 1;
		for(int i = key.length(); i >= 0; i--){
		    hashCode += key[i] * currentCoeff;
			hashCode %= this->numBuckets;
			currentCoeff *= 37;
			currentCoeff %= this->numBuckets;
		}
		return hashCode % this->numBuckets;
	}

  public:
	double getLoadFactor(){
		return (1.0 * this->count) / this->numBuckets;
	}

	void rehash(){
		MapNode<T>** temp = this->buckets;
		buckets = new MapNode<T>*[2 * this->numBuckets];
		for(int i = 0; i < 2 * this->numBuckets; i++){
		    this->buckets[i] = NULL;
		}
		int oldBucketCount = this->numBuckets;
		this->numBuckets *= 2;
		this->count = 0;
		for (int i = 0; i < oldBucketCount; i++){
		    MapNode<T>* head = temp[i];
			while(head != NULL){
				string key = head->key;
				T value = head->value;
				insert(key, value);
				head = head->next;
			}
		}
		for (int i = 0; i < oldBucketCount; i++){
		    delete temp[i];
		}
		delete [] temp;
	}

  public:
	void insert(const string &key, const T &value){
		int bucketIndex = getBucketIndex(key);
		MapNode<T>* head = this->buckets[bucketIndex];
		while(head != NULL){
			if(head->key == key){
				head->value = value;
				return;
			}
			head = head->next;
		}
		head = this->buckets[bucketIndex];
		MapNode<T>* node = new MapNode<T>(key, value);
		node->next = head;
		this->buckets[bucketIndex] = node;
		this->count++;
		double loadFactor = (1.0 * this->count) / this->numBuckets;
		if(loadFactor > 0.7){
			rehash();
		}
	}

	T getValue(const string &key){
		int bucketIndex = getBucketIndex(key);
		MapNode<T>* head = this->buckets[bucketIndex];
		while(head != NULL){
			if(head->key == key){
				return head->value;
			}
			head = head->next;
		}
		return 0;
	}

	T remove(const string &key){
		int bucketIndex = getBucketIndex(key);
		MapNode<T> *head = this->buckets[bucketIndex];
		MapNode<T> *prev = NULL;
		while(head != NULL){
			if(head->key == key){
				if(prev == NULL){
					buckets[bucketIndex] = head->next;
				} else {
					prev->next = head->next;
				}
				T value = head->value;
				head->next = NULL;
				delete head;
				count--;
				return value;
			}
			prev = head;
			head = head->next;
		}
	}

	void print(){
		for(int i = 0; i < this->numBuckets; i++){
		    MapNode<int>* head = this->buckets[i];
			while(head != NULL){
				cout << head->key << " : ";
				cout << head->value << endl;
				head = head-> next;
			}
		}
	}
};
