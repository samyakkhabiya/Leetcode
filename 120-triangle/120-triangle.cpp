class Solution {
public:
    int dp[300][300];
    
    int dfs(vector<vector<int>>& tri, int h, int j){
        if(h>=tri.size())
            return 0;
        if(dp[h][j]!=-1)
            return dp[h][j];
        return dp[h][j]=tri[h][j]+min(dfs(tri,h+1,j),dfs(tri,h+1,j+1));
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        memset(dp,-1,sizeof(dp));
        return dfs(triangle,0,0);
    }
};