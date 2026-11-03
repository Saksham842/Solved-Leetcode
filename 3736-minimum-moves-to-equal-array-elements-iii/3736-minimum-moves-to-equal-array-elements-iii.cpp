class Solution {
public:
    int minMoves(vector<int>& nums) {
        int val=*max_element(nums.begin(),nums.end());
        int ans=0;
        for(int v:nums) ans+=val-v;
        return ans;
    }
};