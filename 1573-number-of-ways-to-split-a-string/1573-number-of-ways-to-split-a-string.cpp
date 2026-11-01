class Solution {
public:
    long long m = 1e9 + 7;

    int numWays(string s) {
        int n = 0;

        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '1') n++;
        }

        if(n % 3 != 0) return 0;

        if(n == 0) {
            long long len = s.length() - 1;
            return (len * (len - 1) / 2) % m;
        }

        int k = n / 3;
        int j = 0;
        long long ans = 1;

        for(int i = 0; i < 2; i++) {
            int a = 0, b = 1;

            while(j != s.length() && a != k) {
                if(s[j] == '1') a++;
                j++;
            }

            while(j != s.length() && s[j] == '0') {
                j++;
                b++;
            }

            ans = (ans * b) % m;
        }

        return ans;
    }
};