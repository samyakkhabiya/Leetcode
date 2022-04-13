// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
#include <bits/stdc++.h>
using namespace std;
//Position this line where user code will be pasted.

class Solution{
	public:
	
	vector<vector<int>> dp;
	
	int dfs(int cost[], int n, int w){
	    if(w==0)
	        return 0;
	       
	   if(n<0 || w<0)
	        return 100000;
	        
	       if(dp[n][w]!=-1)
	            return dp[n][w];
	        
	   if(w-n+1>=0 && cost[n]!=-1){
	       int a=dfs(cost,n,w-n-1)+cost[n];
	       int b=dfs(cost,n-1,w-n-1)+cost[n];
	       int c=dfs(cost,n-1,w);
	       dp[n][w]=min({a,b,c});
	   }
	   else
	        dp[n][w]=dfs(cost,n-1,w);
	       
	   return dp[n][w];
	}
	
	int minimumCost(int cost[], int N, int W) 
	{ 
        // Your code goes here
        dp.resize(N+1,vector<int>(W+1,-1));
        int ans=dfs(cost,N-1,W);
        return ans==100000?-1:ans;
	} 
};


// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, w;
        cin >> n >> w;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minimumCost(a, n, w) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends