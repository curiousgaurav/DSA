class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();

        map<int, int> m;
        int sum = 0;
        int ans = 0;

        for (int i = 0; i < n; i++) {

            if (nums[i] == 0)
                sum--;
            else
                sum++;

            if (sum == 0) {
                ans = i + 1;
            }

            if (m.find(sum) != m.end()) {
                ans = max(ans, i - m[sum]);
            } else {
                m[sum] = i;
            }
        }

        return ans;
    }
};