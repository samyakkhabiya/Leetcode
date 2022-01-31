// { Driver Code Starts
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    int transform (string a, string b)
    {
        //code here.
        int m=a.size(),n=b.size();
        if(m!=n)
            return -1;
        int count=0;
        int sum2=0,sum1=0;
        for(int i=0;i<m;i++){
            sum1+=a[i];
            sum2+=b[i];
        }
        if(sum1!=sum2)
            return -1;
        int j=m-1,i=m-1;
        while(i>=0 and j>=0){
            if(a[i] == b[j]){
                i--,j--;
            }else{
                count++;
                i--;
            }
        }
        return count;
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
        Solution ob;
        cout <<ob.transform (A, B) << endl;
    }
}  // } Driver Code Ends