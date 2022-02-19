class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        vector<pair<int,int>> vc;
        for(int i=0;i<nums.size();i++){
            vc.push_back({nums[i],i});
        }
        sort(vc.begin(),vc.end());
        int count=0;
        for(int i=0;i<nums.size();i++){
            int j=i+1;
            while(j<nums.size() && vc[i].first==vc[j].first){
                if((vc[i].second*vc[j].second)%k==0)
                    count++;
                j++;
            }
        }
        return count;
    }
};