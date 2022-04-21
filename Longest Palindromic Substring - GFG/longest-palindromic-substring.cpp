// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    
    
    
    string longestPalindrome(string s){
        // code here 
        int maxlen=0,start=0;
        for(int i=0;i<s.size();i++){
            int left=i;
            int right=i;
            while(left>=0 && right<s.size() && s[left]==s[right]){
                if(maxlen<right-left+1){
                    maxlen=right-left+1;
                    start=left;
                }
                left--;
                right++;
            }
            left=i;
            right=i+1;
            while(left>=0 && right<s.size() && s[left]==s[right]){
                if(maxlen<right-left+1){
                    maxlen=right-left+1;
                    start=left;
                }
                left--;
                right++;
            }
        }
        return s.substr(start,maxlen);
    }
};

// { Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.longestPalindrome(S)<<endl;
    }
    return 0;
}
  // } Driver Code Ends