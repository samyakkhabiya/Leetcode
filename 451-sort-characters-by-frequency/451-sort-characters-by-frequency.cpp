class Solution {
public:
    
    static bool cmp(pair<char,int> a,pair<char,int> b){
        return a.second>b.second;
    }
    
    string frequencySort(string s) {
        unordered_map<char,int> temp;
        for (char c : s) temp[c]++;
        
        
        vector<pair<char,int>> vc;
        for(auto i:temp){
            // if(temp[i]>0)
            vc.push_back({i.first,i.second});
        }
        
        sort(vc.begin(),vc.end(),cmp);
        // for(auto i:vc){
        //     cout<<i.first<<" "<<i.second<<endl;
        // }
        string ans;
        for(auto i:vc){
            for(int j=0;j<i.second;j++)
                ans+=i.first;
        }
        return ans;
        // return "";
    }
};