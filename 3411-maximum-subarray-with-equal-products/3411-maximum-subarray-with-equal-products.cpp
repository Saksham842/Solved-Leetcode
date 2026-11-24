class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 2;
        int left = 0;
        int last[11] = {};

        for (int right = 0; right < n; right++) {
            int x = nums[right];

            for (int p = 2; p <= 10; p++) {
                if (x % p == 0) {
                    left = max(left, last[p]);
                    last[p] = right + 1;
                }
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};