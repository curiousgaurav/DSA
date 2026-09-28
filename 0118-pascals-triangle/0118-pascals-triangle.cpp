class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> a;

        for (int i = 0; i < numRows; i++) {

            long long ans = 1;
            vector<int> anss;

            anss.push_back(1);

            for (int j = 1; j <= i; j++) {
                ans = ans * (i - j + 1);
                ans = ans / j;

                anss.push_back(ans);
            }

            a.push_back(anss);
        }

        return a;
    }
};