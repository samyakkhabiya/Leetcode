class Solution {
public:
    bool canJump(vector<int>& nums) {
        int ma=nums[0];
        for(int i=1;i<nums.size();i++){
            ma--;
            if(ma<0)
                return false;
            if(i!=nums.size()-1 and ma==0 and nums[i]==0)
                return false;
            ma=max(ma,nums[i]);
        }
        return true;
    }
};