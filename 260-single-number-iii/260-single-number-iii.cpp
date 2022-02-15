class Solution {
public:
    
    static bool cmp(pair<int,int> a, pair<int,int> b){
        return a.second<b.second;
    }
    
    vector<int> singleNumber(vector<int>& temp) {
        
        vector<pair<int,int>> ans;
        vector<pair<int,int>> nums;
        for(int i=0;i<temp.size();i++){
            nums.push_back({temp[i],i});
        }
        sort(nums.begin(),nums.end());
        
        if(nums[0].first!=nums[1].first)
            ans.push_back(nums[0]);
        if(nums[nums.size()-1].first!=nums[nums.size()-2].first)
            ans.push_back(nums[nums.size()-1]);
        
        if(ans.size()==2){
            vector<int> a(2);
            sort(ans.begin(),ans.end(),cmp);
            a[0]=ans[0].first;
            a[1]=ans[1].first;
            return a;
        }
        
        for(int i=1;i<nums.size()-1;i++){
            if(nums[i].first!=nums[i-1].first && nums[i].first!=nums[i+1].first){
                ans.push_back(nums[i]);
                if(ans.size()==2){
                    vector<int> a(2);
                    sort(ans.begin(),ans.end(),cmp);
                    a[0]=ans[0].first;
                    a[1]=ans[1].first;
                    return a;
                }
            }
        }
        return {0,0};
    }
};