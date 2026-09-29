class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0];  // Initialize max sum
        int currentSum = nums[0];  // Current subarray sum

        for (int i = 1; i < nums.size(); i++) {
            currentSum = max(nums[i], currentSum + nums[i]);  
            maxSum = max(maxSum, currentSum);  
        }
        
        return maxSum;
    }
};
