//Problem: Check Repeated Substring with K Replacements
//Topic: Strings + Hashing (frequency counting).
//Pattern: Medium

class Solution {
  public:
    bool kSubstr(string &s, int k) {
        int n = s.size();

        if (n % k != 0) return false;

        unordered_map<string, int> freq;
        int blocks = n / k;
        int mx = 0;

        for (int i = 0; i < n; i += k) {
            string part = s.substr(i, k);
            mx = max(mx, ++freq[part]);
        }

        return (mx == blocks || mx == blocks - 1);
        
    }
};
