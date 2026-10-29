class Solution {
public:
    int t[30001][2];
    int solve(vector<int>& prices, int buy , int i){
        if(i==prices.size()) return 0;
        if(t[i][buy]!=-1) return t[i][buy];
        int profit=INT_MIN;
        if(buy){
            int take = -prices[i] + solve(prices,0,i+1);
            int skip=solve(prices,1,i+1);
            profit=max(take,skip);
        }
        else{
            int sell=prices[i]+solve(prices,1,i+1);
            int skip=solve(prices,0,i+1);
            profit=max(sell,skip);
        }
        return t[i][buy]=profit;
    }
    int maxProfit(vector<int>& prices) {
        memset(t,-1,sizeof(t));
        return solve(prices,1,0);
        
    }
};