//Problem: Count Pairs Divisible By K
//Topic: Hashing / Frequency Array + Modulo Arithmetic + Pair Counting + One-pass Traversal
//Pattern: Medium

class Solution {
  public:
    int countKdivPairs(vector<int>& arr, int k) {
        vector<int> freq(k, 0);
        int ans = 0;

        for (int num : arr) {
            int rem = num % k;
            int need = (k - rem) % k;

            ans += freq[need];
            freq[rem]++;
        }

        return ans;
        
    }
};
