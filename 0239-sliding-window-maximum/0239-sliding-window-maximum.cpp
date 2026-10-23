class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int,greater<int>>ds;
        vector<int>ans;
        int n=nums.size();
        for(int i=0;i<k;i++){
            ds.insert(nums[i]);
        }
        ans.push_back(*ds.begin());
        for(int i=1;i<=n-k;i++){
            int l=nums[i-1];
            int c=nums[i+k-1];
            ds.erase(ds.find(l));
            ds.insert(c);
            ans.push_back(*ds.begin());
        }
        return ans;
    }
};