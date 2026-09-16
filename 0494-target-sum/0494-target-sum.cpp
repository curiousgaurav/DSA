class Solution {
public:

    int solve(int i, vector<int>& nums, int target) {

        if(i == nums.size()) {
            if(target == 0)
                return 1;
            return 0;
        }

        // take +
        int plus = solve(i + 1, nums, target - nums[i]);

        // take -
        int minus = solve(i + 1, nums, target + nums[i]);

        return plus + minus;
    }

    int findTargetSumWays(vector<int>& nums, int target) {

        return solve(0, nums, target);
    }
};