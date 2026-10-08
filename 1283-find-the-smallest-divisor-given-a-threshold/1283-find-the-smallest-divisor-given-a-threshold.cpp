class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int l=1;
        int h = *max_element(nums.begin(),nums.end());
        while(l<=h){
            int mid = (l+h)/2;
            int sum=0;

            for(auto n:nums){
                sum += (n+mid-1)/mid;
            }
            if(sum<=threshold){
                h = mid-1;
            }else{
                l = mid+1;
            }
        }
        return l;
        
    }
};