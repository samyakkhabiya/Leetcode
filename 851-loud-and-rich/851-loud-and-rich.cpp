class Solution {
public:
    int dfs(int node,vector<vector<int> > &graph,vector<int> quiet,vector<int> &ans)
    {
        if(ans[node]!=-1)
        return ans[node];
        else
        {
        //storing the node's value as ans for the time being
        ans[node]=node;
        for(auto child:graph[node])
        {
            //finding the minimum quitenss for the child connected to the node and storing the ans for the child to the ans for the node(if quitesness of node is not lesser than that)
            if(quiet[dfs(child,graph,quiet,ans)]<quiet[ans[node]])
            {
                ans[node]=ans[child];
            }
        }
        }
        return ans[node];
    }
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        //constructing the graph
        int n=quiet.size();
        vector<vector<int>> graph(n);
        for(int i=0;i<richer.size();i++)
        {
            graph[richer[i][1]].push_back(richer[i][0]);
        }
        vector<int> ans(n,-1);
        for(int i=0;i<n;i++)
        {
            //calling dfs func. for each of the nodes
            dfs(i,graph,quiet,ans);
        }
        return ans;
    }
};