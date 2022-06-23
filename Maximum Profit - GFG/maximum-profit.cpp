// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    
    int dp[501][2][202];

    int dfs(vector<int> &price, int idx, bool stock, int k){
        if(idx>=price.size())
            return 0;
        if(k==0)
            return 0;
        
        if(dp[idx][stock][k]!=-1)
            return dp[idx][stock][k];
            
        if(stock){
            return dp[idx][stock][k]=max( price[idx]+dfs(price,idx+1,0,k-1) , dfs(price,idx+1,stock,k));
        }
        else
            return dp[idx][stock][k]=max( dfs(price,idx+1,1,k)-price[idx] , dfs(price,idx+1,stock,k));
            
    }
    
    int maxProfit(int K, int N, int A[]) {
        // code here
        memset(dp,-1,sizeof(dp));
        vector<int> price(A,A+N);
        
        return dfs(price,0,0,K);
    }
};




// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}  // } Driver Code Ends