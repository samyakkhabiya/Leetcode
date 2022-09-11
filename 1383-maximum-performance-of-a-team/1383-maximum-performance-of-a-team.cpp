class Solution {
public:
    
    int mod=1e9+7;
    
    int maxPerformance(int n, vector<int>& speed, vector<int>& eff, int k){
        vector<pair<int,int>> vc(n);
        for(int i=0;i<n;i++){
            vc[i]={eff[i],speed[i]};
        }
        
        sort(vc.begin(),vc.end(),greater<pair<int,int>>());
        priority_queue<int,vector<int>,greater<int>> pq;
        
        long long ans=0,sum=0;
        for(int i=0;i<n;i++){
            sum+=vc[i].second;
            pq.push(vc[i].second);
            while(pq.size()>k){
                sum-=pq.top();
                pq.pop();
            }
            ans=max(ans,sum*vc[i].first);
        }
        return ans%mod;
    }
};