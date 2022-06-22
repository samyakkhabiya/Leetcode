// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    vector<int> vis;
    
    bool dfs(int node, vector<int> adj[], int col){
        vis[node]=col;
        for(auto i:adj[node]){
            if(!vis[i]){
                if(dfs(i,adj,3-col))
                    return true;
            }
            else if(vis[i]==col)
                return true;
        }
        return false;
    }
    
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    vis.resize(V,0);
	    for(int i=0;i<V;i++){
	        if(!vis[i]){
	            if(dfs(i,adj,1))
	                return false;
	        }
	    }
	    return true;
	}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}  // } Driver Code Ends