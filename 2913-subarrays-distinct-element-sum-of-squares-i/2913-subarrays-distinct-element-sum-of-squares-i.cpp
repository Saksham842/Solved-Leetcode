
class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int ans = 0;
        
        for(int i = 0; i < nums.size(); i++) {
            vector<int> mp(101, 0);
            int cnt = 0;
            
            for(int j = i; j < nums.size(); j++) {
                if(mp[nums[j]] == 0) {
                    cnt++;
                    mp[nums[j]] = 1;
                }
                
                ans += cnt * cnt;
            }
        }
        
        return ans;
    }
};
