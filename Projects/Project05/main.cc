#include <iostream>
#include <vector>
using namespace std;

int main(){
    /*
    k: number of testcases (number of city groups)
    n: number of cities in a test case
    */
    int k, n;
    cin >> k;
       for (int i = 0; i < k; i++){
        cin >> n;
        string cities[n];
        int distance_matrix[n][n];
        for (int j = 0; j < n; j++){
            cin >> cities[j];
        }
        for (int j = 0; j < n; j++){
            for (int k = 0; k < n; k++){
                cin >> distance_matrix[j][k];
            }
        }
        for (int j = 0; j < n; j++){
            for (int k = 0; k < n; k++){
                cout << cities[j] << " to " << cities[k] << ": " << distance_matrix[j][k] << endl;
            }
        }
       }
}