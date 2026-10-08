class Solution {
public:

bool check(int mid,vector<int>& weights, int days){
    int current = 0;
    int usedDays = 1;

    for (int w : weights) {
        if (current + w > mid) {
            usedDays++;
            current = w;
        } else {
            current += w;
        }
    }

    return usedDays <= days;
}
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int l = *max_element(weights.begin(),weights.end());
        int h = accumulate(weights.begin(), weights.end(), 0);

        while(l<=h){
            int mid =(l+h)/2;
            if(check(mid,weights,days)){
                h = mid-1;
            }else{
                l = mid+1;
            }
        }
        return l;
        
    }
};