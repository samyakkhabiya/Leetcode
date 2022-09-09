class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowPos, vector<int>& colPos) {
        int x1 = startPos[0];
        int x2 = homePos[0];
        int y1 = startPos[1];
        int y2 = homePos[1];
        int ans = 0;

        if (x1 == x2 && y1 == y2) return 0; // when start and home at same position

        if (x1 < x2) {
            for (int i = x1 + 1; i <= x2 ; i++)
                ans += rowPos[i];
        }
        else {
            for (int i = x2; i <= x1 - 1; i++)
                ans += rowPos[i];
        }

        if (y1 < y2) {
            for (int i = y1 + 1; i <= y2 ; i++)
                ans += colPos[i];
        }
        else {
            for (int i = y2; i <= y1 - 1; i++)
                ans += colPos[i];
        }
        return ans;
    }
};