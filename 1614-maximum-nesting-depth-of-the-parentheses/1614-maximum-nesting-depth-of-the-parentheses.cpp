class Solution {
public:
    int maxDepth(string s) {
        int ans=0;
        int temp=0;
        stack<char>stk;
        int i=0;
        while(!stk.empty() || i<s.length()){
            if(s[i]=='('){
                stk.push(s[i]);
                temp++;
                ans=max(ans,temp);
            }
            else if(s[i]==')'){
                stk.pop();
                temp--;
            }
            i++;
        }
        return ans;
    }
};