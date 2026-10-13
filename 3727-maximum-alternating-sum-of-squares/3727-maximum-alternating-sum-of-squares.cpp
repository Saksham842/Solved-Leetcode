class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end(),[](int &a,int &b){
            return a*a<b*b;
        });
        long long ans=0;
        int i=0,j=n-1;
        while(i<j){
            ans+=(nums[j]*nums[j] - nums[i]*nums[i]);
            i++;j--;
        }
        if(n%2!=0) ans+=(nums[n/2]*nums[n/2]);
        return ans;
    }
};