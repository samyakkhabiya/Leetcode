class Solution {
public:
    unordered_map<string,vector<string>> ump;
    unordered_map<string,bool> vis;
    
    void dfs(vector<string>& s, string src){
        vis[src]=true;
        s.push_back(src);
        for(auto i:ump[src]){
            if(vis.find(i)==vis.end())
                dfs(s,i);
        }
    }
    
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        vector<vector<string>> ans;
        
        
        for(int i=0;i<accounts.size();i++){
            for(int j=1;j<accounts[i].size();j++){
                ump[accounts[i][1]].push_back(accounts[i][j]);
                ump[accounts[i][j]].push_back(accounts[i][1]);
            }
        }
        
        for(int i=0;i<accounts.size();i++){
            for(int j=1;j<accounts[i].size();j++){
                
                if(vis.find(accounts[i][j])==vis.end()){
                    
                    vector<string> s;
                    dfs(s,accounts[i][j]);
                    sort(s.begin(),s.end());
                    s.insert(s.begin(),accounts[i][0]);
                    ans.push_back(s);
                }
                
            }
        }
        
        return ans;
    }
};