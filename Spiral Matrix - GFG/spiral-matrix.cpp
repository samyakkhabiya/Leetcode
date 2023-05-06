//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int findK(vector<vector<int>> &a, int n, int m, int k)
    {
        // Your code goes here
        int startcol=0,endcol=m-1,startrow=0,endrow=n-1;
        
        while(startrow<=endrow and startcol<=endcol){
        for(int i=startcol;i<=endcol;i++){
            if(k==1)
                return a[startrow][i];
            // cout<<a[startrow][i]<<" ";
            k--;
        }
        startrow++;
        for(int i=startrow;i<=endrow;i++){
            if(k==1)
                return a[i][endcol];
            // cout<<a[i][endcol]<<" ";
            k--;
        }
        endcol--;
        for(int i=endcol;i>=startcol;i--){
            if(k==1)
                return a[endrow][i];
            // cout<<a[endrow][i]<<" ";
            k--;
        }
        endrow--;
        for(int i=endrow;i>=startrow;i--){
            if(k==1)
                return a[i][startcol];
            // cout<<a[i][startcol]<<" ";
            k--;
        }
        startcol++;
        }
        return -1;
    }
    
};

//{ Driver Code Starts.

int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n,m;
        int k=0;
        //cin>>k;
        cin>>n>>m>>k;
        vector<vector<int>> a(n, vector<int>(m, 0));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }

        Solution obj;

        cout<< obj.findK(a, n, m, k) << "\n";
        
       
    }
}
// } Driver Code Ends