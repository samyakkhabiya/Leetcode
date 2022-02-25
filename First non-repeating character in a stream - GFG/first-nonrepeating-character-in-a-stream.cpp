// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    queue<char> q;
		    map<char, int> freq;
		    string ans="";
		    
		    for(int i=0; i<A.length(); i++){
		        
		        if(freq[A[i]]<1){
		            freq[A[i]]++;
		            q.push(A[i]);
		        }
		        else
    		        freq[A[i]]++;
    		        
		        
		        while(!q.empty() && freq[q.front()]>1)
		            q.pop();
		        
		        if(q.empty())
    		        ans.push_back('#');
		        else
		            ans.push_back(q.front());
		    }
		    
		    return ans;
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends