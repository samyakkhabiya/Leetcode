class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int sum=0;
        for(auto i:nums){
            if(i%2==0)
                sum+=i;
        }
        vector<int> ans;
        for(auto i:queries){
            int prev=nums[i[1]];
            if(prev%2==0)
                sum-=prev;
            nums[i[1]] += i[0];
            if(nums[i[1]]%2==0)
                sum+=nums[i[1]];
            ans.push_back(sum);
        }
        return ans;
    }
};