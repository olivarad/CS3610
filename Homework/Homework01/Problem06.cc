/*
Write a program to find the mean and standard deviation of numbers. The
mean (average) of n numbers x1, x2, . . ., xn is x ¼ (x1 + x2 + . . . + xn) / n.
Use a vector object to store the variables
*/

#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int menu(vector<double>& vec);

int main(){
    vector<double> nums; // An STL vector to store the data from the problem
    while (menu(nums) != 1);
    if (nums.empty() != 1){
        int count = 0;
        double average = 0;
        double stdev = 0;
        for (auto i = nums.begin(); i != nums.end(); ++i){
            count += 1;
            average += *i;
        }
        average /= count;
        for (auto i = nums.begin(); i != nums.end(); ++i){
            stdev += ((*i - average) * (*i - average));
        }
        stdev /= count;
        stdev = sqrt(stdev);
        cout << "Average: " << average << endl;
        cout << "STDEV: " << stdev << endl;
    }
    return 0;
}

int menu(vector<double>& vec){ // Inputing the variable directly into the vector and returning a 0 on continue and 1 on quit
    double num;
    cout << "Please select an option\n";
    cout << "1. Add number\n";
    cout << "2. Quit\n";
    cin >> num;

    if (num == 1){
        cout << "Pleae input the number to add\n";
        cin >> num;
        vec.push_back(num);
        return 0;
    }
    else{
        return 1;
    }
}