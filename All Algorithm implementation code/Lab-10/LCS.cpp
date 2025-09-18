
//string1 :lullabybabies
//string2: skullandbones

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void findLCS(const string &X, const string &Y) {
    int m = X.length();
    int n = Y.length();

    // Initialize a 2D DP table with dimensions (m+1) x (n+1)
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Fill the DP table
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (X[i - 1] == Y[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // Reconstruct the LCS from the DP table
    string lcs = "";
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            lcs = X[i - 1] + lcs; // Add character to the front of the LCS
            --i;
            --j;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            --i;
        } else {
            --j;
        }
    }

    // Output the results
    cout << "Longest Common Subsequence: " << lcs << endl;
    cout << "Length of LCS: " << dp[m][n] << endl;
}

int main() {
    string X, Y;

    // Input strings
    cout << "Enter the first string: ";
    cin >> X;
    cout << "Enter the second string: ";
    cin >> Y;

    // Find and display the LCS
    findLCS(X, Y);

    return 0;
}


