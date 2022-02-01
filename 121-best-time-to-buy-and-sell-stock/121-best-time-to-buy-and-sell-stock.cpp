class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=INT_MIN,ma=INT_MIN,mi=INT_MAX;
        for(int i=0;i<prices.size();i++){
            mi=min(mi,prices[i]);
            // ma=max(ma,prices[i]);
            ans=max(ans,(prices[i]-mi));
        }
        return ans<0?0:ans;
    }
};