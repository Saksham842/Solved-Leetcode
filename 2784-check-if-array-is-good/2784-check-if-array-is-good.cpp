class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>m;
        for(int val:nums)
        {
            m[val]++;
        }
        for(int i=1;i<n-1;i++)
        {
            if(m.find(i)!=m.end())
            {
                if(m[i]!=1) return false;
            }
            else return false;
        }
        if(m[n-1]!=2) return false;
        return true;
    }
};