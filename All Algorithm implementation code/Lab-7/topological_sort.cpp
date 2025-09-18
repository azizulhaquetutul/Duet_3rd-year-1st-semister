#include <iostream>
#include <vector>
#include <stack>
using namespace std;
void dfsTopologicalSort(int v, const vector<vector<int>> &adj, vector<bool> &visited, stack<int> &Stack) {
    visited[v] = true;
    for (int neighbor : adj[v]) {
        if (!visited[neighbor]) {
            dfsTopologicalSort(neighbor, adj, visited, Stack);
        }
    }
    Stack.push(v);
}

void topologicalSort(int V, const vector<pair<int, int>> &edges) {
    vector<vector<int>> adj(V);
    for (const auto &edge : edges) {
        adj[edge.first].push_back(edge.second);
    }

    vector<bool> visited(V, false);
    stack<int> Stack;

    for (int i = 0; i < V; ++i) {
        if (!visited[i]) {
            dfsTopologicalSort(i, adj, visited, Stack);
        }
    }

    cout << "Task Scheduling Order: ";
    while (!Stack.empty()) {
        cout << Stack.top() << " ";
        Stack.pop();
    }
    cout << endl;
}

int main() {
    int V = 7;
    vector<pair<int, int>> edges = {{0, 1}, {0, 2}, {1, 2}, {1, 5}, {2, 3}, {5, 3}, {5, 4}, {6, 1}, {6, 5}};
    topologicalSort(V, edges);

    return 0;
}

