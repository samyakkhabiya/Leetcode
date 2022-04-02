class Solution {
public:
    long long dp[3][100001][4];
    
    long long solve(string& s, int last,int index,int cnt){
        if(cnt==3)
            return 1;
        if(dp[last][index][cnt]!=-1)
            return dp[last][index][cnt];
        if(index>=s.size() || cnt>3)
            return 0;
        long long a=0,b=0;
        if(s[index]-'0' != last)
            a=solve(s,s[index]-'0',index+1,cnt+1);
        b=solve(s,last,index+1,cnt);
        return dp[last][index][cnt]=a+b;
    }
    
    long long numberOfWays(string s) {
        memset(dp,-1,sizeof(dp));
        return solve(s,2,0,0);
    }
};