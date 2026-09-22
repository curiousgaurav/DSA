class Solution {
public:
    int dp[101][101]; // Assuming max 100x100 grid

    int countPaths(int m, int n, vector<vector<int>>& obstacleGrid) {
        // If out of bounds
        if (m < 0 || n < 0) return 0;

        // If there's an obstacle, return 0 (no path)
        if (obstacleGrid[m][n] == 1) return 0;

        // If we reach the start, return 1 (valid path)
        if (m == 0 && n == 0) return 1;

        // If already computed, return stored value
        if (dp[m][n] != -1) return dp[m][n];

        // Move up and left
        return dp[m][n] = countPaths(m - 1, n, obstacleGrid) + countPaths(m, n - 1, obstacleGrid);
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        memset(dp, -1, sizeof(dp)); // Initialize DP table

        return countPaths(m - 1, n - 1, obstacleGrid);
    }
};
