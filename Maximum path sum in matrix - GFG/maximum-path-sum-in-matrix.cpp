// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
    vector<vector<int>> dp;
    
    int dfs(vector<vector<int>>& mat, int i, int j){
        int m=mat.size();
        int n=mat[0].size();
        if(i<0 || j<0 || i>=m || j>=n)
            return 0;
       
        
        if(dp[i][j]!=-1)
            return dp[i][j];
            
        int a=dfs(mat,i+1,j)+mat[i][j];
        int b=dfs(mat,i+1,j-1)+mat[i][j];
        int c=dfs(mat,i+1,j+1)+mat[i][j];
        return dp[i][j]=max({a,b,c});
    }
    
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        // code here
        int m=Matrix.size();
        int n=Matrix[0].size();
        dp.resize(m+1,vector<int>(n+1,-1));
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++)
                ans=max(ans,dfs(Matrix,i,j));
        }
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}  // } Driver Code Ends