// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++


// int solve(vector<int>&nums,int k,int k1,int n,int i){
//       if(i==n-1){
//           if(k1>nums[i])
//           return 0;
//           else
//           return k1*k1;
//       }
//       else if(k1==k){
//           return solve(nums,k,k-nums[i],n,i+1);
//       }
//       else{
//           if(k1>nums[i])
//           return min(k1*k1+solve(nums,k,k,n,i),solve(nums,k,k1-1-nums[i],n,i+1));
//           else
//           return k1*k1+solve(nums,k,k,n,i);
//       }
//   }

//   int solveWordWrap(vector<int>nums, int k) 
//   {
//       int n=nums.size();
//       for(int i=0;i<n;i++){
//           if(k-nums[i]<0)
//           return 0;
//       }
//       return solve(nums,k,k,n,0);
//   }

class Solution {
public:
    vector<vector<int>> dp;
    
    int dpmem(vector<int>nums, int n, int k, int k1, int i){
        if(i==n-1){
            if(k1>nums[i]){
                return dp[i][k1]=0;
            }
            else
                return dp[i][k1]=k1*k1;
        }
        if(dp[i][k1]!=-1)
            return dp[i][k1];
        if(k==k1){
            return dp[i][k1]=dpmem(nums,n,k,k1-nums[i],i+1);
        }
        else{
            if(k1>nums[i]){
                dp[i][k1]=min(k1*k1+dpmem(nums,n,k,k,i),dpmem(nums,n,k,k1-nums[i]-1,i+1));
                return dp[i][k1];
            }
            else{
                return dp[i][k1]=k1*k1+dpmem(nums,n,k,k,i);
            }
        }
    }
    
    int solveWordWrap(vector<int>nums, int k) 
    { 
        int n=nums.size();
       for(int i=0;i<n;i++){
           if(k-nums[i]<0)
           return 0;
       }
        dp.clear();
        dp.resize(nums.size()+1,vector<int>(k+1,-1));
        return dpmem(nums,n,k,k,0);
    } 
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, k;
        cin >> n;
        vector<int>nums(n);
        for (int i = 0; i < n; i++)cin >> nums[i];
        cin >> k;
        Solution obj;
        cout << obj.solveWordWrap(nums, k) << endl;
	}
	return 0;
}  // } Driver Code Ends