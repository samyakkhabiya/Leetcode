class Solution {
public:
    long long dp[13][10001];
    
    long long dfs(vector<int>& coins, int amount, int i){
        long long n=coins.size();
        if(i>=n or amount<0)
            return INT_MAX;
        if(amount==0)
            return 0;
        if(dp[i][amount]!=-1)
            return dp[i][amount];
        if(amount-coins[i]>=0){
            return dp[i][amount]=min(1+dfs(coins,amount-coins[i],i),dfs(coins,amount,i+1));
        }
        else
            return dp[i][amount]=dfs(coins,amount,i+1);
    }
    
    int coinChange(vector<int>& coins, int amount) {
        memset(dp,-1,sizeof(dp));
        long long ans=dfs(coins,amount,0);
        return ans>=INT_MAX?-1:(int)ans;
    }
};