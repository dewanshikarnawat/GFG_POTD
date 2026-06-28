//Problem: k Times Appearing Adjacent Two 1's
//Topic: Dynamic Programming (DP), Strings, State DP
//Pattern: Medium

class Solution {
  public:
    int countStrings(int n, int k) {
        const int MOD = 1000000007;

        vector<vector<int>> prev(k + 1, vector<int>(2, 0));
        vector<vector<int>> curr(k + 1, vector<int>(2, 0));

        prev[0][0] = 1;
        prev[0][1] = 1;

        for (int i = 2; i <= n; i++) {
            for (int j = 0; j <= k; j++) {
                curr[j][0] = (prev[j][0] + prev[j][1]) % MOD;

                long long ways = prev[j][0];
                if (j > 0)
                    ways += prev[j - 1][1];

                curr[j][1] = ways % MOD;
            }

            prev.swap(curr);

            for (int j = 0; j <= k; j++) {
                curr[j][0] = curr[j][1] = 0;
            }
        }

        return (prev[k][0] + prev[k][1]) % MOD;
        
    }
};
