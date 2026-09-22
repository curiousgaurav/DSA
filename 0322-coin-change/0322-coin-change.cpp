class Solution {
public:
    int solve(int i, vector<int>& coins, int amount,
              vector<vector<int>>& dp) {

        // Exact amount achieved
        if (amount == 0) {
            return 0;
        }

        // No coins left
        if (i == coins.size()) {
            return 1e9;
        }

        if (dp[i][amount] != -1) {
            return dp[i][amount];
        }

        // Skip current coin
        int skip = solve(i + 1, coins, amount, dp);

        // Take current coin
        int take = 1e9;

        if (amount >= coins[i]) {
            take = 1 + solve(i, coins, amount - coins[i], dp);
        }

        return dp[i][amount] = min(skip, take);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));

        int ans = solve(0, coins, amount, dp);

        if (ans >= 1e9) {
            return -1;
        }

        return ans;
    }
};