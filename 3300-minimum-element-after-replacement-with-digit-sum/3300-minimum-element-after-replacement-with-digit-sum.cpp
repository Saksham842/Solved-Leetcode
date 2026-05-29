class Solution {
public:
    int solve(int val)
    {   int sum=0;
        while(val>0)
        {
            sum+=val%10;
            val/=10;
        }
        return sum;
    }
    int minElement(vector<int>& nums) {
        int ans=INT_MAX;
        for(int val:nums)
        {
            if(val>9) val=solve(val);
            ans=min(val,ans);
        }
        return ans;
    }
};