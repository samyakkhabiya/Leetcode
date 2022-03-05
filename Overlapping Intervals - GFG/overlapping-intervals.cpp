// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    
    static bool cmp(pair<int,int> a, pair<int,int> b){
        return a.second<b.second;
    }
    
    vector<vector<int>> overlappedInterval(vector<vector<int>>& intervals) {
         // Code here
         vector<pair<int,int>> vc(intervals.size());
        int j=0;
        for(auto i:intervals){
            vc[j]=make_pair(i[0],i[1]);
            j++;
        }
        sort(vc.begin(),vc.end());
        vector<vector<int>> ans;
        j=0;
        j=vc[0].first;
        int k=vc[0].second;
        for(int i=1;i<vc.size();i++){
            if(vc[i].first<=k){
                k=max(vc[i].second,k);
            }
            else{
                ans.push_back({j,k});
                j=vc[i].first;
                k=vc[i].second;
            }
        }
        ans.push_back({j,k});
        return ans;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>Intervals(n);
		for(int i = 0; i < n; i++){
			int x, y;
			cin >> x >> y;
			Intervals[i].push_back(x);
			Intervals[i].push_back(y);
		}
		Solution obj;
		vector<vector<int>> ans = obj.overlappedInterval(Intervals);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends