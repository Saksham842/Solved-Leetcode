class Solution {
public:
    void solve(int val,vector<int>&ans)
    {
        int n=ans.size();
        while(val>0)
        {
            ans.push_back(val%10);
            val/=10;
        }
        reverse(ans.begin()+n,ans.end());
    }
    vector<int> separateDigits(vector<int>& nums) {
        vector<int>ans;
        for(int val:nums)
        {
            if(val>=10)
            {
                solve(val,ans);
            }
            else ans.push_back(val);
        }
        return ans;
    }
};