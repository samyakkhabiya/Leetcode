class Solution {
public:
    int ans=0;
    vector<int> used;
    void dfs(int i, int n){
        if(i>n){
            ans++;
            return;
        }
        
        for(int j=1;j<=n;j++){
            if(used[j]==0 and (j%i==0 or i%j==0)){
                used[j]=1;
                dfs(i+1,n);
                used[j]=0;
            }
        }
    }
    
    int countArrangement(int n) {
        if(n==0)
            return n;
        used.resize(n+1,0);
        dfs(1,n);
        return ans;
    }
};