//Problem: Subsets with Products of Distinct Primes
//Topic: Dynamic Programming (DP)
//Pattern: Hard

class Solution {
  public:
    int countSubsets(vector<int> &arr) {
        const int MOD = 1e9 + 7;
        vector<int> primes = {2,3,5,7,11,13,17,19,23,29};

        vector<int> freq(31, 0);
        for (int x : arr) freq[x]++;

        vector<int> mask(31, -1);

        for (int x = 2; x <= 30; x++) {
            int t = x;
            int m = 0;
            bool ok = true;

            for (int i = 0; i < 10; i++) {
                int p = primes[i];
                if (t % (p * p) == 0) {
                    ok = false;
                    break;
                }
                if (t % p == 0)
                    m |= (1 << i);
            }

            if (ok) mask[x] = m;
        }

        vector<long long> dp(1 << 10, 0);
        dp[0] = 1;

        for (int val = 2; val <= 30; val++) {
            if (freq[val] == 0 || mask[val] == -1) continue;

            int m = mask[val];

            for (int s = (1 << 10) - 1; s >= 0; s--) {
                if ((s & m) == 0) {
                    dp[s | m] = (dp[s | m] + dp[s] * freq[val]) % MOD;
                }
            }
        }

        long long ans = 0;
        for (auto x : dp) ans = (ans + x) % MOD;
        ans = (ans - 1 + MOD) % MOD;

        long long mul = 1, base = 2;
        int ones = freq[1];
        while (ones) {
            if (ones & 1) mul = mul * base % MOD;
            base = base * base % MOD;
            ones >>= 1;
        }

        return ans * mul % MOD;
        
    }
};
