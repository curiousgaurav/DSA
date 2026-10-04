class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>s;
        for(auto v:tokens){
            
            if(v=="+"|| v=="-" || v=="*" || v=="/"){
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                int c;
if(v=="+") c = b + a;
else if(v=="-") c = b - a;
else if(v=="*") c = b * a;
else if(v=="/") c = b / a;
                s.push(c);

            }
            else{
                s.push(stoi(v));
            }
        }
        return s.top();
        
    }
};