class Solution {
public:
    int count(int n){
        int sum=0;
        while(n>0){
            if(n&1)
                sum++;
            n=n>>1;
        }
        return sum;
    }
    vector<int> countBits(int n) {
        vector<int> ans(n+1);
        for(int i=0;i<n+1;i++){
            ans[i]=count(i);
        }
        return ans;
    }
};