class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        st.push(0);
        for(char c:s){
            if(c=='('){
                st.push(0);
            }
            else{
                int val=0;
                int tmp=st.top();
                st.pop();
                if(tmp>0)
                    val=tmp*2;
                else
                    val=1;
                st.top()+=val;
            }
        }
        return st.top();
    }
};