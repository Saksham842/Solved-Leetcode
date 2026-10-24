class Solution {
public:
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        int n = nums.size(), m = pattern.size();
        vector<int> lps(m, 0);

        for (int i = 1, j = 0; i < m;) {
            if (pattern[i] == pattern[j]) {
                lps[i++] = ++j;
            } else if (j > 0) {
                j = lps[j - 1];
            } else {
                lps[i++] = 0;
            }
        }

        int ans = 0, j = 0;

        for (int i = 0; i < n - 1; i++) {
            int x = (nums[i] < nums[i + 1]) ? 1 :
                    (nums[i] > nums[i + 1]) ? -1 : 0;

            while (j > 0 && x != pattern[j])
                j = lps[j - 1];

            if (x == pattern[j])
                j++;

            if (j == m) {
                ans++;
                j = lps[j - 1];
            }
        }

        return ans;
    }
};