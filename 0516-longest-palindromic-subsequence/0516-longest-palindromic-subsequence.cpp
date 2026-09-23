class Solution {
public:

    int solve(string& text1, int n,
              string& text2, int m,
              vector<vector<int>>& dp) {

        if (n == 0 || m == 0) {
            return 0;
        }

        if (dp[n][m] != -1) {
            return dp[n][m];
        }

        if (text1[n - 1] == text2[m - 1]) {
            return dp[n][m] =
                1 + solve(text1, n - 1, text2, m - 1, dp);
        }

        return dp[n][m] = max(
            solve(text1, n - 1, text2, m, dp),
            solve(text1, n, text2, m - 1, dp)
        );
    }

    int longestPalindromeSubseq(string s) {

        string s1 = s;
        reverse(s1.begin(), s1.end());

        int n = s.size();
        int m = s1.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

        return solve(s, n, s1, m, dp);
    }
};