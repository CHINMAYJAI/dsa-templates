#include <bits/stdc++.h>
using namespace std;

int levenshteinDistance(const string &s1, const string &s2) {
    int m = s1.length();
    int n = s2.length();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1));

    // Base cases
    for (int i = 0; i <= m; i++)
        dp[i][0] = i;
    for (int j = 0; j <= n; j++)
        dp[0][j] = j;

    // Fill DP table
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = 1 + min({
                    dp[i - 1][j],     // Delete
                    dp[i][j - 1],     // Insert
                    dp[i - 1][j - 1]  // Replace
                });
            }
        }
    }

    return dp[m][n];
}

int main() {
    string s1, s2;

    cout << "Enter first string: ";
    cin >> s1;

    cout << "Enter second string: ";
    cin >> s2;

    cout << "Levenshtein Distance: "
         << levenshteinDistance(s1, s2) << endl;

    return 0;
}