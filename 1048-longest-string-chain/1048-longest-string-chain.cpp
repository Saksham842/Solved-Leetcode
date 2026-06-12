class Solution {
public:
    bool check(string m , string n)
    {
        if(n.length()-m.length()!=1) return false;
        int i=0,j=0;
        while(j<n.length())
        {
            if(m[i]==n[j])
            {
                i++;j++;
            }
            else j++;
        }
        if(i!=m.length()) return false;
        return true;

    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),[](string& a, string& b)
        {
            return a.length()<b.length();
        });
        int ans=1;
        int n=words.size();
        vector<int>dp(n,1);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(check(words[j],words[i]))
                {
                    dp[i]=max(dp[i],dp[j]+1);
                    ans=max(ans,dp[i]);
                }
            }
        }
        return ans;
    }
};