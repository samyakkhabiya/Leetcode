class Solution {
public:
    int dp[38];
    
    int dfs(int n){
        if(n<=2)
            return n==0?0:1;
        if(dp[n]!=-1)
            return dp[n];
        return dp[n]=dfs(n-1)+dfs(n-2)+dfs(n-3);
    }
    
    int tribonacci(int n) {
        memset(dp,-1,sizeof(dp));
        return dfs(n);
    }
};