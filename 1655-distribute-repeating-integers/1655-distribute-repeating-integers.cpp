bool alg[52][1 << 10];
// ok[i][j]: if there are enough integers for the ith integer to be distributed into a quantity subset j
bool ok[52][1 << 10];

class Solution {
public:
    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        memset(alg, 0, sizeof(alg));
        memset(ok, 0, sizeof(ok));
        
        unordered_map<int, int> num_to_cnt;
        for (auto const &num : nums) {
            num_to_cnt[num]++;
        }
        vector<int> cnts;
        for (auto const &[_, cnt] : num_to_cnt) {
            cnts.push_back(cnt);
        }
        
        int m = cnts.size();
        int n = quantity.size();
        alg[m][(1 << n) - 1] = true;
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < (1 << n); ++j) {
                int sum = 0;
                for (int k = 0; k < n; ++k) {
                    if ((j >> k) & 1) {
                        sum += quantity[k];
                    }
                }
                if (sum <= cnts[i]) {
                    ok[i][j] = true;
                }
            }
        }
        
        for (int i = m - 1; i >= 0; --i) {
            for (unsigned int j = 0; j < (1 << n); ++j) {
                alg[i][j] = alg[i + 1][j];
                unsigned int whole_set = (~j) & ((1 << n) - 1);
				// https://cp-algorithms.com/algebra/all-submasks.html
                for (int subset = whole_set; subset > 0; subset = (subset - 1) & whole_set) {
                    if (ok[i][subset]) {
                        alg[i][j] = alg[i][j] || alg[i + 1][j | subset];
                    }
                }
            }
        }
        return alg[0][0];
    }
};