class Solution {
public:
    bool isPossible(vector<vector<int>>& tasks,int mid)
    {
        sort(tasks.begin(),tasks.end(),[](vector<int>&a,vector<int>&b){
            int diff1=a[1]-a[0];
            int diff2=b[1]-b[0];
            return diff1>diff2;
        });
        for(vector<int> val : tasks)
        {
            if(val[1]>mid) return false;
            else
            {
                mid-=val[0];
            }
        }
        return true;
    }
    int minimumEffort(vector<vector<int>>& tasks) {
        int r=0,l=0,ans=0;
        for(vector<int> val : tasks)
        {
            r+=val[1];
        }
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(isPossible(tasks,mid))
            {
                ans=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }    
};