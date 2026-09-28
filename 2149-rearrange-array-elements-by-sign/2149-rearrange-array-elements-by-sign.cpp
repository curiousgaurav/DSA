class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> positive, negative;

        
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                positive.push_back(nums[i]);
            } else {
                negative.push_back(nums[i]);
            }
        }

        vector<int> result;
        
        for (int j = 0; j < n / 2; j++) {
            result.push_back(positive[j]);  
            result.push_back(negative[j]);  
        }
        return result;
    }
};
