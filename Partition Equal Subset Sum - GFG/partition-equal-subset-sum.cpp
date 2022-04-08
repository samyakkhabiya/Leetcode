// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int hs;
    vector<vector<int>> dp;
    
    bool dfs(int arr[], int i, int n, int sum){
        if(i>=n)
            return false;
        
        if(hs<sum)
            return false;
        
        if(hs==sum)
            return true;
            
        if(dp[i][sum]!=-1)
            return dp[i][sum];
            
        // if(sum+arr[i]<=hs)
            return dp[i][sum]=dfs(arr,i+1,n,sum+arr[i]) || dfs(arr,i+1,n,sum);
    //     else
    //         return dp[i][sum]=dfs(arr,i+1,n,sum);
    }
    
    int equalPartition(int N, int arr[])
    {
        // code here
        int sum=0;
        for(int i=0;i<N;i++)
            sum+=arr[i];
        if(sum%2!=0)
            return 0;
        hs=sum/2;
        dp.resize(N+1,vector<int>(sum,-1));
        return dfs(arr,0,N,0);
            
        
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}  // } Driver Code Ends