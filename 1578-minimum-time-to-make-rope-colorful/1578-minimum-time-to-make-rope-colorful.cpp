class Solution {
public:
    int minCost(string col, vector<int>& need) {
        int ma=0,sum=0,ans=0;
        for(int i=0;i<col.size();i++){
            if(i>0 and col[i-1]!=col[i]){
                ans+=sum-ma;
                sum=0;
                ma=0;
            }
            sum+=need[i];
            ma=max(ma,need[i]);
        }
        ans+=sum-ma;
        return ans;
    }
};