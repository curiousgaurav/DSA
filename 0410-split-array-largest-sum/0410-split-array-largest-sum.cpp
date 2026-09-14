class Solution {
public:

    bool check(vector<int>& nums, int k, int mid) {

        int sum = 0;
        int cnt = 1;

        for(int i = 0; i < nums.size(); i++) {

            if(sum + nums[i] <= mid) {
                sum += nums[i];
            }
            else {
                cnt++;
                sum = nums[i];
            }
        }

        return cnt <= k;
    }

    int splitArray(vector<int>& nums, int k) {

        int n = nums.size();

        int m = *max_element(nums.begin(), nums.end());

        int sum = 0;

        for(int i = 0; i < n; i++) {
            sum += nums[i];
        }

        int lo = m;
        int hi = sum;
        int ans = sum;

        while(lo <= hi) {

            int mid = lo + (hi - lo) / 2;

            if(check(nums, k, mid)) {
                ans = mid;
                hi = mid - 1;
            }
            else {
                lo = mid + 1;
            }
        }

        return ans;
    }
};