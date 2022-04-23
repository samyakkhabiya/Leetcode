class Solution {
public:
//     MEMO
    int solve(vector<string>& strs, int m, int n,int i,vector<vector< vector<int>>>& memo){
        if(i==strs.size() || m<0 || n<0) return 0;
        if(m==0 && n==0) return 0;
        if(memo[i][m][n]!=-1) return memo[i][m][n];
        int zeros = count(strs[i].begin(),strs[i].end(),'0');
        int ones = strs[i].length()-zeros;
        if(zeros<=m && ones<=n) return memo[i][m][n] = max(solve(strs,m,n,i+1,memo) , solve(strs,m-zeros,n-ones,i+1,memo)+1);
        else return memo[i][m][n] = solve(strs,m,n,i+1,memo);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
vector<vector< vector<int> > > memo(strs.size()+1,vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        return solve(strs,m,n,0,memo);      
    }
};