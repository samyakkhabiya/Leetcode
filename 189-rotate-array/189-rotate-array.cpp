class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int fk=k%nums.size();
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+fk);
        reverse(nums.begin()+fk,nums.end());
        
    }
};