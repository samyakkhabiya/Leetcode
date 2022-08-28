class Solution {
public:
    int m,n;
    
    vector<int> dfs(vector<vector<int>>& mat, int idx, bool ch){
        int i=idx,j=idx;
        if(ch)
            j=0;
        else
            i=0;
        vector<int> temp;
        while(i<m and j<n){
            temp.push_back(mat[i][j]);
            i++;
            j++;
        }
        sort(temp.begin(),temp.end());
        return temp;
    }
    
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        m=mat.size();
        n=mat[0].size();
        vector<vector<int>> vc(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            int x=i,y=0;
            vector<int> sorted=dfs(mat,i,true);
            int k=0;
            while(x<m and y<n){
                vc[x][y]=sorted[k++];
                x++;
                y++;
            }
        }
        for(int i=1;i<n;i++){
            int x=0,y=i;
            vector<int> sorted=dfs(mat,i,false);
            int k=0;
            while(x<m and y<n){
                vc[x][y]=sorted[k++];
                x++;
                y++;
            }
        }
        return vc;
        
    }
};