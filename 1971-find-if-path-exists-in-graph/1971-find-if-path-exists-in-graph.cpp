class Solution {
public:
    vector<vector<int>> graph;
    vector<int> vis;
    
    bool dfs(int src, int dest){
        vis[src]=1;
        if(src==dest)
            return true;
        for(auto i: graph[src]){
            if(!vis[i] && dfs(i,dest))
                return true;
        }
        return false;
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        graph.resize(n);
        vis.resize(n,0);
        for(auto i:edges){
            graph[i[0]].push_back(i[1]);
            graph[i[1]].push_back(i[0]);
        }
        
        return dfs(source,destination);
        
    }
};