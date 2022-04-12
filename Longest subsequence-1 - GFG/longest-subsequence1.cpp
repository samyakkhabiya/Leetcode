// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> dp;
    
    int solve(int a[], int idx, int n){
        if(idx>=n)
            return 0;
            
        if(dp[idx]!=-1)
            return dp[idx];
            
        int ans=1;
        for(int i=idx+1;i<n;i++){
            if(abs(a[idx]-a[i])==1){
                ans=max(ans,solve(a,i,n)+1);
            }
        }
        return dp[idx]=ans;
    }
    
    int longestSubsequence(int N, int A[])
    {
        // code here
    
        dp.resize(N+1,-1);
        
        int ans=0;
        for(int i=0;i<N;i++){
            ans=max(ans,solve(A,i,N));
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
        int A[N];
        for(int i = 0;i < N;i++)
            cin>>A[i];
        
        Solution ob;
        cout<<ob.longestSubsequence(N, A)<<endl;
    }
    return 0;
}  // } Driver Code Ends