class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        
        int count=0;
        unordered_map<int,int> ump;
        for(auto i:nums)
            ump[i]++;
        for(auto i:ump){
            if((k && ump.count(i.first+k)) || (!k && i.second>1))
                count++;
            // else if(k==0 && i.second>1)
            //     count++;
        }
        
        return count;
    }
};