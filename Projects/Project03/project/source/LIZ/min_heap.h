#include <vector>
#include <algorithm>
#include <cmath>
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
  T peek() const {return heap.at(0).data;} // need to implement this function

  int size() const {return heap.size();}         // need to implement this function

private:
  vector<HeapNode<T> > heap;
};

template <typename T>
void MinHeap<T>::insert(const T data, const int key) {  // need to implement this function
  int i = heap.size() - 1;
  HeapNode<T> tmp(data, key);
  heap.push_back(tmp);

  while(i > 0 && heap[i].key < heap[(i-1)/2].key){
    swap(heap[i], heap[(i-1)/2]);
    i = (i-1)/2;
  }

}

template <typename T>
T MinHeap<T>::extract_min() {    
  T tmp = heap[0].data;                      // need to implement this function
  heap[0] = heap[heap.size() - 1];
  heap.pop_back();
  int i = 0;
  while(i < heap.size() / 2){
    if(heap[2*i+1].key < heap[2*i+2].key){
      if(heap[2*i+1].key < heap[i].key){
        swap(heap[2*i + 1], heap[i]);
        i = (2*i + 1);
      }
      else{
        break;
      }
    }
    else{
      if(heap[2*i+2].key < heap[i].key){
        swap(heap[2*i + 2], heap[i]);
        i = (2*i + 2);
      }
      else{
        break;
      }
    }
  }
  return tmp;
  
}
