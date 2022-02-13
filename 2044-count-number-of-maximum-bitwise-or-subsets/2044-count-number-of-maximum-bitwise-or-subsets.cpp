// OJ: https://leetcode.com/problems/count-number-of-maximum-bitwise-or-subsets/
// Author: github.com/lzl124631x
// Time: O(2^N * N)
// Space: O(1)
class Solution {
public:
    int countMaxOrSubsets(vector<int>& A) {
        int goal = 0, N = A.size(), ans = 0;
        for (int n : A) goal |= n;
        for (int m = 1; m < 1 << N; ++m) {
            int x = 0;
            for (int i = 0; i < N; ++i) {
                if (m >> i & 1) x |= A[i];
            }
            if (x == goal) ++ans;
        }
        return ans;
    }
};