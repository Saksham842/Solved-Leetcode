class Solution {
public:
    int t[100001][2][3];
    int solve(vector<int>& prices, int buy , int i, int cnt){
        if(i==prices.size() || cnt==0) return 0;
        if(t[i][buy][cnt]!=-1) return t[i][buy][cnt];
        int profit=INT_MIN;
        if(buy){
            int take = -prices[i] + solve(prices,0,i+1,cnt);
            int skip=solve(prices,1,i+1,cnt);
            profit=max(take,skip);
        }
        else{
            int sell=prices[i]+solve(prices,1,i+1,cnt-1);
            int skip=solve(prices,0,i+1,cnt);
            profit=max(sell,skip);
        }
        return t[i][buy][cnt]=profit;
    }
    int maxProfit(vector<int>& prices) {
        memset(t,-1,sizeof(t));
        return solve(prices,1,0,2);
        
    }
};