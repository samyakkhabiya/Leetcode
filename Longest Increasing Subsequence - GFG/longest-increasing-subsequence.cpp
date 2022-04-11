// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int dp[100001];
    
    int solve(int a[], int i, int n){
        if(i>=n)
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        int res=0;
        for(int j=i+1;j<n;j++){
            if(a[j]>a[i])
                res=max(res,solve(a,j,n)+1);
        }
        return dp[i]=res;
    }
    
    int longestSubsequence(int n, int a[])
    {
       // your code here
       memset(dp,-1,sizeof(dp));
       int ans=0;
       for(int i=0;i<n;i++)
            ans=max(ans,solve(a,i,n)+1);
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}
  // } Driver Code Ends