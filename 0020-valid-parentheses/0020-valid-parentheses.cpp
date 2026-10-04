class Solution {
public:
    bool isValid(string s) {
        map<char, int> mp;
        mp['('] = 1;
        mp[')'] = -1;
        mp['['] = 2;
        mp[']'] = -2;
        mp['{'] = 3;
        mp['}'] = -3;

        stack<char> ss;

        for (char v : s) {
            if (v == '(' || v == '[' || v == '{') {
                ss.push(v);
            }
            else {
                if (ss.empty()) {
                    return false;
                }

                if (mp[v] + mp[ss.top()] != 0) {
                    return false;
                }

                ss.pop();
            }
        }

        return ss.empty();
    }
};