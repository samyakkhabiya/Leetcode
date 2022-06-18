class WordFilter {
public:
    unordered_map<string,int> ump;
    WordFilter(vector<string>& words) {
        int n=words.size();
        for(int i=0;i<n;i++){
            for(int j=1;j<=words[i].size();j++){
                string pre=words[i].substr(0,j);
                for(int k=0;k<words[i].size();k++){
                    string suff=words[i].substr(k,words[i].size());
                    ump[pre + "|" + suff]=i+1;
                }
            }
        }
    }
    
    int f(string prefix, string suffix) {
        return ump[prefix + "|" + suffix]-1;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */