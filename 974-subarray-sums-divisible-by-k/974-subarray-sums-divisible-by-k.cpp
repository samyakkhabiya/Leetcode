class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> ump;
        ump[0]++;
        int count=0;
        int currsum=0,reminder=0;
        for(int i=0;i<n;i++){
            currsum+=nums[i];
            reminder=currsum%k;
            if(reminder<0)
                reminder+=k;
                
            if(ump[reminder])
                count+=ump[reminder];
            ump[reminder]++;
        }
        return count;
        
        
        
    }
};