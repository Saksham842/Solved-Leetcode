class Solution {
public:
    bool check(unordered_map<int,vector<int>>&adj,int u,vector<bool>& visited , vector<bool>& in){
        visited[u]=true;
        in[u]=true;
        for(int &v:adj[u]){
            if(!visited[v] && check(adj,v,visited,in) ) return true;
            else if(in[v]==true) return true;
        }
        in[u]=false;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<bool>visited(numCourses,false);
        vector<bool>in(numCourses,false);
        unordered_map<int,vector<int>>adj(numCourses);
        for(vector<int>val:prerequisites){
            adj[val[1]].push_back(val[0]);
        }
        for(int i=0;i<numCourses;i++){
            if(!visited[i] && check(adj,i,visited,in)) return false;
        }
        return true;
    }
};