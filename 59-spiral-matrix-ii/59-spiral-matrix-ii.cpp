class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int r=n,c=n;
        int firstRow=0,firstCol=0,lastRow=r-1,lastCol=c-1;
        int total=r*c;
        vector<vector<int>> matrix(r,vector<int>(c));
        int k=0;
        while(k<total){
            for(int i=firstCol;i<=lastCol;i++){
                matrix[firstRow][i]=k+1;
                k++;
            }
            firstRow++;
            if(k>=total)
                break;
            for(int i=firstRow;i<=lastRow;i++){
                matrix[i][lastCol]=k+1;
                k++;
            }
            lastCol--;
            if(k>=total)
                break;
            for(int i=lastCol;i>=firstCol;i--){
                matrix[lastRow][i]=k+1;
                k++;
            }
            lastRow--;
            if(k>=total)
                break;
            for(int i=lastRow;i>=firstRow;i--){
                matrix[i][firstCol]=k+1;
                k++;
            }
            firstCol++;
            
        }
        // for(auto i=0;i<k;i++){
        //         cout<<arr[i]<<" ";
        //     }
        return matrix;
    }
};