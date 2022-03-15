class Solution {
public:
    
    vector<string> ans;
    unordered_map<string, priority_queue<string, vector<string>, greater<string> > > graph;
    
    void dfs(string s){
        auto & edge=graph[s];
        while(!edge.empty()){
            string temp=edge.top();
            edge.pop();
            dfs(temp);
        }
        ans.push_back(s);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(auto i:tickets){
            graph[i[0]].push(i[1]);
        }
        dfs("JFK");
        reverse(ans.begin(),ans.end());
        return ans;
    }
};