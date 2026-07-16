//Problem: Numbers with Given Digit Sum
//Topic: Dynamic Programming (DP)
//Pattern: Medium

class Solution {
  public:
    int countWays(int n, int sum) {
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));

        // First digit (1-9)
        for (int d = 1; d <= 9; d++) {
            if (d <= sum)
                dp[1][d] = 1;
        }

        // Remaining digits (0-9)
        for (int i = 2; i <= n; i++) {
            for (int s = 0; s <= sum; s++) {
                for (int d = 0; d <= 9; d++) {
                    if (s >= d)
                        dp[i][s] += dp[i - 1][s - d];
                }
            }
        }

        return dp[n][sum] == 0 ? -1 : dp[n][sum];
        
    }
};
