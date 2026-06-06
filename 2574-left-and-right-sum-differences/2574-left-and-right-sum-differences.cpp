class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
       vector<int>ans(nums.size(),0);
       for(int i=0 ; i<nums.size() ; i++)
       {
            for(int j=0 ; j<nums.size() ; j++)
            {
                if(i==j) continue;
                else if(j>i) ans[i]+=nums[j];
                else ans[i]-=nums[j];
            }
            ans[i]=abs(ans[i]);
       } 
       return ans;
    }
};