class Solution {
public:
    
    int dp[1001][1001];
    
    int recurs(vector<int>& nums1, vector<int>& nums2,int i,int j)
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
    
    
    
    
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        
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