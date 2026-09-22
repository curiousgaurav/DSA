class Solution {
public:
    int solve(int i, int j, int m, int n,
              vector<vector<int>>& dp,
              vector<vector<int>>& grid) {

        if (i >= m || j >= n) {
            return INT_MAX;
        }

        if (i == m - 1 && j == n - 1) {
            return grid[i][j];
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int down = solve(i + 1, j, m, n, dp, grid);
        int right = solve(i, j + 1, m, n, dp, grid);

        return dp[i][j] = grid[i][j] + min(down, right);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        return solve(0, 0, m, n, dp, grid);
    }
};