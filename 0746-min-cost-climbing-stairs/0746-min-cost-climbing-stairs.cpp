class Solution {
public:
    int solve(int i, int n, vector<int>& cost,vector<int>&dp) {
        // Reached or crossed the top
        if (i >= n) {
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }

        int ans = cost[i] + min(
            solve(i + 1, n, cost,dp),
            solve(i + 2, n, cost,dp)
        );
        dp[i]=ans;

        return dp[i];
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>dp(n+1,-1);

        return min(solve(0, n, cost,dp),
                   solve(1, n, cost,dp));
    }
};