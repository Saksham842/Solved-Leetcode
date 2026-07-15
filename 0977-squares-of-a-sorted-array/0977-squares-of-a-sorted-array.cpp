class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int i=0,j=nums.size()-1;
        int k=j;
        vector<int>ans(nums.size(),0);
        while(i<=j)
        {
            int a=nums[i]*nums[i];
            int b=nums[j]*nums[j];
            if(b<a)
            {
                ans[k]=a;
                i++;
            }
            else
            {
                ans[k]=b;
                j--;
            }
            k--;
        }
        return ans;
    }
};