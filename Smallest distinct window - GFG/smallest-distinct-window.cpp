// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    int findSubString(string str)
    {
        // Your code goes here  
        unordered_map<char,int> ump;
        for(auto i:str)
            ump[i]++;
            
        int i=0,j=0,n=str.size();
        unordered_map<char,int> temp;
        int ma=INT_MAX;
        while(j<n){
            temp[str[j]]++;
            while(temp.size()==ump.size()){
                // cout<<str[j]<<" "<<j<<" ";
                ma=min(ma,j-i+1);
                temp[str[i]]--;
                if(temp[str[i]]==0)
                    temp.erase(str[i]);
                    
                i++;
            }
            j++;
                
        }
        return ma==INT_MAX?-1:ma;
    }
};

// { Driver Code Starts.
// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;
    }
    return 0;
}  // } Driver Code Ends