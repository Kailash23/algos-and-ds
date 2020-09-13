#include <iostream>
using namespace std;

template <typename T>

class Node {
  public:
    T data;
    Node<T> *next;

    Node(T data) { // We don't need to add <T> after Node
        this->data = data;
        next = NULL;
    }
};
