class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_set<string> st;
        unordered_map<char,string> ump;
        vector<string> temp={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        char c='a';
        for(auto i:temp){
            ump[c]=i;
            // cout<<c<<" "<<ump[c]<<endl;
            c++;
        }
        for(auto i:words){
            string ans;
            for(auto j:i){
                ans+=ump[j];
            }
            st.insert(ans);
        }
        return st.size();
    }
};