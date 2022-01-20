// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	    vector<string> ans;
	
	    void permute(string s,int i, int j){
	        if(i==j){
	            ans.push_back(s);
	        }
	        else{
	            for(int k=i;k<=j;k++){
	                swap(s[i],s[k]);
	                permute(s,i+1,j);
	                swap(s[i],s[k]);
	            }
	        }
	    }
	    
	    
		vector<string>find_permutation(string S)
		{
		    // Code here there
		    ans.clear();
		    permute(S,0,S.size()-1);
		    sort(ans.begin(),ans.end());
		    return ans;
		    
		}
};



// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}
  // } Driver Code Ends