#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int partition(vector<int>& list, int first, int last) {
  // first and last are indecies not dereferenced values
  // The pivot should be the median of the
  // first, middle, and last elements.
  int pivot;
  int middle = floor((list.size() - 1) / 2); // Middle index

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
  
  return smallIndex;  // Returns pivot point
}

void quicksort(vector<int>& list, int first, int last) {
  int pivotLocation;
  if (first < last){
    pivotLocation = partition(list, first, last);
    quicksort(list, first, pivotLocation - 1);
    quicksort(list, pivotLocation + 1, last);
  }
}

void multiway_merge(
  vector<vector<int> >& input_lists, vector<int>& output_list
) 
{

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
