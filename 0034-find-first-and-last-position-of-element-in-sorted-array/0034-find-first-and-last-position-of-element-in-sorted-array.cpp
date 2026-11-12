class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        if(!binary_search(nums.begin(),nums.end(),target)) return {-1,-1};
        int f=lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        int l=upper_bound(nums.begin(),nums.end(),target)-nums.begin();
        return {f,l-1};
        
    }
};