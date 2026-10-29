class Solution {
public:
    int t[20001][200];
    bool solve(vector<int>&nums,int a , int sum, int i){
        if(i==nums.size()) return false;
        if(a==sum) return true;
        if(t[a][i]!=-1) return t[a][i];
        bool take=solve(nums,a+nums[i],sum,i+1);
        bool skip=solve(nums,a,sum,i+1);
        return t[a][i]= take || skip;
    }
    bool canPartition(vector<int>& nums) {
        memset(t,-1,sizeof(t));
        int sum=0;
        for(int val:nums) sum+=val;
        if(sum%2!=0) return false;
        return solve(nums,0,sum/2,0);
        
    }
};