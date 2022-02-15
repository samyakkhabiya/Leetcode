class Solution {
public:
    
    void solve(vector<int>& nums, set<vector<int>>& result, vector<int>& sub, int size,int idx){
        if(size>=2)
            result.insert(sub);
        
        for(int i=idx;i<nums.size();i++){
            if(sub.size()==0 || nums[i]>=sub[sub.size()-1]){
                sub.push_back(nums[i]);
                solve(nums,result,sub,size+1,i+1);
                sub.pop_back();
            }
        }
    }
    
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>> result;
        vector<int> sub;
        solve(nums,result,sub,0,0);
        vector< vector<int>> fans(result.begin(),result.end());
        return fans;
    }
};