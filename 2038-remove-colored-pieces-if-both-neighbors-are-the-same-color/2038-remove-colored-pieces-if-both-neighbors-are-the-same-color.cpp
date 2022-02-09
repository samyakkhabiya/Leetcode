class Solution {
public:
    bool winnerOfGame(string s) {
        int sum[2] = {};
        for (int i = 0, N = s.size(); i < N;) {
            int c = s[i], cnt = 0;
            while (i < N && c == s[i]) ++i, ++cnt;
            sum[c - 'A'] += max(0, cnt - 2);
        }
        return sum[0] > sum[1];
    }
};