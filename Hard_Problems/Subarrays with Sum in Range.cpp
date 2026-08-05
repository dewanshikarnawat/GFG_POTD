//Problem: Subarrays with Sum in Range
//Topic: Sliding Window
//Pattern: Hard

class Solution {
  public:
  long long countAtMost(vector<int>& arr, long long k) {
        if (k < 0) return 0;

        long long ans = 0;
        long long sum = 0;
        int left = 0;

        for (int right = 0; right < arr.size(); right++) {
            sum += arr[right];

            while (sum > k) {
                sum -= arr[left];
                left++;
            }

            ans += (right - left + 1);
        }

        return ans;
    }
    int countSubarray(vector<int>& arr, int l, int r) {
        return (int)(countAtMost(arr, r) - countAtMost(arr, (long long)l - 1));
        
    }
};
