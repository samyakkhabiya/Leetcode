class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> ump;
        for(int i:nums){
            ump[i]++;
            if(ump[i]>(nums.size()/2))
                return i;
        }
        return -1;
    }
};