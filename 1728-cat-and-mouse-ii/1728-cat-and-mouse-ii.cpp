class Solution {
public:
    int dp[36][64][64] = {};
int dirs[5] = {0, 1, 0, -1, 0};
vector<int> getJumps(vector<string>& g, int p, int f, int max) {
    vector<int> res{p};
    for (auto d = 0; d < 4; ++d)
        for (int jump = 1; jump <= max; ++jump) {
            auto i = p / 8 + dirs[d] * jump, j = p % 8 + dirs[d + 1] * jump;
            if (i < 0 || j < 0 || i >= g.size() || j >= g[i].size() || g[i][j] == '#')
                break;
            res.push_back(i * 8 + j);
        }
    sort(begin(res), end(res), [f](int a, int b) { return abs(f / 8 - a / 8) + abs(f % 8 - a % 8) <
            abs(f / 8 - b / 8) + abs(f % 8 - b % 8); });
    return res;
}
bool dfs(vector<string>& g, int turn, int c, int m, int f, int catJump, int mouseJump) {
    if (turn >= 0 && (m == f || dp[turn][m][c] == 1))
        return true;
    if (turn < 0 || c == m || c == f || dp[turn][m][c] == -1)
        return false;
    auto catJumps = getJumps(g, c, f, catJump);
    for (auto new_m : getJumps(g, m, f, mouseJump)) {
        bool mouseWon = true;
        for (auto n = 0; mouseWon && n < catJumps.size(); ++n)
            mouseWon &= dfs(g, turn - 1, catJumps[n], new_m, f, catJump, mouseJump);
        if (mouseWon)
            return dp[turn][m][c] = 1;
    }
    dp[turn][m][c] = -1;
    return false;
}
bool canMouseWin(vector<string>& g, int catJump, int mouseJump) {
    int c = 0, m = 0, f = 0, rows = g.size(), cols = g[0].size();
    int turns = rows * ((cols + 1) / 2) + cols / 2 - 1;        
    for (auto i = 0; i < rows; ++i)
        for (auto j = 0; j < cols; ++j) {
            m = g[i][j] == 'M' ? i * 8 + j : m;
            c = g[i][j] == 'C' ? i * 8 + j : c;
            f = g[i][j] == 'F' ? i * 8 + j : f;
        }
    return dfs(g, turns, c, m, f, catJump, mouseJump);
}

};