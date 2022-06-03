class NumMatrix {
public:
    vector<vector<int>> vc;
    vector<vector<int>> mat;
    NumMatrix(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vc.resize(m,vector<int>(n,0));
        mat=matrix;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(j==0)
                    vc[i][j]=matrix[i][j];
                else
                    vc[i][j]=vc[i][j-1]+matrix[i][j];
            }
        }
        // for(auto i:vc){
        //     for(auto j:i){
        //         cout<<j<<" ";
        //     }
        //     cout<<endl;
        // }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum=0;
        for(int i=row1;i<=row2;i++){
                sum+=vc[i][col2]-vc[i][col1]+mat[i][col1];
        }
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */