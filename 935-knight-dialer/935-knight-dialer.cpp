class Solution {
const long long M = 1e9+7;
vector<vector<vector<long>>> m_memo;
public:
long long dfs(int n, int i, int j)
{
if(i < 0 or i >=4 or j < 0 or j>=3 or(i==3 and j!=1))
return 0;
if(n == 1)
return 1;
if(m_memo[i][j][n] != -1)
return m_memo[i][j][n];
long long ans = 0;
int dx[]={-1,1,2,2,1,-1,-2,-2};
int dy[]={-2,-2,-1,1,2,2,1,-1};
for(int k = 0; k < 8; k++)
{
ans = (ans%M + dfs(n-1, i+dx[k], j + dy[k])%M)%M;
}
return m_memo[i][j][n] = ans;

}
int knightDialer(int n1) {
    m_memo.resize(4, vector<vector<long>>(3, vector<long>(n1+1,-1)));
    long long ans = 0;
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            ans = (ans%M + dfs(n1,i,j)%M)%M; 
        }
    }
    return ans;
}
};