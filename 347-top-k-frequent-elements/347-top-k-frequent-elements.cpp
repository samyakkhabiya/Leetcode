class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue< pair<int,int> > pq;
        unordered_map<int,int> ump;
        for(auto i:nums)
            ump[i]++;
        for(auto i:ump){
            pq.push({i.second,i.first});
        }
        vector<int> ans;
        // for(auto& i:pq)
        //     break;
        while(pq.size() && k){
            auto i=pq.top();
            pq.pop();
            k--;
            ans.push_back(i.second);
        }
        return ans;
    }
};