#define ll long long
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int i=0,j=nums.size()-1;
        int count=0;
        while(i<j){
            int sum=nums[j]+nums[i];
            if(sum>k){
                j--;
            }
            else if(sum<k){
                i++;
            }
            else{
                count++;
                i++;
                j--;
            } 
        }
        return count;
    }
};