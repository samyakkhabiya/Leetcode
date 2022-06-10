class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        int n=nums2.size();
        int post[n];
        for(int i=n-1;i>=0;i--){
            if(st.empty()){
                post[i]=0;
            }
            else{
                while(!st.empty() and nums2[i]>=st.top()){
                    st.pop();
                }
                if(st.empty())
                    post[i]=0;
                else
                    post[i]=st.top();
            }
            st.push(nums2[i]);
        }
        unordered_map<int,int> ump;
        for(int i=0;i<n;i++)
            ump[nums2[i]]=i;
        vector<int> ans(nums1.size());
        for(int i=0;i<nums1.size();i++){
            ans[i]=post[ump[nums1[i]]];
            if(ans[i]==0)
                ans[i]=-1;
        }
        return ans;
    }
};