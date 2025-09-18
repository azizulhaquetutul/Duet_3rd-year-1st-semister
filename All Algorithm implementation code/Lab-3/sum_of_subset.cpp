#include <iostream>
#include <vector>
using namespace std;

void PrintSolution(const vector<int>& x, const vector<int>& w) {
    cout << "{ ";
    for (int i = 0; i < x.size(); i++) {
        if (x[i] == 1)
            cout << w[i] << " ";
    }
    cout << "}" << endl;
}

void SumOfSubsets(const vector<int>& w, vector<int>& x, int m, int s, int k, int r) {
    // Generate left child: Include w[k]
    x[k] = 1;
    if (s + w[k] == m) {
        PrintSolution(x, w);  // Subset found
    } else if (s + w[k] + w[k + 1] <= m && k + 1 < w.size()) {  // Ensure we don’t go out of bounds
        SumOfSubsets(w, x, m, s + w[k], k + 1, r - w[k]);
    }

    // Generate right child: Exclude w[k]
    x[k] = 0;
    if (s + r - w[k] >= m && s + w[k + 1] <= m && k + 1 < w.size()) {  // Ensure we don’t go out of bounds
        SumOfSubsets(w, x, m, s, k + 1, r - w[k]);
    }
}

int main() {
    int n, m;
    cout << "Enter the number of elements: ";
    cin >> n;
    vector<int> w(n);
    cout << "Enter the elements in non-decreasing order: ";
    for (int i = 0; i < n; i++)
        cin >> w[i];
    cout << "Enter the target sum: ";
    cin >> m;

    vector<int> x(n, 0);
    int totalSum = 0;
    for (int i = 0; i < n; i++)
        totalSum += w[i];

    cout << "Subsets with sum " << m << " are:\n";
    SumOfSubsets(w, x, m, 0, 0, totalSum);
    return 0;
}

