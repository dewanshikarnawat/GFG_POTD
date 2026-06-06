//Problem: Non-Attacking Black and White Knights
//Topic: Mathematical Counting (Combinatorics)
//Pattern: Medium

class Solution {
  public:
    int numOfWays(int n, int m) {
        long long total = 1LL * n * m;
        
        long long ways = total * (total - 1);
        
        long long attacking = 4LL * (
            max(0, n - 1) * 1LL * max(0, m - 2) +
            max(0, n - 2) * 1LL * max(0, m - 1)
        );
        
        return (int)(ways - attacking);
        
    }
};
