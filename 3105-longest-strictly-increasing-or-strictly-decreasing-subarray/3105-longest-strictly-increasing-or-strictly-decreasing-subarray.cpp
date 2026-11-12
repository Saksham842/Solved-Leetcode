class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int inc=0,desc=0,ans=0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]>nums[i+1]){
                desc++;
                inc=0;
                ans=max(ans,desc);
            }
            else if(nums[i]<nums[i+1]){
                inc++;
                desc=0;
                ans=max(ans,inc);
            }
            else{
                inc=0;
                desc=0;
            }
        }
        return ans+1;
    }
};