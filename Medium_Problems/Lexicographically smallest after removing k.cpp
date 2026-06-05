//Problem: Lexicographically smallest after removing k
//Topic: Greedy algorithm + Monotonic Stack
//Language Used: C++(17)

class Solution {
  public:
    bool isPowerOfTwo(int n) {
        return n > 0 && (n & (n - 1)) == 0;
    }
    string lexicographicallySmallest(string &s, int k) {
        int n = s.size();

        if (isPowerOfTwo(n))
            k /= 2;
        else
            k *= 2;

        if (k >= n) return "-1";

        string st;

        for (char c : s) {
            while (!st.empty() && k > 0 && st.back() > c) {
                st.pop_back();
                k--;
            }
            st.push_back(c);
        }

        while (k > 0) {
            st.pop_back();
            k--;
        }

        return st.empty() ? "-1" : st;
        
    }
};
