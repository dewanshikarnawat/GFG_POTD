//Problem: Ways to Tile the Floor
//Topic: Dynamic Programming (DP)
//Pattern: Medium

class Solution {
  public:
    int countWays(int n, int m) {
        const int MOD = 1e9 + 7;

        vector<int> dp(n + 1, 0);
        dp[0] = 1;

        for (int i = 1; i <= n; i++) {
            dp[i] = dp[i - 1];

            if (i >= m) {
                dp[i] = (dp[i] + dp[i - m]) % MOD;
            }
        }

        return dp[n];
    }
};
