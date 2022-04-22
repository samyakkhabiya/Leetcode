class Solution {
public:
    vector<vector<vector<int>>> dp;
    int solve(vector<int> &p,int idx,bool has_stock,int k)
{
    if(idx>=p.size()||k<=0)
        return 0;
    if(dp[idx][has_stock][k]!=-1)
        return dp[idx][has_stock][k];
    if(has_stock)
    {
        return dp[idx][has_stock][k]=
        max(p[idx]+solve(p,idx+1,0,k-1),solve(p,idx+1,1,k));
    }
    else
    {
        return dp[idx][has_stock][k]=
        max(solve(p,idx+1,1,k)-p[idx],solve(p,idx+1,0,k));
    }
}
    int maxProfit(int k, vector<int>& prices) {
        // memset(dp,-1,sizeof dp);
        int n=prices.size();
        if (k>=n/2){
            int res=0;
            for (int i=1; i<n; ++i){
                if (prices[i]>prices[i-1]) res+=prices[i]-prices[i-1];
            }
            return res;
        }
        dp.resize(n+1, vector<vector<int>>(2, vector<int> (k+1, -1)));
        return solve(prices,0,0,k);
    }
};