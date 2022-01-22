class Solution {
public:
    bool dig(int n, int turn, vector<vector<int>> &dp) {
        if (dp[turn][n] != -1) return dp[turn][n];
		
        if (turn == 1) { // Alice's Turn, where he wants to win. 
            if (n == 0) return false; // no moves for Alice, i.e., Alice looses.
            bool curr = false;
            for (int i = 1; i*i <= n; ++i) {
                int left = n - (i * i);
                curr |= dig(left, 0, dp); // if next move leads Alice to win, we will consider it.
                if (curr) return dp[turn][n] = true;
            }
            return dp[turn][n] = false;
        } else { // Bob's Turn, where he wants Alice to loose.
            if (n == 0) return true; // no moves for Bob, i.e., Alice wins.
            bool curr = true;
            for (int i = 1; i*i <= n; ++i) {
                int left = n - (i * i);
                curr &= dig(left, 1, dp); // if next move leads Alice to loose, we will consider it.
                if (!curr) return dp[turn][n] = false;
            }
            return dp[turn][n] = true;
        }
    }
    bool winnerSquareGame(int n) {
        vector<vector<int>> dp(2, vector<int>(n+1, -1));
        return dig(n, 1, dp);
    }
};