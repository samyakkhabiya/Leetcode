class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        if(nums.size()==0){
            return {};
        }
        if(nums.size()==1){
            return {to_string(nums[0])};
        }
        for(int i=0;i<nums.size()-1;i++){
            long long x=nums[i],y=-1;
            bool ch=false;
            string temp="";
            while(i<nums.size()-1 && nums[i]+1==nums[i+1]){
                i++;
                y=nums[i];
                ch=true;
            }
            if(ch==false){
                temp= to_string(x);
            }
            else{
                temp= to_string(x) + "->" + to_string(y);
            }
            ans.push_back(temp);
        }
        if(nums[nums.size()-1] != nums[nums.size()-2]+1){
            ans.push_back(to_string(nums[nums.size()-1]));
        }
        return ans;
    }
};