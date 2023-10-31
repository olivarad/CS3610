#include <vector>
#include <algorithm>
using namespace std;

template <typename T>
struct HeapNode {
  HeapNode(const T data, const int key) : data(data), key(key) {}
  bool operator<(const HeapNode<T>& rhs) {return this->key < rhs.key;}
  bool operator<=(const HeapNode<T>& rhs) {return this->key <= rhs.key;}

  T data;
  int key;
};

template <typename T>
class MinHeap {
public:
  MinHeap() {}
  ~MinHeap() {}

  void insert(const T data, const int key);
  T extract_min();
  T peek() const {return heap[0].data;}; // need to implement this function

  int size() const { return heap.size();};         // need to implement this function

private:
  vector<HeapNode<T> > heap;
};


template <typename T>
void MinHeap<T>::insert(const T data, const int key) {  // need to implement this function
  heap.push_back(HeapNode(data, key)); // Inserts the new element into the back of the heap array
  int index = heap.size() - 1; // Index of new element is the last index in the vector
  while (index > 0){ // No need to heapify further if you are the root
    if (index % 2 == 1){ // Odd indecies are left children
      int parent = (index - 1) / 2;
      if (heap[index].key < heap[parent].key){ // Swapping required
        swap(heap[parent], heap[index]); // Utilizes the STD swap function for individual elements
        index = parent;
      }
      else{ // No swapping required, insertion complete
        return;
      }
    }
    else{ // Even indecies are right children
      int parent = (index - 2) / 2;
      if (heap[index].key < heap[parent].key){ // Swapping required
        swap(heap[parent], heap[index]); // Utilizes the STD swap function for individual elements
        index = parent;
      }
      else{ // No swapping required, insertion complete
        return;
      }
    }
  }
}

template <typename T>
T MinHeap<T>::extract_min() {                          // need to implement this function

  T data = heap[0].data; // Extracts data from min
  heap.erase(heap.begin()); // Deletes min
   return data;
}
