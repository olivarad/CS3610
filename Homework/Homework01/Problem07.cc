#include <iostream>

using namespace std;

int linearSearch(int arr[], int size, int target){
    if (size == 0){
        return -1;
    }
    else if (arr[size -1] == target){
        return size - 1;
    }
    return linearSearch(arr, size -1, target);
}

int main(){
    int target;
    cout << "Please provide a target\n";
    cin >> target;
    int nums[] = {1, 2, 3, 5, 4};
    int index = linearSearch(nums, sizeof(nums), target);
    if (index == -1)
        cout << "The target number (" << target << ") could not be found\n";
    else
        cout << "The target number (" << target << ") was found at index " << index << " of the given array\n"; 
    return 0;
}