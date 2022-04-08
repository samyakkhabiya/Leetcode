// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
  
    int dfs(string &word1, string &word2, int i, int j, vector<vector<int>> &dp){
        if(i==word1.size() && j==word2.size())
            return 0;
        if(word1.size()==i)
            return word2.size()-j;
        if(word2.size()==j)
            return word1.size()-i;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
            
        if(word1[i]==word2[j]){
            return dp[i][j]=dfs(word1,word2,i+1,j+1,dp);
        }
        else{
            int a=dfs(word1,word2,i+1,j,dp)+1;
            int b=dfs(word1,word2,i,j+1,dp)+1;
            int c=dfs(word1,word2,i+1,j+1,dp)+1;
            return dp[i][j]=min({a,b,c});
        }
        
    }
    
    int editDistance(string word1, string word2) {
        // Code here
        vector<vector<int>> dp(word1.size()+1,vector<int>(word2.size()+1,-1));
        return dfs(word1,word2,0,0,dp);
        
    }
};

// { Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends