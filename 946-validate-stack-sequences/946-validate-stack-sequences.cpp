class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int k=0;
        int n=pushed.size();
        stack<int> s;
        int i;
        for(i=0;i<n;i++){
            s.push(pushed[i]);
            while(!s.empty()){
                if(s.top()==popped[k]){
                    k++;
                    s.pop();
                }
                else
                    break;
            }
        }
        // cout<<s.empty()<<" "<<i<<" "<<k<<endl;
        if(s.empty() && i==n && k==n)
            return true;
        return false;
    }
};