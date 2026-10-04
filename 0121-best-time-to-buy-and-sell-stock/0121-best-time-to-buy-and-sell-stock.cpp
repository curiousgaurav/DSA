class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int b = prices[0];
        int ans = 0;

        
        for(int i=1;i<n;i++){
            if(prices[i]<b){
                b=prices[i];

            }
            else{
                ans = max(ans,prices[i]-b);
            }


        }
        return ans;
        
    }
};