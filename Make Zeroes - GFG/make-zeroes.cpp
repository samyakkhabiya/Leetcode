//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int m,n;
    
    void dfs(vector<vector<int>> &matrix, vector<vector<int>> &vc, int i, int j){
        int sum=0;
        if(i-1>=0){
            sum+=matrix[i-1][j];
            vc[i-1][j]=0;
        }
        if(i+1<m){
            sum+=matrix[i+1][j];
            vc[i+1][j]=0;
        }
        if(j-1>=0){
            sum+=matrix[i][j-1];
            vc[i][j-1]=0;
        }
        if(j+1<n){
            sum+=matrix[i][j+1];
            vc[i][j+1]=0;
        }
        vc[i][j]=sum;
    }

    void MakeZeros(vector<vector<int> >& matrix) {
        // Code here
        m=matrix.size();
        n=matrix[0].size();
        vector<vector<int>> vc=matrix;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0)
                    dfs(matrix,vc,i,j);
            }
        }
        matrix=vc;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> matrix(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		ob.MakeZeros(matrix);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cout << matrix[i][j] <<" ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends