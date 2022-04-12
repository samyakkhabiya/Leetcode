class Solution {
public:
    
    bool ch(vector<vector<int>> board, int i, int j){
        int m=board.size();
        int n=board[0].size();
        if(i<0 || j<0 || i>=m || j>=n)
            return false;
        return true;
    }
    
    int solve(vector<vector<int>> board, int i, int j){
        int m=board.size();
        int n=board[0].size();
        int count=0;
        if(ch(board,i+1,j) && board[i+1][j]){
            count++;
        }
        if(ch(board,i-1,j) && board[i-1][j]){
            count++;
        }
        if(ch(board,i,j+1) && board[i][j+1]){
            count++;
        }
        if(ch(board,i,j-1) && board[i][j-1]){
            count++;
        }
        
        if(ch(board,i+1,j+1) && board[i+1][j+1]){
            count++;
        }
        if(ch(board,i-1,j+1) && board[i-1][j+1]){
            count++;
        }
        if(ch(board,i-1,j-1) && board[i-1][j-1]){
            count++;
        }
        if(ch(board,i+1,j-1) && board[i+1][j-1]){
            count++;
        }
        return count;
    }
    
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> vc(board.size(),vector<int>(board[0].size(),0));
        int m=board.size();
        int n=board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int x=solve(board,i,j);
                if(board[i][j]==1 && (x==2 || x==3))
                    vc[i][j]=1;
                if(board[i][j]==0 && x==3)
                    vc[i][j]=1;
                    
            }
        }
        board=vc;
        
    }
};