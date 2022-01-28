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
    
    int dpmem(string& text1, string& text2, int m, int n){
        if(m<0 || n<0)
            return 0;
        if(dp[m][n]!=-1)
            return dp[m][n];
        
        int sum=0;
        if(text1[m]==text2[n]){
            return dp[m][n]=dpmem(text1,text2,m-1,n-1)+1;
        }
        else{
            int a=dpmem(text1,text2,m-1,n);
            int b=dpmem(text1,text2,m,n-1);
            int c=dpmem(text1,text2,m-1,n-1);
            sum=max(a,max(b,c));
        }
        dp[m][n]=sum;
        return dp[m][n];
    }
    
    int lcs(int x, int y, string s1, string s2)
    {
        // your code here
        memset(dp,-1,sizeof(dp));
        return dpmem(s1,s2,x-1,y-1);
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