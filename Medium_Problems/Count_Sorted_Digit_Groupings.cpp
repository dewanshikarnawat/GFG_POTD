Problem: Count Sorted Digit Groupings
Pattern: Medium

class Solution {
  public:
        int solve(int idx, int prevSum, string &s, vector<vector<int>> &dp) {
        
        if (idx == s.size()) {
            return 1;
        }
        
        if (dp[idx][prevSum] != -1) {
            return dp[idx][prevSum];
        }
        
        int currSum = 0;
        int ways = 0;
        
        for (int i = idx; i < s.size(); i++) {
            currSum += (s[i] - '0');
            
            if (currSum >= prevSum) {
                ways += solve(i + 1, currSum, s, dp);
            }
        }
        
        return dp[idx][prevSum] = ways;
    }
    int validGroups(string &s) {
        vector<vector<int>> dp(101, vector<int>(901, -1));
        
        return solve(0, 0, s, dp);
        
    }
};  
