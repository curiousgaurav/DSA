class Solution {
public:
    int solve(string& s1, int n, string& s2, int m,
              vector<vector<int>>& dp) {

        if (n == 0)
            return m;

        if (m == 0)
            return n;

        if (dp[n][m] != -1)
            return dp[n][m];

        if (s1[n - 1] == s2[m - 1]) {
            return dp[n][m] =
                solve(s1, n - 1, s2, m - 1, dp);
        }

        int insert = solve(s1, n, s2, m - 1, dp);
        int remove = solve(s1, n - 1, s2, m, dp);
        int replace = solve(s1, n - 1, s2, m - 1, dp);

        return dp[n][m] = 1 + min({
            insert,
            remove,
            replace
        });
    }

    int minDistance(string word1, string word2) {

        int n = word1.size();
        int m = word2.size();

        vector<vector<int>> dp(
            n + 1,
            vector<int>(m + 1, -1)
        );

        return solve(word1, n, word2, m, dp);
    }
};