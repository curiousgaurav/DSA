class Solution {
public:
    int maxScore(vector<int>& arr, int k) {
        int n = arr.size();
        int w = n - k;

        int total = 0;

        for(int i = 0; i < n; i++) {
            total += arr[i];
        }

        int window = 0;

        for(int i = 0; i < w; i++) {
            window += arr[i];
        }

        int minWindow = window;

        for(int i = w; i < n; i++) {
            window = window - arr[i-w] + arr[i];

            minWindow = min(minWindow, window);
        }

        return total - minWindow;
    }
};