class Solution {
public:
    string shortestCommonSupersequence(string X, string Y) {
        int n = X.size(), m = Y.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        // LCS DP
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(X[i-1] == Y[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }

        // Build SCS
        string ans = "";
        int i = n, j = m;
        while(i > 0 && j > 0) {
            if(X[i-1] == Y[j-1]) {
                ans += X[i-1];
                i--; j--;
            }
            else if(dp[i-1][j] > dp[i][j-1]) {
                ans += X[i-1];
                i--;
            }
            else {
                ans += Y[j-1];
                j--;
            }
        }

        while(i > 0) ans += X[--i];
        while(j > 0) ans += Y[--j];

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
