class Solution {
public:
    unordered_map<string,bool> memo;
    unordered_map<string,bool> dict;
    bool dfs(string s){
        if(dict.find(s)!=dict.end())
            return true;
        if(memo.find(s)!=memo.end())
            return memo[s];
        for(int i=0;i<s.size();i++){
            string first=s.substr(0,i+1);
            string last=s.substr(i+1);
            if(dict.find(first)!=dict.end()){
                if(dfs(last)){
                    memo[s]=true;
                    return true;
                }
            }
        }
        memo[s]=false;
        return false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        for(auto i:wordDict)
            dict[i]=true;
        
        return dfs(s);
    }
};