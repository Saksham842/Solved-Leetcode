class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            if(nums[i]==i && nums[i]<10) return i;
            if(nums[i]>9){
                int k=nums[i];
                int sum=0;
                while(k>0){
                    sum+=k%10;
                    k/=10;
                }
                if(sum==i) return i;
            }
        }
        return -1;
    }
};