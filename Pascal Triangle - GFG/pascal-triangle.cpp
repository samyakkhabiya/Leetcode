//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long

// } Driver Code Ends
// #define ll long long
class Solution{
public:
    int mod= 1000000007;
    vector<ll> nthRowOfPascalTriangle(int n) {
        // code here
        vector<vector<ll>> vc(n,vector<ll>(n,1));
        for(int i=0;i<n;i++){
            vc[i].resize(i+1);
                
            for(int k=1;k<i;k++){
                vc[i][k]=((vc[i-1][k-1]%mod)+(vc[i-1][k]%mod)%mod)%mod;
            }
        }
        return vc[n-1];
    }
};


//{ Driver Code Starts.


void printAns(vector<ll> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.nthRowOfPascalTriangle(n);
        printAns(ans);
    }
    return 0;
}

// } Driver Code Ends