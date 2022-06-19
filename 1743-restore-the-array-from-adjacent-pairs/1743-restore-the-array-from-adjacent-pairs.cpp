class Solution {
public:
    vector<int> ans;
    unordered_map<int,bool> vis;
    unordered_map<int,vector<int>> grid;
    
    void dfs(int node){
        vis[node]=true;
        ans.push_back(node);
        for(auto i:grid[node]){
            if(!vis[i]){
                dfs(i);
            }
        }
    }
    
    vector<int> restoreArray(vector<vector<int>>& adj) {
        ans.clear();
        vis.clear();
        grid.clear();
        for(auto i:adj){
            grid[i[0]].push_back(i[1]);
            grid[i[1]].push_back(i[0]);
        }
        int start=0;
        for(auto i:grid){
            if(i.second.size()==1){
                start=i.first;
                break;
            }
        }
        
        dfs(start);
        return ans;
                
    }
};