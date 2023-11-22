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

int city_to_int(int n, string city, string cities[]){
    for (int i = 0; i < n; i++)
        if (city == cities[i])
            return i; // Index of source city
    return -1; // Sentinel to indicate failure
}

bool no_visit(int n, string city, string unvisited[]){
    for (int i = 0; i < n; i++)
        if (city == unvisited[i])
            return true; // City has not been visited
    
    return false; // City has been visited
}

int shortest(int n, pair<string, pair<int, int>> table[], string unvisited[]){
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
        if (table[i].second.first < shortest && no_visit(n, table[i].first, unvisited)){
            shortest = table[i].second.first;
            city = i;
        }
    
    return city;
}

void dijkstra(int n, vector<vector<int>> matrix, string cities[]){
    typedef pair<string, pair<int, int>> Data; // City (.first), Shortest distance from A (.second.first), Previous city (.second.second)
    Data table[n]; // Array to store data relevant to dijkstras algorithm

    string visited[n] = {"NULL"}; // Initialized to null to indicate that no cities have been visited
    string unvisited[n]; // Unvisited cities
    
    table[0].first = cities[0];
    table[0].second.first = 0;
    table[0].second.second = 999; // No previous city

    unvisited[0] = cities[0]; // Initialized seperately to simply for loop in the setup
    for (int i = 1; i < n; i++){
        table[i].first = cities[i];
        table[i].second.first = 999; // Indicates no known shortest distance
        table[i].second.second = 999; // No previous city
        unvisited[i] = cities[i];
    }

    for(int city_counter = 0; city_counter < n; city_counter++){ // Run until every city has been visited
        // Find unvisited city with shortest distance from start
        int city = shortest(n, table, unvisited); // Table index of city to branch from
        for (int i = 0; i < n; i++){ // Find all unvisited cities that branch from city
            if (i != city && no_visit(n, cities[i], unvisited) && matrix[city][i] != 0){ // i is the index of an unvisited city (other than city) with a path from city
                int dist = table[city].second.first + matrix[city][i];
                if (dist < table[i].second.first){ // Traveling from city is faster method than current
                    table[i].second.first = dist;
                    table[i].second.second = city;
                }
            }
        }
        unvisited[city] = "NULL";
        visited[city] = cities[city];
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