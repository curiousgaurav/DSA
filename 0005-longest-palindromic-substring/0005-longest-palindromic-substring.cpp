class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        int m = 0;
        int ans_i = 0, ans_j = 0;

        for (int k = 0; k < n; k++) {
            int i = 0;
            int j = k;

            while (j < n) {

                // Length 1
                if (i == j) {
                    dp[i][j] = 1;
                }

                // Length 2
                else if (j == i + 1) {
                    if (s[i] == s[j]) {
                        dp[i][j] = 1;
                    }
                }

                // Length >= 3
                else {
                    if (s[i] == s[j] && dp[i + 1][j - 1] == 1) {
                        dp[i][j] = 1;
                    }
                }

                // If palindrome, check its length
                if (dp[i][j] == 1) {
                    if (j - i + 1 > m) {
                        m = j - i + 1;
                        ans_i = i;
                        ans_j = j;
                    }
                }

                i++;
                j++;
            }
        }

        return s.substr(ans_i, ans_j - ans_i + 1);
    }
};