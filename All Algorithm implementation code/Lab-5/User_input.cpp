#include <iostream>
#include <vector>
using namespace std;

const int MAX = 20;
int n, m;
int G[MAX][MAX];
int x[MAX];

void NextValue(int k) {
    while (true) {
        x[k] = (x[k] + 1) % (m + 1);
        if (x[k] == 0) return;

        int j;
        for (j = 1; j <= n; j++) {
            if (G[k][j] != 0 && x[k] == x[j]) break;
        }

        if (j == n + 1) return;
    }
}


void mColoring(int k) {
    while (true) {
        NextValue(k);
        if (x[k] == 0) return;

        if (k == n) {

            for (int i = 1; i <= n; i++) {
                cout << x[i] << " ";
            }
            cout << endl;
        } else {
            mColoring(k + 1);
        }
    }
}

int main() {
    cout << "Enter the number of vertices: ";
    cin >> n;
    cout << "Enter the number of colors: ";
    cin >> m;
    cout << "Enter the adjacency matrix:\n";

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> G[i][j];
        }
    }


    for (int i = 1; i <= n; i++) {
        x[i] = 0;
    }

    cout << "Possible colorings:\n";
    mColoring(1);
    return 0;
}


