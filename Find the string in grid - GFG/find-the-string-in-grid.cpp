// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    
    const int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
   const int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
   bool helper(vector<vector<char>>arr, string s, int n, int m, int i, int j){
       for(int d=0; d<8; d++){
           int x=i+dx[d];
           int y=j+dy[d];
           int idx;
           for(idx=1;idx<s.length();idx++){
               if (x < 0 || y < 0 || x >= n || y >= m || arr[x][y] != s[idx]) break;
               x += dx[d];
               y += dy[d];
           }
           if(idx==s.length()) return true;
       }
       return false;
   }
   
vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
    vector<vector<int>> res;
       int n = grid.size();
       int m = grid[0].size();
       for(int i=0; i<n; i++){
           for(int j=0; j<m; j++){
               if(grid[i][j]==word[0]){
                   if(helper(grid,word,n,m,i,j)) res.push_back({i,j});
               }
           }
       }
       return res;
}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m,'x'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> grid[i][j];
		}
		string word;
		cin >> word;
		Solution obj;
		vector<vector<int>>ans = obj.searchWord(grid, word);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
		if(ans.size() == 0)
		{
		    cout<<"-1\n";
		}
	}
	return 0;
}  // } Driver Code Ends