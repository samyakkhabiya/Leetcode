#define ll long long
class Solution {
public:
    ll dp[367];
    
    ll dfs(vector<int>& days, vector<int>& costs, int i){
        ll n=days.size();
        if(i>=n)
            return 0;
        
        if(dp[i]!=-1)
            return dp[i];
        
        ll a=0,b=0,c=0;
        
        a=costs[0]+dfs(days,costs,i+1);
        ll pos=i;
        while(pos<n && days[pos]-days[i]<7)
            pos++;
        b=costs[1]+dfs(days,costs,pos);
        pos=i;
        while(pos<n && days[pos]-days[i]<30)
            pos++;
        c=costs[2]+dfs(days,costs,pos);
        return dp[i]=min({a,b,c});
        
    }
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
          memset(dp,-1,sizeof(dp));
        return dfs(days,costs,0);
    }
};