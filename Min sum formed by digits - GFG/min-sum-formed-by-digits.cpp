// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution{
    public:
    long long int minSum(int arr[], int n)
    {
        // Your code goes here
        long long c1=0,c2=0;
        sort(arr,arr+n);
        int i=0,j=1;
        int z;
        for(z=0;z<n;z++){
            if(arr[z]!=0)
                break;
        }
        for(int k=z+1;k<n;k+=2){
            c2+=arr[k];
            c2*=10;
        }
        c2/=10;
        for(int k=z;k<n;k+=2){
            c1+=arr[k];
            c1*=10;
        }
        c1/=10;
        return c1+c2;
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
        int arr[n+1];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.minSum(arr, n)<<endl;
    }
    return 0;
}
  // } Driver Code Ends