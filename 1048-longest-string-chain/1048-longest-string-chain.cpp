class Solution {
public:
    unordered_set<string> s;
bool isChain(string &prev, string &cur) {
  for (auto i = 0, j = 0; i < prev.size(); ++j) {
    if (prev[i] == ' ' || prev[i] == cur[j]) ++i;
    if (j - i == 2) return false;
  }
  return true;
}
int dfs(vector<vector<string>> &w, string pr) {
  int res = pr.size();
  if (res == w.size()) return res;
  if (!s.insert(pr).second) return 0;
  for (auto word : w[pr.size()]) {
    if (isChain(pr, word)) res = max(res, dfs(w, word));
  }
  return res;
}
int longestStrChain(vector<string>& words, int res = 1) {
  vector<vector<string>> w(16, vector<string>());
  for (auto word : words) w[word.size() - 1].push_back(word);
  for (auto i = 0; i < 16; ++i) res = max(res, dfs(w, string(i, ' ')) - i);
  return res;
}
};