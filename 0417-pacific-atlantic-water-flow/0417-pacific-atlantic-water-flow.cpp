class Solution {
public:
    int m, n;

    void dfs(vector<vector<int>>& heights, int i, int j, vector<vector<bool>>& visited) {
        if(i < 0 || j < 0 || i >= m || j >= n || visited[i][j]) return;

        visited[i][j] = true;

        if(i+1 < m && heights[i+1][j] >= heights[i][j])
            dfs(heights, i+1, j, visited);

        if(j+1 < n && heights[i][j+1] >= heights[i][j])
            dfs(heights, i, j+1, visited);

        if(i-1 >= 0 && heights[i-1][j] >= heights[i][j])
            dfs(heights, i-1, j, visited);

        if(j-1 >= 0 && heights[i][j-1] >= heights[i][j])
            dfs(heights, i, j-1, visited);
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();

        vector<vector<bool>> p(m, vector<bool>(n, false));
        vector<vector<bool>> a(m, vector<bool>(n, false));

        for(int i = 0; i < m; i++) {
            dfs(heights, i, 0, p);
            dfs(heights, i, n-1, a);
        }

        for(int j = 0; j < n; j++) {
            dfs(heights, 0, j, p);
            dfs(heights, m-1, j, a);
        }

        vector<vector<int>> ans;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(p[i][j] && a[i][j])
                    ans.push_back({i, j});
            }
        }

        return ans;
    }
};