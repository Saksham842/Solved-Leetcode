class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> stk;
        string ans = "";

        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '(') {
                if(!stk.empty())
                    ans += '(';
                stk.push('(');
            }
            else {
                stk.pop();
                if(!stk.empty())
                    ans += ')';
            }
        }

        return ans;
    }
};