//Problem: Substrings with more 1's than 0's
//Topic: Prefix Sum, Fenwick Tree (Binary Indexed Tree), Coordinate Compression, Binary Search
//Pattern: Hard

class Solution {
public:
    class BIT {
    public:
        vector<int> bit;
        int n;

        void init(int sz) {
            n = sz;
            bit.assign(n + 1, 0);
        }

        void update(int idx, int val) {
            while (idx <= n) {
                bit[idx] += val;
                idx += idx & -idx;
            }
        }

        int query(int idx) {
            int sum = 0;
            while (idx > 0) {
                sum += bit[idx];
                idx -= idx & -idx;
            }
            return sum;
        }
    };

    int countSubstring(string& s) {
        int n = s.size();

        vector<int> pref(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            pref[i] = pref[i - 1] + (s[i - 1] == '1' ? 1 : -1);
        }

        vector<int> vals = pref;
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());

        BIT ft;
        ft.init(vals.size());

        long long ans = 0;

        for (int x : pref) {
            int idx = lower_bound(vals.begin(), vals.end(), x) - vals.begin() + 1;
            ans += ft.query(idx - 1);
            ft.update(idx, 1);
        }

        return (int)ans;
    }
};
