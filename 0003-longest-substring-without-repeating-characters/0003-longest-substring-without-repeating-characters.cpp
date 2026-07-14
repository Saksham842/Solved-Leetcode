class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans=0;
        int n=s.length();
        unordered_map<char,int>m;
        int f=0,sl=0;
        while(f<n)
        {
            if(m.find(s[f])!=m.end() && sl<=m[s[f]])
            {
                sl=m[s[f]]+1;
                m[s[f]]=f;
               
            }
                ans=max(ans,f-sl+1);
                m[s[f]]=f;
                f++;
        }  
        return ans; 
    }
};