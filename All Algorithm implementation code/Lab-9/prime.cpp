#include <iostream>
#include <vector>
#include <climits>

using namespace std;

const int INF = INT_MAX;

int Prim(int n, vector<vector<int>>& cost, vector<pair<int, int>>& t) {
    vector<int> near(n + 1, INF);
    int mincost = 0;


    int l = -1, k = -1, min = INF;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (cost[i][j] < min) {
                min = cost[i][j];
                l = i;
                k = j;
            }
        }
    }

    t[1] = {l, k};
    mincost += cost[l][k];
    near[l] = near[k] = 0;


    for (int i = 1; i <= n; i++) {
        if (near[i] != 0) {
            near[i] = (cost[i][l] < cost[i][k]) ? l : k;
        }
    }


    for (int i = 2; i < n; i++) {
        int j = -1, min = INF;


        for (int v = 1; v <= n; v++) {
            if (near[v] != 0 && cost[v][near[v]] < min) {
                min = cost[v][near[v]];
                j = v;
            }
        }

        t[i] = {j, near[j]};
        mincost += cost[j][near[j]];
        near[j] = 0;


        for (int v = 1; v <= n; v++) {
            if (near[v] != 0 && cost[v][near[v]] > cost[v][j]) {
                near[v] = j;
            }
        }
    }

    return mincost;
}

int main() {
    int n;

    cout << "Enter the number of vertices: ";
    cin >> n;

    vector<vector<int>> cost(n + 1, vector<int>(n + 1, INF));

    cout << "Enter the adjacency matrix (use " << INF << " for infinity):\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> cost[i][j];
        }
    }

    vector<pair<int, int>> t(n);
    int mincost = Prim(n, cost, t);

    cout << "Edges in the minimum-cost spanning tree:\n";
    for (int i = 1; i < n; i++) {
        cout << t[i].first << " - " << t[i].second << "\n";
    }
    cout << "Minimum cost: " << mincost << endl;

    return 0;
}

