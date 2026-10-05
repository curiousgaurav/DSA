class Solution {
public:

    static bool s(string a, string b) {
        return a + b > b + a;
    }

    string largestNumber(vector<int>& nums) {

        vector<string> ans;

        for(auto it : nums) {
            ans.push_back(to_string(it));
        }

        sort(ans.begin(), ans.end(), s);

        if(ans[0] == "0") {
            return "0";
        }

        string a = "";

        for(auto it : ans) {
            a += it;
        }

        return a;
    }
};