class Solution {
public:
    
    vector<int> dp;
    
    int dfs(vector<int> adj[], int idx, vector<int> &time){
        if(dp[idx]!=-1)
            return dp[idx];
        int res=0;
        for(auto i:adj[idx]){
            res=max(res,dfs(adj,i,time));
        }
        return dp[idx]=res+time[idx];
    }
    
    int minimumTime(int n, vector<vector<int>>& rel, vector<int>& time) {
        vector<int> adj[n];
        dp.resize(n,-1);
        for(int i=0;i<rel.size();i++){
            int u=rel[i][0]-1,v=rel[i][1]-1;
            adj[u].push_back(v);
        }
        for(int i=0;i<n;i++){
            dfs(adj,i,time);
        }
        int ans= *max_element(dp.begin(),dp.end());
        return ans;
        
    }
};