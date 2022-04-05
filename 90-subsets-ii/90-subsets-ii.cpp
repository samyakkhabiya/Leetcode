class Solution {
public:
    vector<vector<int>> ans;
    vector<int> sub;
    
    void solve(vector<int>& nums, int src){
        ans.push_back(sub);
        for(int i=src;i<nums.size();i++){
            if(i==src || nums[i]!=nums[i-1]){
                sub.push_back(nums[i]);
                solve(nums,i+1);
                sub.pop_back();
            }
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        ans.clear();
        sub.clear();
        sort(nums.begin(),nums.end());
        solve(nums,0);
        return ans;
    }
};