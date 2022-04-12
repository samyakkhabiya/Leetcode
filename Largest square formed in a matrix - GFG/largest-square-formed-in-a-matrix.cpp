// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:

    vector<vector<int>> dp;
    
    int dfs(vector<vector<int>> mat, int i, int j){
        int m=mat.size();
        int n=mat[0].size();
        if(i>=m || j>=n || mat[i][j]==0)
            return 0;
            
        if(dp[i][j]!=-1)
            return dp[i][j];
            
        int a=dfs(mat,i+1,j)+1;
        int b=dfs(mat,i,j+1)+1;
        int c=dfs(mat,i+1,j+1)+1;
        return dp[i][j]=min({a,b,c});
    }
    
    int maxSquare(int m, int n, vector<vector<int>> mat){
        // code here
        dp.resize(m+1,vector<int>(n+1,-1));
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==1){
                    ans=max(ans,dfs(mat,i,j));
                }
            }
        }
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for(int i = 0;i < n*m;i++)
            cin>>mat[i/m][i%m];
        
        Solution ob;
        cout<<ob.maxSquare(n, m, mat)<<"\n";
    }
    return 0;
}  // } Driver Code Ends