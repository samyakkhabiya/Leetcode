class Solution {
public:
    int m,n;
    vector<vector<int>> dp;
    int solve(vector<vector<int>>& ob, int i, int j){
        if(i<0 || i>=m || j<0 || j>=n || ob[i][j]==1)
            return 0;
        if(i==m-1 && j==n-1)
            return 1;
        if(dp[i][j]!=-1)
            return dp[i][j];
        return dp[i][j]=solve(ob,i+1,j)+solve(ob,i,j+1);
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& ob) {
        m=ob.size();
        n=ob[0].size();
        dp.resize(m+1,vector<int>(n+1,-1));
        return solve(ob,0,0);
    }
};