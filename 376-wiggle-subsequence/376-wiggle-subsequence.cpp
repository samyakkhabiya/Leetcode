class Solution {
private:
    int longestWiggle(vector<int> &nums, int index, int prevNum, bool isUp, vector<vector<int>> &memo){
        if(index >= nums.size()) return 0;
        
        if(memo.at(index).at(isUp) != -1) return memo.at(index).at(isUp);
        
        if(nums.at(index) > prevNum && !isUp) 
            return memo.at(index).at(isUp) = 1 + longestWiggle(nums, index + 1, nums.at(index), true, memo);
        
        if(nums.at(index) < prevNum && isUp)
            return memo.at(index).at(isUp) = 1 + longestWiggle(nums, index + 1, nums.at(index), false, memo);
                
        return memo.at(index).at(isUp) = longestWiggle(nums, index + 1, nums.at(index), isUp, memo);     
    }
    
public:
    int wiggleMaxLength(vector<int>& nums) {
        vector<vector<int>> memo(nums.size(), vector<int>(2, -1));
        
        int up   = longestWiggle(nums, 0, nums.at(0), false, memo);
        int down = longestWiggle(nums, 0, nums.at(0), true,  memo);
        
        return 1 + max(up, down);
    }
};