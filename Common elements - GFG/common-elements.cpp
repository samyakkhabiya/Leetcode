// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:    
       vector <int> commonElements (int a[], int b[], int c[], int n1, int n2, int n3)
        {
            //code here.
            unordered_map<int,int> m1,m2;
            for(int i=0;i<n1;i++)
                m1[a[i]]++;
                
            for(int i=0;i<n2;i++)
                m2[b[i]]++;
            
            
            vector<int> ans;
            for(int i=0;i<n3;i++){
                if(i+1<n3 and c[i]==c[i+1])
                    continue;
                if(m1.count(c[i]) and m2.count(c[i]))
                    ans.push_back(c[i]);
            }
            return ans;
                
        }

};

// { Driver Code Starts.

int main ()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; 
        cin >> n1 >> n2 >> n3;
        int A[n1];
        int B[n2];
        int C[n3];
        
        for (int i = 0; i < n1; i++) cin >> A[i];
        for (int i = 0; i < n2; i++) cin >> B[i];
        for (int i = 0; i < n3; i++) cin >> C[i];
        
        Solution ob;
        
        vector <int> res = ob.commonElements (A, B, C, n1, n2, n3);
        if (res.size () == 0) 
            cout << -1;
        for (int i = 0; i < res.size (); i++) 
            cout << res[i] << " "; 
        cout << endl;
    }
}  // } Driver Code Ends