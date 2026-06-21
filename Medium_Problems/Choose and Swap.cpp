//Problem: Choose and Swap
//Topic: Greedy Algorithm
//Pattern: Medium

class Solution {
public:
    string chooseSwap(string &s) {
        vector<int> first(26, -1);

        // Store first occurrence
        for (int i = 0; i < s.size(); i++) {
            if (first[s[i] - 'a'] == -1)
                first[s[i] - 'a'] = i;
        }

        for (int i = 0; i < s.size(); i++) {
            for (int ch = 0; ch < s[i] - 'a'; ch++) {
                if (first[ch] > i) {
                    char c1 = s[i];
                    char c2 = char(ch + 'a');

                    for (char &c : s) {
                        if (c == c1)
                            c = c2;
                        else if (c == c2)
                            c = c1;
                    }
                    return s;
                }
            }
        }

        return s;
    }
};
