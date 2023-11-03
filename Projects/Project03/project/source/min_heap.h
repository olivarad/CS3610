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
  int index = heap.size() - 1; // Index of new element is the last index in the vector

  HeapNode<T> node(data, key);
  heap.push_back(node); // Inserts the new element into the back of the heap array
  while (index > 0 && heap[index].key < heap[(index - 1) / 2].key){ // No need to heapify further if you are the root
    swap(heap[index], heap[(index - 1) / 2]);
    index = (index - 1) / 2;
  }
}

template <typename T>
T MinHeap<T>::extract_min() {                          // need to implement this function
  T data = heap[0].data;
  heap[0] = heap[heap.size() - 1];
  heap.pop_back();

  unsigned int i = 0;
  while(i < heap.size() / 2){
    if(heap[2 * i + 1].key < heap[2 * i + 2].key){ // Left child is smaller
      if(heap[2 * i + 1].key < heap[i].key){ // Left child is smaller than parent
        swap(heap[i], heap[2 * i + 1]);
        i = 2 * i + 1;
      }
      else{
        break;
      }
    }
    else{
      if(heap[2 * i + 2].key < heap[i].key){
        swap(heap[2 * i + 2], heap[i]);
        i = 2 * i + 2;
      }
      else{
        break;
      }
    }
  }
  return data;
}
