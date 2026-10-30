class Solution {
public:
    void dfs(unordered_map<int,vector<int>>& mp,
             vector<pair<int,int>>& nc, int u) {

        if(mp[u].size() == 0) {
            nc[u] = {0, 0};
            return;
        }

        int l = 0, r = 0;

        if(mp[u].size() >= 1) {
            dfs(mp, nc, mp[u][0]);
            l = nc[mp[u][0]].first + nc[mp[u][0]].second + 1;
        }

        if(mp[u].size() >= 2) {
            dfs(mp, nc, mp[u][1]);
            r = nc[mp[u][1]].first + nc[mp[u][1]].second + 1;
        }

        nc[u] = {l, r};
    }

    int countHighestScoreNodes(vector<int>& parents) {
        unordered_map<int,vector<int>> mp;
        map<long long,int,greater<long long>> ans;

        int n = parents.size();

        for(int i = 1; i < n; i++) {
            mp[parents[i]].push_back(i);
        }

        vector<pair<int,int>> nc(n);
        dfs(mp, nc, 0);

        for(int i = 0; i < n; i++) {
            long long l = nc[i].first;
            long long r = nc[i].second;
            long long rem = n - 1 - l - r;

            long long p = 1;

            if(l) p *= l;
            if(r) p *= r;
            if(rem) p *= rem;

            ans[p]++;
        }

        return ans.begin()->second;
    }
};