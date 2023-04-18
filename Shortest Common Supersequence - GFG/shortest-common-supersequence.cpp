//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++


class Solution{
    
    public:
    //Declaring our cache for storing sub problems
    int t[101][101];
    
    int LCS(string x, string y, int m, int n){
        // If any of them string is empty then there is no LCS, return 0
        if(m == 0 || n == 0) return 0;
        
        // If our cache has answer for subproblem then return it
        if(t[m][n] != -1) return t[m][n];
        
        // If both the elements are same then it could be LCS, so, increament by one and do the same with rest of the element 
        if(x[m-1] == y[n-1]){
            return t[m][n] = 1 + LCS(x, y, m-1, n-1);
        }
        // Else check for reduced string of both one by one
        else{
            return t[m][n] = max(LCS(x, y, m-1, n), LCS(x, y, m, n-1));
        }
    }
    
    int shortestCommonSupersequence(string X, string Y, int m, int n){
        memset(t, -1, sizeof(t));
        int lcs = LCS(X, Y, m, n); // We get the length of LCS
        return m + n - lcs; // So, using our LCS we can calculate this problem too.
    }
};

//{ Driver Code Starts.

int main()
{   
    
    int t;
    
    //taking total testcases
    cin >> t;
    while(t--){
    string X, Y;
    //taking String X and Y
	cin >> X >> Y;
	
	//calling function shortestCommonSupersequence()
	Solution obj;
	cout << obj.shortestCommonSupersequence(X, Y, X.size(), Y.size())<< endl;
    }
	return 0;
}


// } Driver Code Ends