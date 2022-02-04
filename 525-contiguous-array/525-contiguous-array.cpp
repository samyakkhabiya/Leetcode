class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> ump;
        int sum=0;
        int ans=0;
        for(int i=0;i<n;i++){
            sum += nums[i]?1:-1;
            
            if(sum==0){
                ans=i+1;
            }
            else if(ump.count(sum)){
                ans=max(ans,i-ump[sum]);
            }
            else
                ump[sum]=i;
        }
        return ans;
        
    }
};