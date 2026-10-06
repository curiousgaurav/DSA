class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        int cnt = 0;

        for (char a : s) {
            if (a == '(') {
                st.push(a);
            }
            else {
                if (!st.empty()) {
                    st.pop();
                }
                else {
                    cnt++;
                }
            }
        }

        return cnt + st.size();
    }
};