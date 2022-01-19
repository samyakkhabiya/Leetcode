class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        int n=mat.size();
        vector<int>v(n*n);
          int z=0;
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    v[z]=mat[i][j];
                    z++;
                }
            }
            sort(v.begin(),v.end());
            return v[k-1];
    }
};