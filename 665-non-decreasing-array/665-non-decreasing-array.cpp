class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int cnt=1,n=nums.size(),ma=INT_MIN;
        for(int i=0;i<n-1;i++){
            if(nums[i]<=nums[i+1])
                ma=nums[i];
            else{
                if(ma>nums[i+1]){
                    nums[i+1]=nums[i];
                }
                cnt--;
            }
            if(cnt<0)
                return false;
        }
        return true;
    }
};