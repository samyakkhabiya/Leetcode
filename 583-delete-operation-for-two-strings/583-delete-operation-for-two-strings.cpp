class Solution {
public:
    
    int dpmem(string& w1, string& w2,int i,int j,vector<vector<int>>& dp){
        if(w1.size()==i && w2.size()==j)
            return 0;
        
        if(w1.size()==i)
            return w2.size()-j;
        if(w2.size()==j)
            return w1.size()-i;
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        if(w1[i]==w2[j])
            return dp[i][j]=dpmem(w1,w2,i+1,j+1,dp);
        else{
            int a=1+dpmem(w1,w2,i+1,j,dp);
            int b=1+dpmem(w1,w2,i,j+1,dp);
            // int del=1+dpmem(w1,w2,i+1,j+1,dp);
            dp[i][j]=min(a,b);
        }
        return dp[i][j];
    }
    
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size()+1,vector<int>(word2.size(),-1));
        return dpmem(word1,word2,0,0,dp);
    }
};