class Solution {
public:
    int m,n;
    vector<vector<vector<int>>> t;
    int solve(vector<vector<int>>& grid , int i , int j , int ans){
        if(i==m || j==n || i<0 || j<0) return INT_MAX;
        ans=ans^grid[i][j];
        if(i==m-1 && j==n-1) return ans;
        if(t[i][j][ans]!=-1) return t[i][j][ans];
        int left=solve(grid,i,j+1,ans);
        int right=solve(grid,i+1,j,ans);
        return t[i][j][ans]=min(left,right);
    }
    int minCost(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        t.assign(m, vector<vector<int>>(n, vector<int>(1024, -1)));
        return solve(grid,0,0,0); 
    }
};