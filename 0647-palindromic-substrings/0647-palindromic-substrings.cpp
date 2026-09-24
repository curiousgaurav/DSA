class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int dp[n][n];
        int c = 0;

        for (int k = 0; k < n; k++) {
            int i = 0;
            int j = k;

            while (j < n) {

                // Length 1
                if (i == j) {
                    dp[i][j] = 1;
                    c++;
                }

                // Length 2
                else if (j == i + 1) {
                    if (s[i] == s[j]) {
                        dp[i][j] = 1;
                        c++;
                    } else {
                        dp[i][j] = 0;
                    }
                }

                // Length >= 3
                else {
                    if (s[i] == s[j] && dp[i + 1][j - 1] == 1) {
                        dp[i][j] = 1;
                        c++;
                    } else {
                        dp[i][j] = 0;
                    }
                }

                i++;
                j++;
            }
        }

        return c;
    }
};