class Solution {
public:

    bool check(vector<int>& nums, int k, long long mid) {
        int parts = 1;
        long long curr = 0;

        for (int x : nums) {

            // Single element itself is greater than mid
            if (x > mid)
                return false;

            if (curr + x <= mid) {
                curr += x;
            }
            else {
                // Start a new subarray
                parts++;
                curr = x;
            }
        }

        return parts <= k;
    }

    int splitArray(vector<int>& nums, int k) {

        long long l = *max_element(nums.begin(), nums.end());
        long long h = 0;

        for (int x : nums)
            h += x;

        long long ans = h;

        while (l <= h) {

            long long mid = l + (h - l) / 2;

            if (check(nums, k, mid)) {
                // mid is possible
                ans = mid;
                h = mid - 1;
            }
            else {
                // mid is too small
                l = mid + 1;
            }
        }

        return ans;
    }
};