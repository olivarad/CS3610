#include <iostream>
#include <vector>
using namespace std;

void dijkstra(int n, vector<vector<int>> distance_matrix, string cities[]);

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
        //int distance_matrix[n][n];
        vector<vector<int>> matrix(n, vector<int>(n)); // Initializes an n*n matrix
        for (int j = 0; j < n; j++){
            cin >> cities[j];
        }
        for (int j = 0; j < n; j++){
            for (int k = 0; k < n; k++){
                cin >> matrix[j][k];
            }
        }
        /*for (int j = 0; j < n; j++){
            for (int k = 0; k < n; k++){
                cout << cities[j] << " to " << cities[k] << ": " << matrix[j][k] << endl;
            }
        }*/
        dijkstra(n, matrix, cities);
       }
}

int minDist(int dist[], bool included[], int n){
    int min = 999;
    int min_index;

    for (int i = 0; i < n; i++){
        if (included[i] == false && dist[i] <= min){
            min = dist[i];
            min_index = i;
        }
    }
    return min_index;
}

bool no_visit(int n, string city, string unvisited[]){
    for (int i = 0; i < n; i++)
        if (city == unvisited[i])
            return true; // City has not been visited
    
    return false; // City has been visited
}

int shortest(int n, pair<string, pair<int, string>> table[], string unvisited[]){
    int initial;
    int shortest;
    for (int i = 0; i < n; i++)
        if (unvisited[i] != "NULL"){
            initial = i;
            shortest = table[i].second.first;
            break;
        }
    
    for (int i = initial; i< n; i++)
        if (table[i].second.first < shortest && no_visit(n, table[i].first, unvisited))
            shortest = table[i].second.first;
    
    return shortest;
}

void dijkstra(int n, vector<vector<int>> matrix, string cities[]){
    typedef pair<string, pair<int, string>> Data; // City (.first), Shortest distance from A (.second.first), Previous city (.second.second)
    Data table[n]; // Array to store data relevant to dijkstras algorithm

    string visited[n] = {"NULL"}; // Initialized to null to indicate that no cities have been visited
    string unvisited[n]; // Unvisited cities
    
    table[0].first = cities[0];
    table[0].second.first = 0;
    table[0].second.second = "NULL"; // No previous city

    unvisited[0] = cities[0]; // Initialized seperately to simply for loop in the setup
    for (int i = 1; i < n; i++){
        table[i].first = cities[i];
        table[i].second.first = 999; // Indicates no known shortest distance
        table[i].second.second = "NULL"; // No previous city
        unvisited[i] = cities[i];
    }


}