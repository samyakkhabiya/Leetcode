class Encrypter {
public:
    unordered_map<char,string> enc;
    unordered_map<string,int> dec;
    Encrypter(vector<char>& keys, vector<string>& values, vector<string>& words){
        enc.clear();
        dec.clear();
        for(int i=0;i<keys.size();i++){
            enc[keys[i]]=values[i];
        }
        for(auto &w:words){
            dec[encrypt(w)]++;
        }
    }
    
    string encrypt(string word1) {
        string ans;
        for(auto w:word1){
            if(!enc.count(w))
                return "";
            ans+=enc[w];
        }
        return ans;
    }
    
    int decrypt(string word2) {
        return dec[word2];
    }
};

/**
 * Your Encrypter object will be instantiated and called as such:
 * Encrypter* obj = new Encrypter(keys, values, dictionary);
 * string param_1 = obj->encrypt(word1);
 * int param_2 = obj->decrypt(word2);
 */