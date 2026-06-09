class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int a=INT_MAX;
        int b=INT_MIN;
        for(int val:nums)
        {
            a=min(a,val);
            b=max(b,val);
        }
        long long ans=(long long)(b-a)*k;
        return ans;
    }
};