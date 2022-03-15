class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string ans;
        stack<char> st;
        for(int i=0;i<s.size();i++){
            if(s[i]==')'){
                if(st.empty())
                    continue;
                st.pop();
            }
            ans+=s[i];
            if(s[i]=='(')
                st.push(s[i]);
        }
        // cout<<ans<<endl;
        if(st.empty())
            return ans;
        string fans;
        int j=ans.size()-1;
        for(int j=ans.size()-1;j>=0;j--){
            if(ans[j]=='('){
                if(!st.empty()){
                    st.pop();
                    continue;
                }
            }
            fans+=ans[j];
        }
        reverse(fans.begin(),fans.end());
        return fans;
    }
};