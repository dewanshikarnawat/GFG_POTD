//Problem: Rearrange the Array
//Topic: Permutation + Graph (Cycle Detection) + Math (LCM & GCD)
//pattern: Hard

class Solution {
  public:
  const int MOD = 1e9 + 7;

    long long gcd(long long a, long long b) {
        while (b) {
            long long t = a % b;
            a = b;
            b = t;
        }
        return a;
    }
    int minOperations(vector<int> &b) {
        int n = b.size();

        vector<bool> vis(n, false);
        long long lcm = 1;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                int curr = i;
                int len = 0;

                while (!vis[curr]) {
                    vis[curr] = true;
                    curr = b[curr] - 1; // convert to 0-based indexing
                    len++;
                }

                lcm = (lcm / gcd(lcm, len)) * len;
            }
        }

        return lcm % MOD;
        
    }
};
