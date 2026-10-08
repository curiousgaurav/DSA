class Solution {
public:

    bool check(int n, vector<int>& bloomDay, int m, int k) {
        int b = 0;
        int c = 0;

        for (auto x : bloomDay) {

            if (x <= n) {
                c++;

                if (c == k) {
                    b++;
                    c = 0;
                }
            }
            else {
                c = 0;
            }
        }

        return b >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {

        int n = bloomDay.size();

        if ((long long)m * k > n) {
            return -1;
        }

        int l = *min_element(bloomDay.begin(), bloomDay.end());
        int h = *max_element(bloomDay.begin(), bloomDay.end());

        while (l <= h) {

            int mid = l + (h - l) / 2;

            if (check(mid, bloomDay, m, k)) {
                h = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }

        return l;
    }
};