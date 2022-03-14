class Solution {
public:
    int dp[201][201];
    bool ch(vector<vector<int>>& matrix, int i, int j){
        int m=matrix.size();
        int n=matrix[0].size();
        if(i<0 || j<0 || i>=m || j>=n)
            return true;
        return false;
    }
    
    int dfs(vector<vector<int>>& matrix, int i, int j, int last){
        int m=matrix.size();
        int n=matrix[0].size();
        if(ch(matrix,i,j))
            return 0;
        
        int curr=matrix[i][j];
        int a=0,b=0,c=0,d=0;
        if(last<matrix[i][j]){
            if(dp[i][j]!=0)
                return dp[i][j];
            a=dfs(matrix,i+1,j,matrix[i][j])+1;
            b=dfs(matrix,i-1,j,matrix[i][j])+1;
            c=dfs(matrix,i,j+1,matrix[i][j])+1;
            d=dfs(matrix,i,j-1,matrix[i][j])+1;
            
        }
        return dp[i][j]=max({a,b,c,d});
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        memset(dp,0,sizeof(dp));
        int maxx=INT_MIN;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                maxx=max(maxx,dfs(matrix,i,j,INT_MIN));
            }
        }
        return maxx;
    }
};