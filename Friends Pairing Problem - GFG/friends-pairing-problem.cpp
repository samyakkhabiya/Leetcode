// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:

    long long int mod=1e9 + 7;
    vector<int> dp;
    long long int solve(int n){
        
        if(n<=2)
            return n;
    if(dp[n]!=-1)
        return dp[n];
        return dp[n]=((solve(n-1)%mod)+((solve(n-2)%mod)*(n-1)%mod))%mod;
        
        
    }
    
    int countFriendsPairings(int n) 
    { 
        // code here
        dp.resize(n+1,-1);
        return solve(n)%mod;
    }
};    
 

// { Driver Code Starts.
int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	Solution ob;
    	cout <<ob.countFriendsPairings(n); 
    	cout<<endl;
    }
} 
  // } Driver Code Ends