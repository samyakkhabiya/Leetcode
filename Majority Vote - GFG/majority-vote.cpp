//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> Solve(int n, vector<int>& nums) {
        // Code here
        unordered_map<int,int> ump;
        vector<int> ans;
        for(auto i:nums){
            ump[i]++;
        }
        for(auto i:ump){
            if(i.second>(n/3))
                ans.push_back(i.first);
        }
        sort(ans.begin(),ans.end());
        if(ans.size()==0)
            ans.push_back(-1);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        Solution obj;

        vector<int> res = obj.Solve(n, a);

        for (auto x : res) cout << x << " ";

        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends