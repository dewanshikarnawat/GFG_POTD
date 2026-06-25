//Problem: N-Digit Numbers with Increasing Digits
//Topic: Backtracking
//Pattern: Medium

class Solution {
  public:
  void generate(int pos, int n, int lastDigit, string &curr,
                  vector<int> &ans) {
        if (pos == n) {
            ans.push_back(stoi(curr));
            return;
        }

        for (int d = lastDigit + 1; d <= 9; d++) {
            curr.push_back(d + '0');
            generate(pos + 1, n, d, curr, ans);
            curr.pop_back();
        }
    }
    vector<int> increasingNumbers(int n) {
        vector<int> ans;

        if (n == 1) {
            for (int i = 0; i <= 9; i++)
                ans.push_back(i);
            return ans;
        }

        if (n > 10) return ans;

        string curr;
        for (int first = 1; first <= 9; first++) {
            curr.push_back(first + '0');
            generate(1, n, first, curr, ans);
            curr.pop_back();
        }

        return ans;
        
    }
};
