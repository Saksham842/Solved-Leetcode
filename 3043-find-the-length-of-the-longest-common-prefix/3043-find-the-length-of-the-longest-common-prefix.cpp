class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int>s;
        int ans=0;
        for(int val:arr1)
        {
            while(val>0)
            {
                s.insert(val);
                val/=10;
            }
        }
        for(int val:arr2)
        {
            while(val>0)
            {
                if(s.find(val)!=s.end())
                {
                    ans=max(val,ans);
                }
                val/=10;
            }
        }
        if(ans==0) return 0;
        return (int)log10(ans)+1;
    }
};