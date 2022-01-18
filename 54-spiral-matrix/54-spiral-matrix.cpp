class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int r=matrix.size(),c=matrix[0].size();
        int firstRow=0,firstCol=0,lastRow=r-1,lastCol=c-1;
        int total=r*c,count=0;
        // int *ans;
        vector<int> arr(r*c);
        // int *ans=arr;
        int k=0;
        while(k<total){
            for(int i=firstCol;i<=lastCol;i++){
                arr[k]=matrix[firstRow][i];
                k++;
            }
            firstRow++;
            if(k>=total)
                break;
            for(int i=firstRow;i<=lastRow;i++){
                arr[k]=matrix[i][lastCol];
                k++;
            }
            lastCol--;
            if(k>=total)
                break;
            for(int i=lastCol;i>=firstCol;i--){
                arr[k]=matrix[lastRow][i];
                k++;
            }
            lastRow--;
            if(k>=total)
                break;
            for(int i=lastRow;i>=firstRow;i--){
                arr[k]=matrix[i][firstCol];
                k++;
            }
            firstCol++;
            
        }
        // *ans=arr;
        // for(auto i=0;i<k;i++){
        //         cout<<arr[i]<<" ";
        //     }
        return arr;
    }
};