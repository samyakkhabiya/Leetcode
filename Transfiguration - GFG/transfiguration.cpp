// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    
    public:
    int transfigure (string a, string b)
    {
    	// Your code goes here
    	if(a.size()!=b.size())
    	    return -1;
    	    
    	   vector<int> count(256);
    	   for(int i=0;i<a.size();i++){
    	       count[a[i]]++;
    	       count[b[i]]--;
    	   }
    	   for(auto i:count){
    	       if(i)
    	        return -1;
    	   }
    	   
    	   int i=a.size()-1,j=i,ans=0;
    	   while(i>=0 and j>=0){
    	       if(a[i]!=b[j]){
    	           ans++;
    	           i--;
    	       }
    	       else{
    	           i--;
    	           j--;
    	       }
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
        string A, B; 
        cin >> A >> B;
        Solution obj;
        cout << obj.transfigure (A, B) << endl;
    }
}  // } Driver Code Ends