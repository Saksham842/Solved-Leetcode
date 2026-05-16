class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       unordered_map<int,int>m;
       vector<int>ans;
       for(int i=0;i<nums.size();i++)
       {
            int other=target-nums[i];
            if(m.find(other)!=m.end())
            {
                ans.push_back(i);
                ans.push_back(m[other]);
                return ans;
            }
            m[nums[i]]=i;
       }
       return ans;
    }
};