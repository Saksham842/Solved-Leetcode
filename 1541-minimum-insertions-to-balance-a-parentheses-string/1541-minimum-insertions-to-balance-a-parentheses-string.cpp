class Solution {
public:
    int minInsertions(string s) {
        int ans=0;
        int i=0;
        stack<char>stk;
        while(i<s.length()){
            if(s[i]=='(') stk.push(s[i]);
            else{
                if(stk.empty()) ans++;
                else stk.pop();
                if(i==s.length()-1 || s[i]!=s[i+1]) ans++;
                else i++;
            }
            i++;
        }
        ans+=2*stk.size();
        return ans;
    }
};