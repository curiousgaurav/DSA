class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();

        int m = *max_element(arr.begin(), arr.end());

        vector<int> a;

        for(int i = 1; i <= m; i++){
            a.push_back(i);
        }

        for(auto x : arr){
            auto it = find(a.begin(), a.end(), x);

            if(it != a.end()){
                a.erase(it);
            }
        }

        // Need to consider numbers after m also
        int x = m + 1;

        while(a.size() < k){
            a.push_back(x);
            x++;
        }

        return a[k-1];
    }
};