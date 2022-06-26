// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function template for C++
class Solution{
   public:
   int dp[1001][1001];
   int f(int i, int j, string &wild, string &pattern){
       if(i<0 and j<0) return true;
       if(i<0 and j>=0) return false;
       if(j<0 and i>=0){
           for(int ii=0;ii<=i;ii++){
               if(wild[ii]!='*') return false;
           }
           return true;
       }
       
       if(dp[i][j]!=-1)
        return dp[i][j];
       
       if(wild[i] == pattern[j] or wild[i]=='?'){
           return dp[i][j]=f(i-1,j-1,wild,pattern);
       }
       if(wild[i]=='*'){
           return dp[i][j]=f(i-1,j,wild,pattern) | f(i,j-1,wild,pattern);
       }
       return dp[i][j]=false;
   }
   
   bool match(string wild, string pattern)
   {
      int n = wild.size();
      int m = pattern.size();
      memset(dp,-1,sizeof(dp));
      return f(n-1,m-1,wild,pattern);
       
   }
};


// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string wild, pattern;
        cin>>wild>>pattern;
        
        Solution ob;
        if(ob.match(wild, pattern))
        cout<<"Yes\n";
        else
        cout<<"No\n";
    }
    return 0;
}  // } Driver Code Ends