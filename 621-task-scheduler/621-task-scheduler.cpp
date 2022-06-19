class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> ump;
        int ma=0;
        for(auto i:tasks){
            ump[i]++;
            ma=max(ma,ump[i]);
        }
        int ans=(ma-1)*(n+1);
        for(auto i:ump)
            if(i.second==ma)
                ans++;
        return max((int)tasks.size(),ans);
    }
};