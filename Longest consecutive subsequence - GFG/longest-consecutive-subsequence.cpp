//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int n)
    {
      //Your code here
      sort(arr,arr+n);
    //   for(int i=0;i<n;i++)
    //     cout<<arr[i]<<" ";
      int maxlen=0,currmax=1;
      for(int i=0;i<n-1;i++){
            if(arr[i]==arr[i+1])
                continue;
            if(arr[i]+1==arr[i+1] )
                currmax++;
            else{
                maxlen=max(maxlen,currmax);
                currmax=1;
            }
      }
      maxlen=max(maxlen,currmax);
      return maxlen;
    }
};

//{ Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}
// } Driver Code Ends