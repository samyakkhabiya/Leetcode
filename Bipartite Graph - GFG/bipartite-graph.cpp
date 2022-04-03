// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:

    bool ans=true;
    vector<int> vis;
	vector<int> clr;
	
    void dfs(int src, vector<int>adj[], int c){
        if(clr[src]!=-1 && clr[src]!=c){
            ans=false;
            return;
        }
        clr[src]=c;
        // vis[src]=c;
        if(vis[src])
            return;
        vis[src]=1;
        for(auto x:adj[src]){
            dfs(x,adj,3-c);
        }
        
    }
	
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    vis.resize(V,0);
	    clr.resize(V,-1);
	    for(int i=0;i<V;i++){
	        if(!vis[i])
	            dfs(i,adj,1);
	    }
	    return ans;
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