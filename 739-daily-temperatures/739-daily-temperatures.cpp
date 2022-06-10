class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        stack<pair<int,int>> st;
        int n=temp.size();
        vector<int> post(n);
        for(int i=n-1;i>=0;i--){
            if(st.empty()){
                post[i]=0;
            }
            else{
                while(!st.empty() and temp[i]>=st.top().first){
                    st.pop();
                }
                if(st.empty())
                    post[i]=0;
                else
                    post[i]=st.top().second-i;
            }
            st.push({temp[i],i});
        }
        return post;
    }
};