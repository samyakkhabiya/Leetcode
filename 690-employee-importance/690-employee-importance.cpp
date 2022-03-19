/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    unordered_map<int,int> ump;
    vector<vector<int>> graph;
    int ans=0;
    vector<bool> vis;
    
    void dfs(int src){
        ans+=ump[src];
        vis[src]=true;
        for(auto i:graph[src]){
            if(!vis[i])
                dfs(i);
        }
    }
    
    int getImportance(vector<Employee*> emp, int id) {
        ump.clear();
        graph.resize(2002);
        vis.resize(2002,false);
        for(auto i:emp){
            ump[i->id]=i->importance;
        }
        for(auto i:emp){
            for(auto j:i->subordinates){
                graph[i->id].push_back(j);
            }
        }
        dfs(id);
        return ans;
    }
};