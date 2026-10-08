class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());

        while (l <= r) {
            int mid = l + (r - l) / 2;
            long long sum = 0;

            for (int n : piles) {
                sum += (n + mid - 1) / mid;
            }

            if (sum <= h) {
                r = mid - 1;   // mid works, try smaller
            } else {
                l = mid + 1;   // mid doesn't work, go bigger
            }
        }

        return l;
    }
};