class Solution {
public:
    int dp[101][101];
    int solve(vector<int>&h ,int k,int n,int i,vector<vector<int>>&cost)
    {
        // base case
        if(i == n && k == 0)
            return 0;
        if(i == n || k == 0)return 1e7;
        int ans = 1e7;
        if(dp[i][k] != -1)
            return dp[i][k];
        
        for(int j = i ; j <= n-k ; j++)
            ans =min(ans, cost[i][j] + solve(h,k-1,n,j+1,cost));
        dp[i][k] = ans;
        return dp[i][k];
    }
    int minDistance(vector<int>& h, int k) {
        int n = h.size();
        // first store the median of houses of with k == 1 storing the mailboxes in between the 
        // houses as the difference won't change 
        
        vector<vector<int>>cost(n , vector<int>(n , 0));
        sort(h.begin() , h.end());
        for(int i=0;i<n;i++)
        {
            for(int j= i+1;j<n;j++)
            {
                int l = i;
                int r = j;
                while(r > l)
                {
                    cost[i][j] += h[r--] - h[l++];
                }
            }
        }
        memset(dp , -1 , sizeof(dp));
        return solve(h,k,n,0,cost);
        
    }
};