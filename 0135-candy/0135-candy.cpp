class Solution {
public:
    int candy(vector<int>& ratings) {
        
        int n = ratings.size();
        
        vector<int> candies(n, 1);
        
        // Pass 1: Left to Right
        for(int i = 1; i < n; i++) {
            if(ratings[i] > ratings[i-1]) {
                candies[i] = candies[i-1] + 1;
            }
        }
        
        // Pass 2: Right to Left
        for(int i = n-2; i >= 0; i--) {
            if(ratings[i] > ratings[i+1]) {
                candies[i] = max(candies[i], candies[i+1] + 1);
            }
        }
        
        // Calculate total
        int ans = 0;
        
        for(int i = 0; i < n; i++) {
            ans += candies[i];
        }
        
        return ans;
    }
};