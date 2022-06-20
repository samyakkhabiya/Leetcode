// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to find the largest number after k swaps.
    string ans;
    
    void dfs(string &str, int idx, int k){
        if(idx==str.size()-1 or k==0){
            if(ans<str)
                ans=str;
            return;
        }
            
        for(int i=idx+1;i<str.size();i++){
            if(str[i]>str[idx]){
                swap(str[i],str[idx]);
                dfs(str,idx+1,k-1);
                swap(str[i],str[idx]);
            }
        }
        dfs(str,idx+1,k);
    }
    
    string findMaximumNum(string str, int k)
    {
       // code here.
       dfs(str,0,k);
       return ans;
       
    }
};

// { Driver Code Starts.

int main()
{
    int t, k;
    string str;

    cin >> t;
    while (t--)
    {
        cin >> k >> str;
        Solution ob;
        cout<< ob.findMaximumNum(str, k) << endl;
    }
    return 0;
}
  // } Driver Code Ends