// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &a, int target) {
        // Your code goes here
        int n=a.size();
    vector<vector<int>>res;
    if(a.empty())return res;
    sort(a.begin(),a.end());
    
    for(int i=0;i<n;i++)
    {
      
            for(int j=i+1;j<n;j++)
            {
                    int sum = target -a[i]-a[j];
                    int left=j+1;int right=n-1;
                    while(left<right)
                    {
                      int  two = a[left]+a[right];
                    if( two >sum)right--;
                    else if( two < sum)left++;
                    else
                    {
                        vector<int>temp(4,0);
                        temp[0]=a[i];
                        
                        temp[1]=a[j];
                        
                        temp[2]=a[left];
                        
                        temp[3]=a[right];
                        res.push_back(temp);
                    
                    while(left<right && a[left]==temp[2])++left;
                    while(left<right && a[right]==temp[3])--right;
            
                }
                }

             
            while(j+1<n&&a[j+1]==a[j])j++;}
            while(i+1<n&&a[i+1]==a[i])i++;}
        
    
    return res;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends