class Solution {
public:
    vector<string> ans;
    int best;

    void solve(string &s, int i, int left, int right, int open, string temp){
        if(i == s.length()){
            if(left == 0 && right == 0 && open == 0){
                if(temp.length() > best){
                    ans.clear();
                    best = temp.length();
                }

                if(temp.length() == best)
                    ans.push_back(temp);
            }
            return;
        }

        if(s[i] == '('){
            if(left > 0)
                solve(s,i+1,left-1,right,open,temp);

            solve(s,i+1,left,right,open+1,temp+'(');
        }

        else if(s[i] == ')'){
            if(right > 0)
                solve(s,i+1,left,right-1,open,temp);

            if(open > 0)
                solve(s,i+1,left,right,open-1,temp+')');
        }

        else{
            solve(s,i+1,left,right,open,temp+s[i]);
        }
    }

    vector<string> removeInvalidParentheses(string s) {
        int left = 0, right = 0;

        for(char c : s){
            if(c == '(')
                left++;
            else if(c == ')'){
                if(left > 0)
                    left--;
                else
                    right++;
            }
        }

        best = 0;
        ans.clear();

        solve(s,0,left,right,0,"");

        unordered_set<string> st(ans.begin(),ans.end());

        return vector<string>(st.begin(),st.end());
    }
};