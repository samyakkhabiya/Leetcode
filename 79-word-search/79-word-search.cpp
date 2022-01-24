class Solution {
public:
    int dp[10][10];
    int m,n;
    bool vis[10][10];
    
    bool dpmem(vector<vector<char>>& board, string& word, int i, int j, int k){
        if(k==word.size())
            return true;
        if(i<0 || j<0 || i>=m || j>=n || board[i][j]!=word[k])
            return false;
            
        
        char temp=board[i][j];
        board[i][j]='*';
        
        bool t=dpmem(board,word,i+1,j,k+1) || dpmem(board,word,i-1,j,k+1) || dpmem(board,word,i,j+1,k+1) || dpmem(board,word,i,j-1,k+1);
        
        board[i][j]=temp;
        return t;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        memset(dp,-1,sizeof(dp));
        
        m=board.size();
        n=board[0].size();
        // if(m==1 && n==1 && word.size()==1){
        //     return board[0][0]==word[0];
        // }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word[0]){
                    cout<<i<<" "<<j<<endl;
                    // memset(vis,0,sizeof(vis));
                    if(dpmem(board,word,i,j,0)){
                        // cout<<i<<" "<<j<<endl;
                        return true;
                    }
                }
            }
        }
        return false;
    }
};