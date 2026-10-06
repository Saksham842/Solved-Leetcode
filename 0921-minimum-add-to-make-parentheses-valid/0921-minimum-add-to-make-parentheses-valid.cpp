class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char>stk;
        int ans=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(') stk.push(s[i]);
            else{
                if(stk.empty()) ans++;
                else stk.pop();
            }
        }
        if(!stk.empty()) ans+=stk.size();
        return ans;
    }
};