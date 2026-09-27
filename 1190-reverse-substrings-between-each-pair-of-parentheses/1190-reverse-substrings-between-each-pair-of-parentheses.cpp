class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> stk;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] != ')') {
                stk.push(s[i]);
            }
            else {
                string temp = "";
                while(stk.top() != '(') {
                    temp += stk.top();
                    stk.pop();
                }
                stk.pop();
                for(int j = 0; j < temp.length(); j++) {
                    stk.push(temp[j]);
                }
            }
        }
        string ans = "";
        while(!stk.empty()) {
            ans += stk.top();
            stk.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};