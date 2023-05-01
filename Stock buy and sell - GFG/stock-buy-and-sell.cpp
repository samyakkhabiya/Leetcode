//{ Driver Code Starts
// Program to find best buying and selling days
#include <bits/stdc++.h>

using namespace std;

// This function finds the buy sell schedule for maximum profit
void stockBuySell(int *, int);

// Driver program to test above functions
int main() {
    int T;
    cin >> T;

    while (T--) {
        int n, i;
        cin >> n;
        int price[n];
        for (i = 0; i < n; i++) cin >> price[i];
        // function call
        stockBuySell(price, n);
    }
    return 0;
}

// } Driver Code Ends


// User function template for C++


// This function finds the buy sell schedule for maximum profit
void stockBuySell(int price[], int n) {
    // code here
    int buy=-1,sell=-1;
    vector<pair<int,int>> vc;
    for(int i=0;i<n-1;i++){
        if(price[i]>price[i+1]){
            if(buy!=-1){
                sell=i;
                if(buy!=sell)
                    vc.push_back({buy,sell});
            }
            buy=i+1;
        }
        else if(price[i]<price[i+1] and buy==-1){
            buy=i;
        }
    }
    if(buy!=-1 and price[buy]<price[n-1]){
        sell=n-1;
        vc.push_back({buy,sell});
    }
    for(auto i:vc)
        cout<<"("<<i.first<<" "<<i.second<<")"<<" ";
        
    if(vc.empty())
        cout<<"No Profit";
    cout<<endl;
    
    
}