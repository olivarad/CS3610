#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int partition(vector<int>& list, int first, int last) {
  // The pivot should be the median of the
  // first, middle, and last elements.
  int middle = floor((list.size() - 1) / 2); // Middle point is the floor of half of the size minus 1
  
  if ((list[middle] < list[1] < list[-1]) || (list[-1] < list[1] < list[middle])){ // first index is pivot point
    int pivot = 1;
  }

  if ((list[1] < list[middle] < list[-1]) || (list[-1] < list[middle] < list[1])){ // Middle is pivot point
    int pivot = middle;
  }

  if ((list[middle] < list[-1] < list[1]) || (list[1] < list[-1] < list[middle])){ // last index is pivot point
    int pivot = list.size() - 1;
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
