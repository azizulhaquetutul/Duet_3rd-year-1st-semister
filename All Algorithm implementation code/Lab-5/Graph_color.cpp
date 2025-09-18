#include<bits/stdc++.h>
using namespace std;
int x[100], n, m, scal;

void NextValue(bool G[][10], int k) {
    while (true) {
        x[k] = (x[k] + 1) % (m + 1);
        if (x[k] == 0) return;

        int j;

        for (j = 0; j < n; j++) {
            if (G[k][j] != 0 && (x[k] == x[j])) break;
        }
        if (j == n) break;
    }
}
void mColoring(bool G[][10], int k) {
    while (true) {
        NextValue(G, k);
        if (x[k] == 0) return;
        if (k == n - 1) {
            scal++;
        } else {
            mColoring(G, k + 1);
        }
    }
}

int main() {
    n = 10;

    bool G[][10] =
{{0,1,1,0,1,1,1,0,0,1},{1,0,1,0,1,1,1,0,1,1},{1,1,0,1,1,1,1,1,0,1},{0,0,1,0,1,1,0,0,1,1},{1,1,1,1,0,0,1,1,1,1},{1,1,1,1,0,0,1,1,0,1},{1,1,1,0,1,1,0,0,1,1}
,{0,0,1,0,1,1,0,0,1,1},{0,1,0,1,1,0,1,1,0,0},{1,1,1,1,1,1,1,1,0,0}};    for (int i = 1; i <= n; i++) {
        scal = 0;
        m = i;
        mColoring(G, 0);
        if (scal > 0) {
            cout << "Minimum colors required (M) = " << i
                 << ", Number of solutions = " << scal << endl;
            break;
        }
    }
    return 0;
}

