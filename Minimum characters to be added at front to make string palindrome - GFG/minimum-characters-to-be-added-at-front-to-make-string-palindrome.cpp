// { Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    bool checkPalindrome(string& s, int start, int end) {
        while(start <= end) {
            if(s[start] != s[end]) return false;
            start++;
            end--;
        }
        
        return true;
    }

    int minChar(string str){
        int n = str.length();
        int i = 0;
        int len = 0; // single character will always a palindrome
        
        while(i < n) {
            if(checkPalindrome(str, 0, i)) {
                len = max(len, i+1);
                // cout << len << endl;
            }
            ++i;
        }
        
        return n-len;
    }
};


// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin >> str;
	    Solution ob;
	    int ans = ob.minChar(str);
	    cout << ans<<endl;
	}
	return 0;
}
  // } Driver Code Ends