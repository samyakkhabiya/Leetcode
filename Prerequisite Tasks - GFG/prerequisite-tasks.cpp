// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    vector<bool> vis;
    vector<bool> rec;
    
    bool dfs(int node, vector<int> grid[]){
        vis[node]=1;
        rec[node]=1;
        for(auto i:grid[node]){
            if(!vis[i]){
                if(dfs(i,grid))
                    return true;
            }
            else if(rec[i])
                return true;
        }
        rec[node]=0;
        return false;
    }
    
	bool isPossible(int N, vector<pair<int, int> >& pre) {
	    // Code here
	    vis.resize(N,0);
	    rec.resize(N,0);
	    vector<int> grid[N];
	    for(auto i:pre){
	        grid[i.second].push_back(i.first);
	    }
	    for(int i=0;i<N;i++){
	        if(!vis[i])
	            if(dfs(i,grid))
	                return false;
	    }
	    return true;
	    
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}  // } Driver Code Ends