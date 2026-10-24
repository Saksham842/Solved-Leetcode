class Solution {
public:
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        int n=nums.size(),m=pattern.size();
        int ans=0;
        for(int i=0;i<n-m;i++){
            int j=i;
            bool flag=true;
            for(int k=0;k<m;k++){
                if(pattern[k]==1){
                    if(nums[j]<nums[j+1]) j++;
                    else {flag=false ; continue;}
                }
                else if(pattern[k]==-1){
                    if(nums[j]>nums[j+1]) j++;
                    else {flag=false ; continue;}
                }
                else{
                    if(nums[j]==nums[j+1]) j++;
                    else {flag=false ; continue;}
                }
            }
            if(flag) ans++;
        }
        return ans;
    }
};