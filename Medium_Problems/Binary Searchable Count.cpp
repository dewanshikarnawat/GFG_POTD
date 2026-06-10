//Problem: Binary Searchable Count
//Topic: Binary Search + Divide & Conquer
//Pattern: Medium
//Language Used: C++(17)

class Solution {
  public:
    int binarySearchable(vector<int>& arr) {
        int n = arr.size();
        int ans = 0;

        using T = tuple<int,int,long long,long long>;
        stack<T> st;

        st.push({0, n - 1, LLONG_MIN, LLONG_MAX});

        while (!st.empty()) {
            auto [l, r, low, high] = st.top();
            st.pop();

            if (l > r) continue;

            int mid = (l + r) / 2;

            if (arr[mid] > low && arr[mid] < high)
                ans++;

            st.push({l, mid - 1, low, min(high, (long long)arr[mid])});
            st.push({mid + 1, r, max(low, (long long)arr[mid]), high});
        }

        return ans;
        
    }
};
