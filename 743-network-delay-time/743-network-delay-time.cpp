typedef pair<int, int> pii;
class Solution {
public:
    
    
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pii> graph[n+1];
        for(auto i:times){
            graph[i[0]].push_back({i[1],i[2]});
        }
        vector<int> dist(n+1,INT_MAX);
        priority_queue<pii ,vector<pii>, greater<pii> > pq;
        pq.push({0,k});
        dist[k]=0;
        dist[0]=0;
        while(!pq.empty()){
            auto z=pq.top();
            pq.pop();
            int u=z.second;
            for(auto i:graph[u]){
                int v=i.first;
                int p=i.second;
                if(dist[u]+p<dist[v]){
                    dist[v]=dist[u]+p;
                    pq.push({dist[v],v});
                }
            }
        }
        int ans= *max_element(dist.begin(),dist.end());
        return ans==INT_MAX?-1:ans;
    }
};