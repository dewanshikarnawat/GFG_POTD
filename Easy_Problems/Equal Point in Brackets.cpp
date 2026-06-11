//Problem: Equal Point in Brackets
//Topic: Prefix Counting / Two-Pointer Style Traversal on Strings (Bracket Balance Partitioning)
//Pattern: Easy

class Solution {
  public:
    int findIndex(string &s) {
        int n = s.size();

        int totalClose = 0;
        for (char c : s) {
            if (c == ')') totalClose++;
        }

        int openBefore = 0;
        int closeSeen = 0;

        for (int k = 0; k <= n; k++) {
            if (openBefore == (totalClose - closeSeen)) {
                return k;
            }

            if (k < n) {
                if (s[k] == '(') openBefore++;
                else closeSeen++;
            }
        }

        return n;
        
    }
};
