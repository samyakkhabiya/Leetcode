//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    #define ll long long
    long long maxSubarraySum(int arr[], int n){
        
        // Your code here
        ll currsum=0,maxsum=INT_MIN;
        for(int i=0;i<n;i++){
                
            currsum=max(currsum+arr[i],(ll)arr[i]);
                
            maxsum=max(maxsum,currsum);
        }
        return maxsum;
        
        
    }
};

//{ Driver Code Starts.

int main()
{
    int t,n;
    
    cin>>t; //input testcases
    while(t--) //while testcases exist
    {
        
        cin>>n; //input size of array
        
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
            
        Solution ob;
        
        cout << ob.maxSubarraySum(a, n) << endl;
    }
}

// } Driver Code Ends