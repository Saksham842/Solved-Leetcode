class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n=nums.size();
        int maxEl=n-1;
        int c=0;
        for(int num:nums)
        {
            int val=abs(num);
            if(val>maxEl) return false;
            else if(val==maxEl) c++;
            if(nums[val]<0)
            {
                if(val!=maxEl) return false;
                else if(c>2) return false;
            }
            else nums[val]*=-1;
        }
        return true;
    }
};