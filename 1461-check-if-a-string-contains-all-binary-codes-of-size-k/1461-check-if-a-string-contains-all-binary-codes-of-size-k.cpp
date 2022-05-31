class Solution {
public:
    
    
    bool hasAllCodes(string s, int k) {
        if(k>s.size())
            return false;
        set<string> st;
        for(int i=0;i<s.size()-k+1;i++){
            string aa=s.substr(i,k);
            // cout<<aa<<" ";
            st.insert(aa);
        }
        if(st.size()==pow(2,k))
            return true;
        return false;
    }
};