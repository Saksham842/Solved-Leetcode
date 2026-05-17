class Solution {
public:
    bool solve(vector<int>& arr, int idx, vector<bool>&vis)
    {
        int n=arr.size();
        if(idx>=n || idx<0) return false;
        if(arr[idx]==0) return true;
        if(vis[idx]) return false;
        vis[idx]=true; 
        bool add=solve(arr,idx+arr[idx],vis);
        bool sub=solve(arr,idx-arr[idx],vis);
        return add || sub;
    }
    bool canReach(vector<int>& arr, int start) {
        vector<bool>vis(arr.size(),false);
        return solve(arr,start,vis);
    }
};