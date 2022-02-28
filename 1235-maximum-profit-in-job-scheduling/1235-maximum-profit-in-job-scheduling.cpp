struct job{
    int start,end,profit;
};
class Solution {
public:
    vector<int> dp;
    static bool cmp(job a,job b){
        return a.end<b.end;
    }
    
    int solve(vector<job> &vc, int n){
        for(int j=n-1;j>=0;j--){
            if(vc[j].end<=vc[n].start)
                return j;
        }
        return -1;
    }
    
    int dfs(vector<job> &vc, int n){
        if(n==0)
            return dp[n]=vc[n].profit;
        if(dp[n]!=-1)
            return dp[n];
        int l=solve(vc,n);
        int inc=vc[n].profit,exc=0;
        if(l!=-1)
            inc+=dfs(vc,l);
        exc=dfs(vc,n-1);
        return dp[n]=max(inc,exc);
    }
    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<job> vc(profit.size());
        for(int i=0;i<profit.size();i++){
            vc[i].start=startTime[i];
            vc[i].end=endTime[i];
            vc[i].profit=profit[i];
        }
        dp.resize(profit.size()+1,-1);
        sort(vc.begin(),vc.end(),cmp);
        return dfs(vc,profit.size()-1);
        for(auto i:vc)
            cout<<i.start<<" "<<i.end<<" "<<i.profit<<endl;
        return 0;
    }
};