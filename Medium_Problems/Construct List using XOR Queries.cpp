//Problem: Construct List using XOR Queries
//Topic: Array + Bit Manipulation
//Pattern: Medium

class Solution {
  public:
    vector<int> constructList(vector<vector<int>> &queries) {
         vector<int> arr;
        arr.push_back(0);   // ✅ important initial value

        int xorMask = 0;

        for (auto &q : queries) {
            int type = q[0];
            int x = q[1];

            if (type == 0) {
                arr.push_back(x ^ xorMask);
            } 
            else {
                xorMask ^= x;
            }
        }

        for (int &val : arr) {
            val ^= xorMask;
        }

        sort(arr.begin(), arr.end());
        return arr;
        
    }
};
