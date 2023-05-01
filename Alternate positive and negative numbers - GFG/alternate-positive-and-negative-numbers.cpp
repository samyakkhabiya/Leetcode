//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:

	void rearrange(int arr[], int n) {
	    // code here
	    vector<int> poss;
	    vector<int> neg;
	    for(int i=0;i<n;i++){
	        if(arr[i]>=0)
	            poss.push_back(arr[i]);
	       else
	            neg.push_back(arr[i]);
	    }
	   // for(auto i:poss)
	   //     cout<<i<<" ";
	        
	   // cout<<endl;
	   
	   // for(auto i:neg)
	   //     cout<<i<<" ";
	        
	   // cout<<endl;
	    
	    if(poss.empty() or neg.empty())
	        return;
	    int i=0,j=0;
	    bool turn=true;
	    for(int k=0;k<n;k++){
	        if(i== poss.size()){
	            while(k<n)
	                arr[k++]=neg[j++];
	           return;
	        }
	        
	        if(j==neg.size()){
	            while(k<n)
	                arr[k++]=poss[i++];
	           return;
	        }
	        
	        if(turn){
	            arr[k]=poss[i++];
	            turn=false;
	        }
	        else{
	            arr[k]=neg[j++];
	            turn=true;
	        }
	    }
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.rearrange(arr, n);
        for (i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends