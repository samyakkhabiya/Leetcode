class Solution {
public:
    int recur(vector<int>& nums, int i, int n, int k, int buy, vector<vector<vector<int>>>& dp){
        if (i==n || k==-1) return 0;
        if (dp[buy][k][i]!=-1) return dp[buy][k][i];
        int a, b;
        if (buy==0){             // buy==0 -> we need to to buy stock i.e no stock in hand
            a=recur(nums, i+1, n, k, 1, dp)-nums[i];
            b=recur(nums, i+1, n, k, 0, dp);
            return dp[buy][k][i]=(a>b)?a:b;
        }
        a=recur(nums, i+1, n, k-1, 0, dp)+nums[i];
        b=recur(nums, i+1, n, k, 1, dp);
        return dp[buy][k][i]=(a>b)?a:b;
    }
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        if (k>=n/2){
            int res=0;
            for (int i=1; i<n; ++i){
                if (prices[i]>prices[i-1]) res+=prices[i]-prices[i-1];
            }
            return res;
        }
        vector<vector<vector<int>>> dp(2, vector<vector<int>>(k, vector<int> (n, -1)));
        return recur(prices, 0, n, k-1, 0, dp);
        
        
    }
};