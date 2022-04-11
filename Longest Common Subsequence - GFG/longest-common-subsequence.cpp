// { Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

 // } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    int dp[1001][1001];
    
    int solve(string &s1, string &s2, int i, int j){
        if(i<0 || j<0 || i>=s1.size() || j>=s2.size())
            return 0;
            
        // if(i==s1)
        if(dp[i][j]!=-1)
            return dp[i][j];
            
        if(s1[i]==s2[j])
            return dp[i][j]=solve(s1,s2,i+1,j+1)+1;
        else{
            int a=solve(s1,s2,i+1,j);
            int b=solve(s1,s2,i,j+1);
            int c=solve(s1,s2,i+1,j+1);
            dp[i][j]=max({a,b,c});
        }
        return dp[i][j];
    }
    
    int lcs(int x, int y, string s1, string s2)
    {
        // your code here
        memset(dp,-1,sizeof(dp));
        return solve(s1,s2,0,0);
    }
};


// { Driver Code Starts.
int main()
{
    int t,n,k,x,y;
    cin>>t;
    while(t--)
    {
        cin>>x>>y;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(x, y, s1, s2) << endl;
    }
    return 0;
}
  // } Driver Code Ends