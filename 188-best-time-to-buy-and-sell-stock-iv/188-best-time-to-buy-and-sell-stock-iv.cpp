class Solution {
public:
    // int dp[100001][2][101];
    int dp[2][101][1001];
    int solve(vector<int> &p,int idx,bool has_stock,int k)
{
    if(idx>=p.size()||k<=0)
        return 0;
    if(dp[has_stock][k][idx]!=-1)
        return dp[has_stock][k][idx];
    if(has_stock)
    {
        return dp[has_stock][k][idx]=
        max(p[idx]+solve(p,idx+1,0,k-1),solve(p,idx+1,1,k));
    }
    else
    {
        return dp[has_stock][k][idx]=
        max(solve(p,idx+1,1,k)-p[idx],solve(p,idx+1,0,k));
    }
}
    int maxProfit(int k, vector<int>& prices) {
        memset(dp,-1,sizeof dp);
        int n=prices.size();
        if (k>=n/2){
            int res=0;
            for (int i=1; i<n; ++i){
                if (prices[i]>prices[i-1]) res+=prices[i]-prices[i-1];
            }
            return res;
        }
        return solve(prices,0,0,k);
    }
};