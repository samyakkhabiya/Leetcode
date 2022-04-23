class Solution {
public:
    int dp[301][301];
    
    int dfs(vector<vector<char>>& matrix, int i, int j){
        if(i<0 || j<0 || i>=matrix.size() || j>=matrix[0].size() || matrix[i][j]=='0')
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        return dp[i][j]=1+min({dfs(matrix,i+1,j),dfs(matrix,i,j+1),dfs(matrix,i+1,j+1)});
    }
    
    int maximalSquare(vector<vector<char>>& matrix) {
        memset(dp,-1,sizeof(dp));
        int ans=0;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]=='1'){
                    ans=max(ans,dfs(matrix,i,j));
                }
            }
        }
        return ans*ans;
    }
};