//Problem: Ways to Express as Sum of Consecutives
//Topic: Math + Arithmetic Progression (AP) + Number Theory 
//Pattern: Medium

class Solution {
  public:
    int getCount(int n) {
        int ans = 0;

        for (long long k = 2; k * (k + 1) / 2 <= n; k++) {
            long long rem = n - k * (k - 1) / 2;
            if (rem > 0 && rem % k == 0)
                ans++;
        }

        return ans;
        
    }
};
