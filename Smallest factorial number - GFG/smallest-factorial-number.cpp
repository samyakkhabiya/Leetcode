// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
    public:
        bool check(int mid,int n){
           int cnt = 0, f = 5;
           while(f <= mid){
               cnt += mid / f;
               f *= 5;
           }
           return (cnt >= n);
       }
       
       int findNum(int n){
           if(n == 1)
               return (5);
           
           int s = 0, e = 5*n;
           int ans = -1;
           while(s <= e){
               int mid = (s+e)/2;
               
               if(check(mid,n)){
                   ans = mid;
                   e = mid - 1;
               }
               else s = mid + 1;
           }
           return (ans);
       }
};

// { Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        Solution ob;
        cout <<ob.findNum(n) << endl;
    }
return 0;
}  // } Driver Code Ends