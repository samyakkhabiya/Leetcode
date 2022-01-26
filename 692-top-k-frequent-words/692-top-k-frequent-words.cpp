class Solution {
public:
    
    static bool cmp(pair<int,string> a, pair<int,string> b){
        if(a.first==b.first){
            return a.second<b.second;
        }
        return a.first>b.first;
    }
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> ump;
        for(auto s:words){
            ump[s]++;
        }
        vector<pair<int,string>> temp;
        for(auto i:ump){
            temp.push_back({i.second,i.first});
        }
        // for(auto i:temp)
        //     cout<<i.first<<" "<<i.second<<" ";
        // cout<<endl;
        sort(temp.begin(),temp.end(),cmp);
        // for(auto i:temp)
        //     cout<<i.first<<" "<<i.second<<" ";
        // cout<<endl;
        vector<string> ans;
        for(int i=0;i<k;i++){
            ans.push_back(temp[i].second);
        }
        return ans;
    }
};