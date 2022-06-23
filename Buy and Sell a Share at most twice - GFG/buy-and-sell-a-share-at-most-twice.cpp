// { Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++
int dp[100001][2][3];

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

int maxProfit(vector<int>&price){
    //Write your code here..
    memset(dp,-1,sizeof(dp));
    return dfs(price,0,0,2);
}

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        vector<int> price(n);
        for(int i=0;i<n;i++) cin>>price[i];
        cout<<maxProfit(price)<<endl;
    }

}
  // } Driver Code Ends