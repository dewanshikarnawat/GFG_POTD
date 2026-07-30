//Problem: Maximum Subset XOR
//Topic: Bit Manipulation
//Pattern: Medium

class Solution {
  public:
    int maxSubsetXOR(vector<int> &arr) {
        int n = arr.size();
        int index = 0;

        // Perform Gaussian Elimination
        for (int bit = 31; bit >= 0; bit--) {

            int maxIndex = -1;

            // Find an element with current bit set
            for (int i = index; i < n; i++) {
                if (arr[i] & (1 << bit)) {
                    maxIndex = i;
                    break;
                }
            }

            if (maxIndex == -1)
                continue;

            swap(arr[index], arr[maxIndex]);

            // Eliminate current bit from all other numbers
            for (int i = 0; i < n; i++) {
                if (i != index && (arr[i] & (1 << bit))) {
                    arr[i] ^= arr[index];
                }
            }

            index++;
        }

        int ans = 0;

        for (int x : arr)
            ans ^= x;

        return ans;
        
    }
};
