class Solution {
public:
    vector<vector<int>> ans;

    void solve(vector<int>& nums, vector<int>& curr, vector<bool>& used) {
        if (curr.size() == nums.size()) {
            ans.push_back(curr);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) continue;

            // choose
            used[i] = true;
            curr.push_back(nums[i]);

            solve(nums, curr, used);

            // backtrack
            curr.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> curr;
        vector<bool> used(nums.size(), false);

        solve(nums, curr, used);
        sort(ans.begin(), ans.end());

ans.erase(unique(ans.begin(), ans.end()), ans.end());
return ans;

        
    }
};