#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void floydWarshall(vector<vector<int>>& graph, int n) {
    vector<vector<int>> dist = graph; // Copy the input graph

    // Core algorithm
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    // Print the result
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == INT_MAX)
                cout << "INF ";
            else
                cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n = 5;
    vector<vector<int>> graph = {
        {0,3,8,INT_MAX,-4},
        {INT_MAX,0,INT_MAX,1,7},
        {INT_MAX,4,0,INT_MAX,INT_MAX},
        {2,INT_MAX,-5,0,INT_MAX},
        {INT_MAX,INT_MAX,INT_MAX,6,0}
    };

    floydWarshall(graph, n);

    return 0;
}


