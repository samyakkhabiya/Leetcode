class Solution {
public:
    vector<bool> camelMatch(vector<string>& qs, string pattern, vector<bool> res = {}) {
  for (auto i = 0; i < qs.size(); ++i) {
    for (auto p = -1, j = 0; j < pattern.size(); ++j) {
      p = qs[i].find(pattern[j], p + 1);
      if (p == string::npos) {
        res.push_back(false);
        break;
      }
      qs[i][p] = 'a';
    }
    if (res.size() <= i) res.push_back(all_of(begin(qs[i]), end(qs[i]), [](char ch) { return islower(ch); }));
  }
  return res;
}
};