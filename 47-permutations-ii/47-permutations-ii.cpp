class Solution {
public:
    vector<vector<int>> ans;
    
    void dfs(int idx, int n, vector<int> nums){
        if(idx==n-1){
            ans.push_back(nums);
            return;
        }
        for(int i=idx;i<n;i++){
            if(idx!=i and nums[i]==nums[idx])
                continue;
            swap(nums[i],nums[idx]);
            dfs(idx+1,n,nums);
            
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        dfs(0,nums.size(),nums);
        return ans;
    }
};

