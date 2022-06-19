class Solution {
public:
    vector<int> temp;
    vector<vector<int>> ans;
    
    void dfs(int i, int n, int k){
        if(k==0){
            ans.push_back(temp);
            return;
        }
        for(int j=i;j<=n;j++){
            temp.push_back(j);
            dfs(j+1,n,k-1);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        dfs(1,n,k);
        return ans;
    }
};