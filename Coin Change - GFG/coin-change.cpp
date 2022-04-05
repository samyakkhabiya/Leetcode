// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
  #define lli long long int
  
    lli ans=0;
    vector<vector<lli>> dp;
    lli dfs(int s[], int sum, int n, int src){
        if(sum==0)
            return dp[src][sum]=1;
        if(src>n-1)
            return 0;
        if(dp[src][sum]!=-1)
            return dp[src][sum];    
            
        if(s[src]<=sum){
            return dp[src][sum]=dfs(s,sum-s[src],n,src)+dfs(s,sum,n,src+1);
        }
        else
            return dp[src][sum]=dfs(s,sum,n,src+1);
    }
    
    long long int count(int S[], int m, int n) {

        // code here.
        dp.resize(m+1,vector<lli>(n+1,-1));
        ans=0;
        // memset(dp,-1,sizeof(dp));
        return dfs(S,n,m,0);
        
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int arr[m];
        for (int i = 0; i < m; i++) cin >> arr[i];
        Solution ob;
        cout << ob.count(arr, m, n) << endl;
    }

    return 0;
}  // } Driver Code Ends