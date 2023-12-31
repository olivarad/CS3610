#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;


/*
Changed textbook code to make the function actually work
*/
int partition(vector<int>& list, int first, int last) {
  // first and last are indecies not dereferenced values
  // The pivot should be the median of the
  // first, middle, and last elements.
  int pivot = list[first]; // Pivot is defined as the first element
 
    int count = 0; // Variable to offset after finding real pivot point
    for (int i = first + 1; i <= last; i++) { // Generates count variable to shift pivot
        if (list[i] <= pivot)
            count++;
    }

    int pivotIndex = first + count;
    swap(list[first], list[pivotIndex]);

    int i = first;
    int j = last;

    while (i < pivotIndex && j > pivotIndex){ // Go until you arrive at the pivot point
      while (list[i] <= pivot){
        i++;
      }

      while (list[j] > pivot){
        j--;
      }

      if (i < pivotIndex && j > pivotIndex){
        swap(list[i++], list[j--]);
      }
    }

    return pivotIndex;

/*
Non-working textbook code
*/
  /*int pivot;
  int middle = floor((last - 1) / 2); // Middle index

  if ((list[middle] <= list[first] && list[first] <= list[last]) || (list[last] <= list[first] && list[first] <= list[middle])) {
      pivot = first;
    }

  else if ((list[0] <= list[middle] && list[middle] <= list[last]) || (list[last] <= list[middle] && list[middle] <= list[0])) {
      pivot = middle;
    }

  else{
      pivot = last;
    }

  swap(list[first], list[pivot]); // Swap the first element of the list with the pivot

  int smallIndex = first;
  
  for (int i = first + 1; i < list.size(); i++){
    if (list[i] < list[pivot]){
      smallIndex++; // Increment smallIndex
      swap(list[i], list[smallIndex]); // Swap the current element iwth the array element pointed to by smallIndex
    }
  }
  swap(list[pivot], list[smallIndex]); // Swap the first element, that is, the pivot, with the array element pointed to by smallIndex

  // partition procedure
  
  return smallIndex;  // Returns pivot point*/
}

void recQuickSort(vector<int>& list, int first, int last){
  int pivotLocation;
  if (first < last){
    pivotLocation = partition(list, first, last);
    recQuickSort(list, first, pivotLocation - 1);
    recQuickSort(list, pivotLocation + 1, last);
  }
}

void quicksort(vector<int>& list, int first, int last) {
  recQuickSort(list, 0, list.size() -1);
}

void multiway_merge(vector<vector<int> >& input_lists, vector<int>& output_list){
  int output_index = 0; // Since the vector is already filled with 0's of the capacity needed this will allow prvention of double sized vector with leading zeros
  typedef pair<int, pair<int, int>> ppi; // pair of pair of ints to track element, from vector, and from vector index
  priority_queue<ppi, vector<ppi>, greater<ppi>> heap;
  for (int i = 0; i < input_lists.size(); i++){
    heap.push({input_lists[i][0], {i, 0}});
  }

  while (!heap.empty()){
    ppi current = heap.top();
    heap.pop();
    int i = current.second.first; // From vector
    int j = current.second.second; // Index of from vector
    output_list[output_index] = current.first; // push element to output list
    output_index++;

    if (j + 1 < input_lists[i].size()){
      heap.push({input_lists[i][j + 1], {i, j + 1}});
    }
  }
  } 

int main(int argc, char** argv) {
  int n, m;
  cin >> n >> m;

  vector<vector<int> > input_lists(n, vector<int>(m));

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> input_lists[i][j];
    }
  }
  // Quicksort k sublists
  for (int i = 0; i < input_lists.size(); ++i)
    quicksort(input_lists[i], 0, m-1);

  // Merge n input sublists into one sorted list
  vector<int> output_list(n * m);
  multiway_merge(input_lists, output_list);

  for (int i = 0; i < output_list.size(); ++i)
    cout << output_list[i] << " ";
  cout << endl;

  return 1;
}
