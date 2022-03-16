class Solution {

typedef long long int lli;
long long mod = (1e9 + 7);
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        priority_queue<pair<lli,lli>,vector<pair<lli,lli>>,greater<pair<lli,lli>>> pq;
        vector<lli> dist(n,LONG_MAX),ways(n,0);
        //pair dist, node;
        dist[0]=0;
        ways[0]=1;
        pq.push({0,0});
        vector<vector<pair<lli,lli>>> adj(n);
        for(auto &e :roads){
            adj[e[0]].push_back({e[1],e[2]});
            adj[e[1]].push_back({e[0],e[2]});
        }
        while(!pq.empty()){
            lli u = pq.top().second;
            lli distu = pq.top().first;
            pq.pop();
            for(auto &x : adj[u]){
                lli v = x.first;
                lli w = x.second;
                if(dist[v]>(distu+w)){
                    dist[v]=distu+w;
                    ways[v]=ways[u];
                    pq.push({dist[v],v});
                }
                else if(dist[v]==(distu+w)){
                    ways[v]=(ways[v]+ways[u])%mod;
                }
            }
        }
        
        return ways[n-1];
    }
};