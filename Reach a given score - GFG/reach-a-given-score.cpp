// { Driver Code Starts
// Driver Code
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

 // } Driver Code Ends
// Complete this function

int arr[3]={3,5,10};
vector<vector<ll>> dp;

ll dfs(ll n, ll x){
    if(n<0)
        return 0;
    if(n==0)
        return 1;
    if(dp[n][x]!=-1)
        return dp[n][x];
    
    ll ans=0;
    for(int i=x;i<3;i++)
        ans+=dfs(n-arr[i],i);
     
       
    return dp[n][x]=ans;
}


long long int count(long long int n)
{
     dp.resize(n+1,vector<ll>(3,-1));
	 return dfs(n,0);
}

// { Driver Code Starts.



int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		cout<<count(n)<<endl;
	}
	return 0;
}  // } Driver Code Ends