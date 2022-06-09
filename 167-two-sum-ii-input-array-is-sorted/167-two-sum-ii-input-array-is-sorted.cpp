class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i=0,j=nums.size()-1;
        vector<int> ans(2,0);
        while(i<j){
            int sum=nums[i]+nums[j];
            if(sum>target){
                j--;
            }
            else if(sum<target){
                i++;
            }
            else{
                ans[0]=i+1;
                ans[1]=j+1;
                break;
            }     
        }
        return ans;
    }
};