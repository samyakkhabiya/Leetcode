class Solution {
public:
    int mod=1e9 + 7;
    int threeSumMulti(vector<int>& arr, int target) {
        unordered_map<int,int> ump;
        int ans=0;
        for(int i=0;i<arr.size();i++){
            ans=(ans + ump[target-arr[i]])%mod;
            for(int j=0;j<i;j++){
                ump[arr[i]+arr[j]]++;
            }
        }
        return ans;
    }
};