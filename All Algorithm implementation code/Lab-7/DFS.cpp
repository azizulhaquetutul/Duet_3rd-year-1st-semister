#include <iostream>
#include <vector>
using namespace std;
const int WHITE = 0;
const int GRAY = 1;
const int BLACK = 2;
int timeCount = 0;
vector<int> color;
vector<int> discoveryTime;
vector<int> finishTime;
vector<int> predecessor;

void DFS_VISIT(const vector<vector<int>>& adjMatrix, int u)
{
    timeCount++;
    discoveryTime[u] = timeCount;
    color[u] = GRAY;


    for (int v = 0; v < adjMatrix[u].size(); ++v)
    {
        if (adjMatrix[u][v] == 1 && color[v] == WHITE)
        {
            predecessor[v] = u;
            DFS_VISIT(adjMatrix, v);
        }
    }

    color[u] = BLACK;
    timeCount++;
    finishTime[u] = timeCount;
}

void DFS(const vector<vector<int>>& adjMatrix)
{
    int n = adjMatrix.size();
    color.assign(n, WHITE);
    discoveryTime.assign(n, 0);
    finishTime.assign(n, 0);
    predecessor.assign(n, -1);

    timeCount = 0;
    for (int u = 0; u < n; ++u)
    {
        if (color[u] == WHITE)
        {
            DFS_VISIT(adjMatrix, u);
        }
    }
    cout << "Vertex\tDiscovery\tFinish\tPredecessor" << endl;
    for (int u = 0; u < n; ++u)
    {
        cout << u+1 << "\t" << discoveryTime[u] << "\t\t"
             << finishTime[u] << "\t" << predecessor[u]+1 << endl;
    }
}

int main()
{

    vector<vector<int>> adjMatrix =
    {
    {0,1,0,0,0,0,0,0},
    {0,0,1,0,0,0,0,0},
    {0,0,0,1,1,0,0,0},
    {1,0,0,0,0,0,0,0},
    {0,0,0,0,0,1,0,0},
    {0,0,0,0,0,0,1,0},
    {0,0,0,0,1,0,0,1},
    {0,0,0,0,0,0,0,0}
    };


    DFS(adjMatrix);

    return 0;
}

