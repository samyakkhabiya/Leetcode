class Solution {
public:
    
         int m,n;
    vector<vector<int>> dp;
    
    int dfs(vector<vector<int>>& g, int i, int j, int s, int t_s) {
  if (i < 0 || j < 0 || i >= g.size() || j >= g[0].size() || g[i][j] == -1) return 0;
  if (g[i][j] == 2) return s == t_s ? 1 : 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
  g[i][j] = -1;
  int paths = dfs(g, i + 1, j, s + 1, t_s) + dfs(g, i - 1, j, s + 1, t_s) +
    dfs(g, i, j + 1, s + 1, t_s) + dfs(g, i, j - 1, s + 1, t_s);
  g[i][j] = 0;
  return paths;
}
int uniquePathsIII(vector<vector<int>>& g) {
    m=g.size();
        n=g[0].size();
        dp.resize(m+1,vector<int>(n+1,-1));
  auto i1 = 0, j1 = 0, t_steps = 0;
  for (auto i = 0; i < g.size(); ++i)
    for (auto j = 0; j < g[0].size(); ++j) {
      if (g[i][j] == 1) i1 = i, j1 = j;
      if (g[i][j] != -1) ++t_steps;
    }
  return dfs(g, i1, j1, 1, t_steps);
}
    
    
//      int m,n;
//     vector<vector<int>> dp;
//     int solve(vector<vector<int>>& ob, int i, int j, int count, int pat){
//         if(i<0 || i>=m || j<0 || j>=n || ob[i][j]==-1)
//             return 0;
//         if(ob[i][j]==2)
//             return count==pat?1:0;
//         if(dp[i][j]!=-1)
//             return dp[i][j];
//         int a,b,c,d;
//         int temp=ob[i][j];
//         ob[i][j]=-1;
//         a=solve(ob,i+1,j,count+1,pat);
//         b=solve(ob,i,j+1,count+1,pat);
//         c=solve(ob,i-1,j,count+1,pat);
//         d=solve(ob,i,j-1,count+1,pat);
//         ob[i][j]=temp;
//         return dp[i][j]=a+b+c+d;
//     }
    
//     int uniquePathsIII(vector<vector<int>>& ob) {
//         m=ob.size();
//         n=ob[0].size();
//         dp.resize(m+1,vector<int>(n+1,-1));
//         int i1=0,j1=0,pat=0;
//         for(int i=0;i<m;i++){
//             for(int j=0;j<n;j++){
//                 if(ob[i][j]==1){
//                     i1=i;
//                     j1=j;
//                 }
//                 if(ob[i][j]!=1){
//                     pat++;
//                 }
                
//             }
//         }
//         return solve(ob,i1,j1,1,pat);
//     }
};