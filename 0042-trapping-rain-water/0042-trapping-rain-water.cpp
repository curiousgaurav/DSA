#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0; // Edge case: empty input

        vector<int> lMax(n), rMax(n);

        // Compute prefix max (lMax)
        lMax[0] = height[0];
        for (int i = 1; i < n; i++) {
            lMax[i] = max(lMax[i - 1], height[i]);
        }

        // Compute suffix max (rMax)
        rMax[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            rMax[i] = max(rMax[i + 1], height[i]);
        }

        // Calculate trapped water
        int totalWater = 0;
        for (int i = 0; i < n; i++) {
            totalWater += min(lMax[i], rMax[i]) - height[i];
        }

        return totalWater;
    }
};

// Driver code

    