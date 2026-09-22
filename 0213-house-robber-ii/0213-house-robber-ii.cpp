class Solution {
public:

    int solve(int i, int n, vector<int>& nums, vector<int>& dp) {
        if (i >= n)
            return 0;

        if (dp[i] != -1)
            return dp[i];

        int rob = nums[i] + solve(i + 2, n, nums, dp);
        int skip = solve(i + 1, n, nums, dp);

        return dp[i] = max(rob, skip);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        // Only one house
        if (n == 1)
            return nums[0];

        // Case 1: Don't rob last house
        vector<int> dp1(n, -1);
        int case1 = solve(0, n - 1, nums, dp1);

        // Case 2: Don't rob first house
        vector<int> dp2(n, -1);
        int case2 = solve(1, n, nums, dp2);

        return max(case1, case2);
    }
};