class Solution {
public:
    vector<long long> countBlackBlocks(int m, int n, vector<vector<int>>& coordinates) {
        unordered_map<long long , int>mp;
        for(auto p:coordinates){
            int x=p[0];
            int y=p[1];
            if(x-1>=0 && y-1>=0) mp[(long long)(x-1)*n+y-1]++;
            if(x-1>=0 && y<n-1) mp[(long long)(x-1)*n+y]++;
            if(x<m-1 && y-1>=0) mp[(long long)(x)*n+y-1]++;
            if(x<m-1 && y<n-1) mp[(long long)(x)*n+y]++;
        }
        vector<long long>ans(5);
        for(auto p:mp){
            ans[p.second]++;
        }
        ans[0]=(long long)(m-1)*(n-1)-ans[1]-ans[2]-ans[3]-ans[4];
        return ans;
        
    }
};