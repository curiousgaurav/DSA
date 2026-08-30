class Solution {
public:
    int maxArea(vector<int>& height) {
        int area = 0;
        int l = 0, r = height.size() - 1;

        while (l < r) {
            int h = min(height[l], height[r]);
            area = max(area, h * (r - l));

            if (height[l] < height[r])
                l++;
            else
                r--;
        }
        return area;
    }
};
