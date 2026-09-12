class Solution {
public:
    bool checkValidString(string s) {

        int low = 0;
        int high = 0;

        for(char a : s) {

            if(a == '(') {
                low++;
                high++;
            }

            else if(a == ')') {
                low--;
                high--;
            }

            else { // '*'
                low--;     // '*' acts as ')'
                high++;    // '*' acts as '('
            }

            if(high < 0)
                return false;

            if(low < 0)
                low = 0;
        }

        return low == 0;
    }
};