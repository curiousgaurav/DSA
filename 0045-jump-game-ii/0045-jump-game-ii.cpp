class Solution {
public:
    int jump(vector<int>& nums) {
        int r=0;
        int n=nums.size();
        int l=0;
        int jump=0;
        while(r<n-1){
            int nextr=r;
            for(int i=l;i<=r;i++){
                nextr=max(nextr,nums[i]+i);
            }
            jump++;
            l=r+1;
            r=nextr;
            

        }
        return jump;
        
    }
};