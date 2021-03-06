// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    vector<string> ans;
    
    void dfs(vector<vector<int>> &graph, string s, int i, int j, int n){
        if(i<0 || j<0 || i>=n  || j>=n || graph[i][j]==0)
            return;
        if(i==n-1 && j==n-1)
            ans.push_back(s);
            
        graph[i][j]=0;
        dfs(graph,s+"D",i+1,j,n);
        dfs(graph,s+"U",i-1,j,n);
        dfs(graph,s+"R",i,j+1,n);
        dfs(graph,s+"L",i,j-1,n);
        graph[i][j]=1;
        
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        if(m[0][0]==0 || m[n-1][n-1]==0)
            return {};
        ans.clear();
        dfs(m,"",0,0,n);
        return ans;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends