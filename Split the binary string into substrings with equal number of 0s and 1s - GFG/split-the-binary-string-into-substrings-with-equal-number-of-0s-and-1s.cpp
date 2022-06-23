// { Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    int maxSubStr(string str){
        //Write your code here
        int zero=0,one=0;
        int ans=0;
        for(int i=0;i<str.size();i++){
            if(zero!=0 and one!=0 and zero == one){
                zero=0;
                one=0;
                ans++;
            }
            if(str[i]=='1')
                one++;
            else
                zero++;
        }
        if(zero!=0 and one!=0 and zero == one)
            ans++;
        else 
            return -1;
        
        return ans;
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
	    int ans = ob.maxSubStr(str);
	    cout << ans<<endl;
	}
	return 0;
}
  // } Driver Code Ends