//Problem: Maximum Area Between Bars
//Topic: Two Pointers
//Pattern: Medium

class Solution {
  public:
    int maxArea(vector<int> &height) {
        int i = 0, j = height.size() - 1;
        int ans = 0;

        while (i < j) {
            int width = j - i - 1;
            ans = max(ans, min(height[i], height[j]) * width);

            if (height[i] < height[j])
                i++;
            else
                j--;
        }

        return ans;
        
    }
};
