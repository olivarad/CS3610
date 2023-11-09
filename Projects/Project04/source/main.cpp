#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int partition(vector<int>& list, int first, int last) {
  // The pivot should be the median of the
  // first, middle, and last elements.
  int pivot;
  int end = list.size() - 1; // End index
  int middle = floor((list.size() - 1) / 2); // Middle index

  if ((list[middle] <= list[0] && list[0] <= list[end]) || (list[end] <= list[0] && list[0] <= list[middle])) {
        pivot = 0;
    }

    else if ((list[0] <= list[middle] && list[middle] <= list[end]) || (list[end] <= list[middle] && list[middle] <= list[0])) {
        pivot = middle;
    }

    else{
        pivot = end;
    }

  int smallIndex = first;

  // partition procedure
  
  return smallIndex;  
}

void quicksort(vector<int>& list, int first, int last) {
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
