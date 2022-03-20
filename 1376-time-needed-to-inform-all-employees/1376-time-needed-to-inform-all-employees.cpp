class Solution {
public:
    vector<vector<int>> graph;
    
    int dfs(int src, vector<int>& info){
        int time=0;
        for(auto i:graph[src])
            time=max(time,dfs(i,info));
        return info[src]+time;
    }
    
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        
        graph.resize(n);
        for(int i=0;i<manager.size();i++){
            if(manager[i]!=-1)
                graph[manager[i]].push_back(i);
        }
        
        return dfs(headID,informTime);
    }
};