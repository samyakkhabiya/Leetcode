// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int CountPS(char S[], int N);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        char S[N+1];
        cin>>S;
        cout<<CountPS(S,N)<<endl;
    }
    return 0;
}

// } Driver Code Ends



int dp[501][501];

bool dfs(string &s, int i, int j){
    if(i>j)
        return 1;
    if(dp[i][j]!=-1)
        return dp[i][j];
    if(s[i]!=s[j])
        return dp[i][j]=0;
        
    return dp[i][j]=dfs(s,i+1,j-1);
}

int CountPS(char S[], int N)
{
    //code here
    string s="";
    for(int i=0;i<N;i++)
        s+=S[i];
        
    int ans=0;
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            if(dfs(s,i,j))
                ans++;
        }
    }
    return ans;
    
    
}