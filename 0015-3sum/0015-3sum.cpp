class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        for(int i=0 ; i<nums.size()-2; i++)
        {
            if(i>0 && nums[i]==nums[i-1] ) continue;
            int sum=-nums[i];
            int st=i+1,end=nums.size()-1;
            while(st<end)
            {
                if(nums[st]+nums[end]==sum) 
                {   ans.push_back({nums[i],nums[st],nums[end]});
                    st++,end--;
                    while(st<end && nums[st]==nums[st-1]) st++;
                    while(st<end && nums[end]==nums[end+1]) end--;
                }
                else if(nums[st]+nums[end]>sum) end--;
                else st++;
            }
        }
        return ans;
    }
};