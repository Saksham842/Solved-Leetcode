class Solution {
public:
    int m,n;
    int DFS(vector<vector<int>>& grid,int i, int j, vector<vector<bool>>&visited,int k){
        if(i<0 || j<0 || i==m || j==n || visited[i][j] || grid[i][j]==0 ) return 0;
        visited[i][j]=true;
        int a1=DFS(grid,i+1,j,visited,k)%k;
        int a2=DFS(grid,i-1,j,visited,k)%k;
        int a3=DFS(grid,i,j+1,visited,k)%k;
        int a4=DFS(grid,i,j-1,visited,k)%k;
        return a1+a2+a3+a4+grid[i][j];
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        m=grid.size();
        n=grid[0].size();
        int ans=0;
        vector<vector<bool>>visited(m,vector<bool>(n,false));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!visited[i][j] && grid[i][j]!=0 ){
                    if(DFS(grid,i,j,visited,k)%k==0) ans++;
                }
            }
        }
        return ans; 
    }
};