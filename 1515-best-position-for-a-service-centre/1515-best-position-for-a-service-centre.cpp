class Solution {
    double dist(vector<int> &a, vector<double> &b) {
        return sqrt(pow(a[0] - b[0], 2) + pow(a[1] - b[1], 2));
    }
    double all(vector<vector<int>> &A, vector<double> &p) {
        double ans = 0;
        for (auto &a : A) ans += dist(a, p);
        return ans;
    }
    const int dirs[4][2] = {{0,1},{0,-1},{-1,0},{1,0}};
public:
    double getMinDistSum(vector<vector<int>>& A) {
        double ans = DBL_MAX;
        vector<double> p(2, 0);
        double step = 100, eps = 1e-6;
        while (step > eps) {
            bool found = false;
            for (auto &dir : dirs) {
                vector<double> next = {p[0] + step * dir[0], p[1] + step * dir[1]};
                double d = all(A, next);
                if (d < ans) {
                    ans = d;
                    p = next;
                    found = true;
                    break;
                }
            }
            if (!found) step /= 2;
        }
        return ans;
    }
};