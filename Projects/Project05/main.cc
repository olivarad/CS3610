/**
 * @file main.cc
 * @author Olivia Radecki (gr982220@ohio.edu)
 * @brief Array based implementation of Djikstra's algorithm
 * @date 2023-11-22
 */

#include <iostream>
#include <vector>
using namespace std;

void dijkstra(const int &n, const vector<vector<int>> &distance_matrix, string cities[]);

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

int shortest(const int &n, const pair<string, pair<int, int>> table[], const string unvisited[]){
    int initial;
    int shortest;
    int city;
    for (int i = 0; i < n; i++)
        if (unvisited[i] != "NULL"){
            initial = i;
            shortest = table[i].second.first;
            city = i;
            break;
        }
    
    for (int i = initial + 1; i < n; i++)
        if (table[i].second.first < shortest && unvisited[i] == table[i].first){
            shortest = table[i].second.first;
            city = i;
        }
    
    return city;
}

void dijkstra(const int &n, const vector<vector<int>> &matrix, string cities[]){ // cities is a copy so we can use this as our list of unvisited cities
    typedef pair<string, pair<int, int>> Data; // City (.first), Shortest distance from A (.second.first), Previous city (.second.second)
    Data table[n]; // Array to store data relevant to dijkstras algorithm
    
    table[0].first = cities[0];
    table[0].second.first = 0; // Distance from self is 0
    table[0].second.second = 999; // No previous city

    for (int i = 1; i < n; i++){
        table[i].first = cities[i];
        table[i].second.first = 999; // Indicates no known shortest distance
        table[i].second.second = 999; // No previous city
    }

    for(int i = 0; i < n; i++){ // Run until every city has been visited
        // Find unvisited city with shortest distance from start
        int city = shortest(n, table, cities); // Table index of city to branch from
        for (int j = 0; j < n; j++){ // Find all unvisited cities that branch from city
            if (j != city && cities[j] == table[j].first && matrix[city][j] != 0){ // j is the index of an unvisited city (other than city) with a path from city
                int dist = table[city].second.first + matrix[city][j]; // New path found of distance start to city plus city to j
                if (dist < table[j].second.first){ // Traveling from city is faster method than current
                    table[j].second.first = dist;
                    table[j].second.second = city;
                }
            }
        }
        cities[city] = "NULL";
    }

    vector <string> path;
    int current = table[n-1].second.second; // Last value in table
    path.push_back(table[n-1].first);
    while (current != 999){
        path.push_back(table[current].first);
        current = table[current].second.second;
    }

    for (auto it =  path.rbegin(); it != path.rend(); ++it)
        cout << *it << " ";
    cout << table[n-1].second.first << endl;
}