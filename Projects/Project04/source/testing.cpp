#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int main(){
    int pivot = 0;
    vector<int> list {1, 2, 3, 4, 5};
    int end = list.size() - 1;
    int middle = floor((list.size() - 1) / 2); // Middle point is the floor of half of the size minus 1

    if ((list[middle] <= list[0] && list[0] <= list[end]) || (list[end] <= list[0] && list[0] <= list[middle])) {
        pivot = 0;
    }

    else if ((list[0] <= list[middle] && list[middle] <= list[end]) || (list[end] <= list[middle] && list[middle] <= list[0])) {
        pivot = middle;
    }

    else{
        pivot = end;
    }

    cout << pivot << endl;
}