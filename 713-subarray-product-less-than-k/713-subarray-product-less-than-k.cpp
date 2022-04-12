class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
		if(k==0)
            return 0;
        
        int i=0,j=0;
        int pro=1,cnt=0;
        while(j<nums.size()){
            pro *= nums[j];
            while(i<=j && pro>=k){
                pro /= nums[i++];
            }
            cnt+= j-i+1;
            j++;
        }
        return cnt;
		
    }
};