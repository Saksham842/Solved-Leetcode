class Solution {
public:
int t[13][10001];
    int solve(vector<int>& coins, int amount , int i){
        if(i==coins.size()) return INT_MAX/2;
        if(amount<0) return INT_MAX/2;
        if(amount==0) return 0;
        if(t[i][amount]!=-1) return t[i][amount];

        int take=1+solve(coins,amount-coins[i],i+1);
        int atake=1+solve(coins,amount-coins[i],i);
        int skip=solve(coins,amount,i+1);

        return t[i][amount]=min({take,atake,skip});

    }
    int coinChange(vector<int>& coins, int amount) {
        memset(t,-1,sizeof(t));
        sort(coins.begin(),coins.end(),greater<int>());
        int ans=solve(coins,amount,0);
        return ans>=INT_MAX/2?-1:ans; 
    }
};