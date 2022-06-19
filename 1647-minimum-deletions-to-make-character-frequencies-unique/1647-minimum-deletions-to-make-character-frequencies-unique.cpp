class Solution {
public:
    int minDeletions(string s) {
        unordered_set<int> seen;
        unordered_map<char,int> ump;
        int ans=0;
        for(auto i:s)
            ump[i]++;
        for(auto [k,v]:ump){
            while(seen.find(v)!=seen.end()){
                v--;
                ans++;
            }
            if(v>0)
                seen.insert(v);
        }
        return ans;
            
    }
};