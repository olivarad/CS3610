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

bool visit(int i, vector<int> visited){
    for (unsigned int j = 0; j < visited.size(); j++){
        if (i == visited[j]){ // i has been visited
            return true;
        }
    }
    return false;
}

void dijkstra(int n, vector<vector<int>> matrix, string cities[]){
    vector<int> visited;
    vector<int>unvisited(n);
    for (int i = 0; i < n; i++)
        unvisited[n] = i;
    int shortest_dist[n] = {0, 999}; // 0: same city, 999: no shortest path found
    int previous_index[n] = {999};
    
    for (int i = 1; i < n; i++){
        if (matrix[0][i] != 0){ // Path exists
            if(matrix[0][0] + matrix[0][i] < shortest_dist[i]){ // Update shortest know distance
                shortest_dist[i] = matrix[0][0] + matrix[0][i];
                previous_index[i] = 0; // Visited city i by traveling from city 0
            }
        }
        visited.push_back(0); // Add city 0 to list of visited cities
        unvisited.erase(unvisited.begin()); // Erase the city just visited from unvisited
    }

    while (!unvisited.empty()){
        int smallest_dist = 999;
        int city; // City now traveling from
        for (unsigned int i = 0; i < unvisited.size(); i++)
            if (shortest_dist[i] != 0 && shortest_dist[i] < smallest_dist){
                smallest_dist = shortest_dist[i];
                city = i;
            }
        
        for (unsigned int i = 0; i < unvisited.size(); i++){
            if (matrix[city][i] != 0 && !visit(i, visited)){ // Path exists and has not been visited yet
                if (shortest_dist[city] + matrix[city][i] < shortest_dist[i]){ // Found better path to city i
                    shortest_dist[i] = shortest_dist[city] + matrix[city][i];
                    previous_index[i] = city;
                }
            }
            visited.push_back(city);
            for (vector<int>::iterator it = unvisited.begin(); it != unvisited.end(); ++it){
                if (*it == city){
                    unvisited.erase(it);
                    break;
                }
            }
        }
    }

    vector<string> results;
    results.insert(results.begin(), cities[n]);
    int prev = previous_index[n];
    while (prev != 0){
        results.insert(results.begin(), cities[prev]);
    }
    for (unsigned int i = 0; i < results.size(); i++){
        cout << results[i] << " ";
    }
    cout << endl;
}