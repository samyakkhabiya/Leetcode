class Solution {
public:
    vector<bool> vis;
    vector<bool> rec;
    
    bool iscycle(int src, vector<vector<int>>& graph){
        if(vis[src]==0){
            vis[src]=1;
            rec[src]=1;
            for(auto i:graph[src]){
                if(!vis[i] && iscycle(i,graph))
                    return true;
                else if(rec[i])
                    return true;
            }
        }
        rec[src]=0;
        return false;
    }
    bool canFinish(int num, vector<vector<int>>& pre) {
        vis.resize(num,false);
        rec.resize(num,false);
        vector<vector<int>> graph(num);
        for(int i=0;i<pre.size();i++){
            graph[pre[i][1]].push_back(pre[i][0]);
        }
        for(int i=0;i<num;i++){
            if(!vis[i] && iscycle(i,graph))
                return false;
        }
        return true;
    }
};