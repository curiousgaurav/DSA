class Solution {
public:
    string decodeString(string s) {
        stack<int> nums;
        stack<string> st;

        string current = "";
        int num = 0;

        for(char ch : s) {

            if(isdigit(ch)) {
                num = num * 10 + (ch - '0');
            }

            else if(ch == '[') {
                nums.push(num);
                st.push(current);

                num = 0;
                current = "";
            }

            else if(ch == ']') {
                int k = nums.top();
                nums.pop();

                string previous = st.top();
                st.pop();

                string temp = "";

                for(int i = 0; i < k; i++) {
                    temp += current;
                }

                current = previous + temp;
            }

            else {
                current += ch;
            }
        }

        return current;
    }
};