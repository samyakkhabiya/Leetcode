// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
    vector<string>ans;
    vector<string>ip;
    
    string convertToIp(vector<string>&temp)
    {
        string conv="";
        for(auto it:temp) conv+= it+".";
        conv.pop_back();
        return conv;
    }
    
    void solve(string &s,int i ,int len)
    {
       if(i>len and ip.size()>4) return;
        if(i==len){
            if(ip.size()!=4) return ;
            string str=convertToIp(ip);
            ans.push_back(str);
            return;
        }
        
        ip.push_back(s.substr(i,1));
        solve(s,i+1,len);
        ip.pop_back();
        if(i<len-1){
            ip.push_back(s.substr(i,2));
            if(s.substr(i,2)[0]!='0') solve(s,i+2,len);
            ip.pop_back();
        }
        if(i<len-2){
            ip.push_back(s.substr(i,3));
            if(s.substr(i,3)[0]!='0' and s.substr(i,3)<"256") solve(s,i+3,len);
            ip.pop_back();
        }
        
    }
        
    vector<string> genIp(string &s) {
        // Your code here
         int n = s.length();
         solve(s,0,n);
         return ans;
    }


};

// { Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;

        /*generating naively*/
        Solution obj;
        vector<string> str = obj.genIp(s);
        sort(str.begin(), str.end());
        if(str.size()==0)
            cout << -1 << "\n";
        else{
            for (auto &u : str) {
                cout << u << "\n";
            }
        }
    }
}  // } Driver Code Ends