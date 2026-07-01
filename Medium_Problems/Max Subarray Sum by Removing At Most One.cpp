//Problem: Max Subarray Sum by Removing At Most One
//Topic: Dynamic Programming (Kadane's Algorithm variation)
//Pattern: Medium

int n = arr.size();

        int noDelete = arr[0];
        int oneDelete = INT_MIN;
        int ans = arr[0];

        for(int i = 1; i < n; i++) {
            int prevNoDelete = noDelete;

            noDelete = max(arr[i], noDelete + arr[i]);
            oneDelete = max(oneDelete + arr[i], prevNoDelete);

            ans = max(ans, max(noDelete, oneDelete));
        }

        return ans;
