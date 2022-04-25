// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    
    int dp[1001][1001];
    
    int recurs(string& nums1, string& nums2,int i,int j)
    {
        
        if(i<0||j<0)
        {
            return 0;
        }
        
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        
       
        recurs(nums1,nums2,i-1,j);
        recurs(nums1,nums2,i,j-1);
            
            if(nums1[i]==nums2[j])
            {
                return dp[i][j]=recurs(nums1,nums2,i-1,j-1)+1;
            }
        
           else
            {
            return dp[i][j]=0;
            }
    }
    
    int longestCommonSubstr (string nums1, string nums2, int n, int m)
    {
        // your code here
        for(int i=0;i<=nums1.size();i++)
        {
             for(int j=0;j<=nums2.size();j++)
            {
                dp[i][j]=-1;
            }
            
        }
        
         recurs(nums1,nums2,nums1.size()-1,nums2.size()-1);
        int max1=0;
        
         for(int i=0;i<=nums1.size();i++)
        {
             for(int j=0;j<=nums2.size();j++)
            {
                max1=max(max1,dp[i][j]);
            }
            
        }
        
        return max1;
    }
};

// { Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends