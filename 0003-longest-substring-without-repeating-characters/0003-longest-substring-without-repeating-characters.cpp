class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans=0;
        int n=s.length();
        unordered_map<char,int>m;
        int f=0,sl=0;
        while(sl<n && f<n)
        {
            if(m.find(s[f])==m.end())
            {
                ans=max(ans,f-sl+1);
                m[s[f]]=f;
                f++;
            }
            else
            {   int t=m[s[f]]+1;
                for(int i=sl;i<t;i++) m.erase(s[i]);
                sl=t;  
            }
        }  
        return ans; 
    }
};