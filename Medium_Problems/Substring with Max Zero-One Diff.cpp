//Problem: Substring with Max Zero-One Diff
//Topic: Array / String + Kadane’s Algorithm (Maximum Subarray Sum)
//Pattern: Medium

class Solution {
  public:
    int maxSubstring(string &s) {
        bool hasZero = false;
        
        for (char c : s) {
            if (c == '0') {
                hasZero = true;
                break;
            }
        }
        
        if (!hasZero) return -1;
        
        int maxEndingHere = 0;
        int maxSoFar = 0;
        
        for (char c : s) {
            int val = (c == '0') ? 1 : -1;
            
            maxEndingHere = max(val, maxEndingHere + val);
            maxSoFar = max(maxSoFar, maxEndingHere);
        }
        
        return maxSoFar;
        
    }
};
