//Problem: Maximum Reachable Index Difference
//Topic: Greedy, String, Dynamic Programming (Right-to-Left DP)
//Pattern: Medium

class Solution {
  public:
    int maxIndexDifference(string &s) {
        int n = s.size();

        vector<int> far(26, -1);   // far[c] = farthest reachable endpoint from a character c

        int ans = -1;

        for (int i = n - 1; i >= 0; i--) {
            int c = s[i] - 'a';

            int endpoint = i;

            if (c < 25 && far[c + 1] != -1)
                endpoint = far[c + 1];

            far[c] = max(far[c], endpoint);

            if (c == 0)
                ans = max(ans, endpoint - i);
        }

        return ans;
        
    }
};
