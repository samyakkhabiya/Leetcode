// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends

#define ll long long
class Solution
{
    public:
    //Function to find the maximum number of cuts.
    vector<ll> dp;
    int mod=1e9+7;
    ll solve(int n, int x, int y, int z){
        if(n==0)
            return 0;
        if(n<0)
            return INT_MIN;
        if(dp[n]!=-1)
            return dp[n];
            
        return dp[n]=max({(solve(n-x,x,y,z)%mod+1)%mod,(solve(n-y,x,y,z)%mod+1)%mod,(solve(n-z,x,y,z)%mod+1)%mod})%mod;
        
    }
    
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        //Your code here
        dp.resize(n+1,-1);
        int ans=solve(n,x,y,z)%mod;
        return ans<0?0:ans;
    }
};

// { Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}  // } Driver Code Ends