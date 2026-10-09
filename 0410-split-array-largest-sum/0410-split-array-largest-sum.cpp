class Solution {
public:
bool check(int mid,int k,vector<int>& nums){
    int parts =1;
    int sum=0;
    for(auto x:nums){
        if(sum+x>mid){
            parts++;
            sum = x;
        }else{
            sum+=x;
        }
    }
    return parts<=k;


}
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int l = *max_element(nums.begin(), nums.end());
        int h = accumulate(nums.begin(), nums.end(), 0);
        while(l<=h){
            int mid = (l+h)/2;
            if(check(mid,k,nums)){
                h = mid-1;

            }
            else{
                l = mid+1;
            }
        }
        return l;
        
    }
};