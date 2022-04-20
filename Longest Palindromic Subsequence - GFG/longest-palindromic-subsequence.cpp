// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    int dp[1001][1001];
    
    int dfs(string s, int i, int j){
        if(i>j)
            return 0;
        if(i==j)
            return 1;
            
        if(dp[i][j]!=-1)
            return dp[i][j];
            
        if(s[i]==s[j])
            return dp[i][j]=dfs(s,i+1,j-1)+2;
        else
            return dp[i][j]=max(dfs(s,i+1,j),dfs(s,i,j-1));
        
        
    }
    
    int longestPalinSubseq(string A) {
        //code here
        memset(dp,-1,sizeof(dp));
        return dfs(A,0,A.size()-1);
    }
};

// { Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends