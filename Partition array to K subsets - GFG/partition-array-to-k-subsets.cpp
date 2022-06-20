// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*You are required to complete this method */

class Solution{
  public:
    
    bool dfs(int sum, int n, vector<bool>& vis, int csum, int arr[], int k){
        if(k==1)
            return true;
            
        if(csum>sum)
            return false;
            
        if(csum==sum){
            return dfs(sum,n,vis,0,arr,k-1);
        }
        for(int i=0;i<n;i++){
            if(!vis[i]){
                vis[i]=true;
                if(dfs(sum,n,vis,csum+arr[i],arr,k))
                    return true;
                vis[i]=false;
            }
                
        }
        return false;
            
        
    }
    
    bool isKPartitionPossible(int a[], int n, int k)
    {
         //Your code here
         vector<bool> vis(n,false);
         int sum=0;
         for(int i=0;i<n;i++)
            sum+=a[i];
            
        if(sum%k!=0)
            return false;
            
        sum/=k;
        return dfs(sum,n,vis,0,a,k);
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	
    	cin>>n;
    	int a[n];
    	for(int i=0;i<n;i++)
    	cin>>a[i];
    	int k;
    	cin>>k;
    	Solution obj;
    	cout<<obj.isKPartitionPossible(a, n, k)<<endl;
    }
}  // } Driver Code Ends