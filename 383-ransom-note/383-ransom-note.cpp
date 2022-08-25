class Solution {
public:
    bool canConstruct(string ran, string mag) {
        unordered_map<char,int> ump1,ump2;
        for(auto i:mag)
            ump1[i]++;
        for(auto i:ran)
            ump2[i]++;
        for(auto i:ump2){
            if(i.second>ump1[i.first])
                return false;
        }
        return true;
    }
};