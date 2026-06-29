//Problem: Max Dot Product with 0 Insertions
//Topic: Dynamic Programming
//Pattern: Medium

class Solution {
  public:
    int maxDotProduct(vector<int>& a, vector<int>& b) {
        int n = a.size();
        int m = b.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int j = 1; j <= m; j++)
            dp[0][j] = INT_MIN;

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= min(i, m); j++) {

                dp[i][j] = dp[i - 1][j];

                if (j > 0 && dp[i - 1][j - 1] != INT_MIN) {
                    dp[i][j] = max(dp[i][j],
                                   dp[i - 1][j - 1] + a[i - 1] * b[j - 1]);
                }
            }
        }

        return dp[n][m];
        
    }
};
