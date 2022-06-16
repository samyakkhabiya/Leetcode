class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        vector<int> stack;
        int d=nums.size()-k;
        for(auto i:nums){
            while(!stack.empty() and i<stack.back() and d){
                stack.pop_back();
                d--;
            }
            stack.push_back(i);
        }
        return vector<int>(stack.begin(),stack.begin()+k);
        
    }
};