class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        int i=0;
        int j=0;
        int k=0;
        vector<int>arr(n+m);
        while(i<n && j<m){
            if(nums1[i]<nums2[j]){
                arr[k]=nums1[i];
                i++;
                k++;

            }else{
                arr[k]=nums2[j];
                j++;
                k++;
            }
        }
        while(i<n){
            arr[k]=nums1[i];
            k++;
            i++;
        }
        while(j<m){
            arr[k]=nums2[j];
            k++;
            j++;
        }

        int total=m+n;
        if(total%2==0){
            return (arr[total/2]+ arr[total/2-1])/2.0;
        }else{
            return arr[total/2];
        }
        
    }
};