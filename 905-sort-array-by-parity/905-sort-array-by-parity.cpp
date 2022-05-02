class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int i=0;
        int j=nums.size()-1;
        vector<int> ans(j+1,0);
        for(int k=0;k<nums.size();k++){
            if(nums[k]%2==0){
                ans[i++]=nums[k];
                // i++;
            }
            else{
                ans[j--]=nums[k];
                // j--;
            }
        }
        return ans;
    }
};