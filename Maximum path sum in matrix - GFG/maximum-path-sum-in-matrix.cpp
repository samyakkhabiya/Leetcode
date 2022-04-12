// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
    int dpmem(int i, int j, int n, vector<vector<int>>& mat, vector<vector<int>>& dp){
        if(i<0 || j<0 || i>=n || j>=n)
            return 0;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
            
        int a=dpmem(i+1,j,n,mat,dp)+mat[i][j];
        int b=dpmem(i+1,j-1,n,mat,dp)+mat[i][j];
        int c=dpmem(i+1,j+1,n,mat,dp)+mat[i][j];
        dp[i][j]=max(a,max(b,c));
        return dp[i][j];
        
    }
    
    int maximumPath(int n, vector<vector<int>> Matrix)
    {
        // code here
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int a=dpmem(i,j,n,Matrix,dp);
                ans=max(a,ans);
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