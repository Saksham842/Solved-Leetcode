class Solution {
public:
    int m,n;
    bool DFS(vector<vector<char>>& board, string word,int i, int j, int k , vector<vector<bool>>&visited){
        if(i<0 || j<0 || i==m || j==n || visited[i][j] ) return false;
        if(board[i][j]==word[k]) k++;
        else return false;
        visited[i][j]=true;
        if(k==word.length()) return true;
        bool a1=DFS(board,word,i+1,j,k,visited);
        bool a2=DFS(board,word,i-1,j,k,visited);
        bool a3=DFS(board,word,i,j+1,k,visited);
        bool a4=DFS(board,word,i,j-1,k,visited);
        visited[i][j]=false;
        return a1||a2||a3||a4;
    }
    bool exist(vector<vector<char>>& board, string word) {
        m=board.size();
        n=board[0].size();
        int k=0;
        vector<vector<bool>>visited(m,vector<bool>(n,false));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!visited[i][j] && board[i][j]==word[0] && DFS(board,word,i,j,k,visited)) return true;
            }
        }
        return false;
    }
};