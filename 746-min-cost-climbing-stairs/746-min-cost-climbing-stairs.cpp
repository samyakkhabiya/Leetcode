class Solution {
public:
    int dp[1001];
    
    int dfs(vector<int>& cost, int idx){
        int n=cost.size();
        if(idx>=n)
            return 0;
        if(dp[idx]!=-1)
            return dp[idx];
        return dp[idx] = min(cost[idx]+dfs(cost,idx+1),cost[idx]+dfs(cost,idx+2));
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
       memset(dp,-1,sizeof(dp));
        return min(dfs(cost,0),dfs(cost,1));
    }
};