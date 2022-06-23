class Solution {
public:
    
    int maxrect(vector<vector<char>>& grid, int x, int y){
        int ma=INT_MAX,i=x,j=y;
        int ans=-1;
        int m=grid.size();
        int n=grid[0].size();
        while(i<m and grid[i][y]=='1'){
            j=y;
            while(j<n and grid[i][j]=='1'){
                j++;
            }
            ma=min(ma,j-y);
            ans=max(ans,ma*(i-x+1));
            i++;
        }
        return ans;
    }
    
    
    int dfs(vector<vector<char>>& grid, int i, int j, vector<vector<int>>& dp){
        int m=grid.size();
        int n=grid[0].size();
        if(i<0 or j<0 or i>=m or j>=n)
            return 0;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int ans=maxrect(grid,i,j);
        if(ans == (m-i)*(n-j))
            return ans;
        return dp[i][j]=max({ans, dfs(grid,i+1,j,dp), dfs(grid,i,j+1,dp) });
            
    }
    
    int maximalRectangle(vector<vector<char>>& m) {
        int rows = m.size(), cols = m[0].size();
        vector<vector<int>> dp(rows+1,vector<int>(cols+1,-1));        
        return dfs(m,0,0,dp);
    }
};