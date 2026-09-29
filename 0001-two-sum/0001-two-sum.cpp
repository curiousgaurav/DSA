class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mt;
        for (int i = 0; i < nums.size(); i++) {
            int a = nums[i];
            int more = target - a;
            if (mt.find(more) != mt.end()) {
                return {mt[more], i};
            }
            mt[a] = i;  // Store the index of the current number
        }
        return {}; // Return an empty vector if no solution is found
    }
};
