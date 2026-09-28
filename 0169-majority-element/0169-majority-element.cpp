class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> result;
        
        // Count frequency of each element
        for (int i = 0; i < n; i++) {
            result[nums[i]]++;
        }

        int maxi = 0, ans = 0;

        // Find the element with max frequency
        for (int j = 0; j < n; j++) {
            if (result[nums[j]] > maxi) {
                maxi = result[nums[j]];
                ans = nums[j];
            }
        }

        return ans; // Return the majority element
    }
};