class Solution {
private:
    bool isPossible(int mid,string s,int k){
        int T=0,F=0;
        
        for(int i=0;i<mid;i++){
            if(s[i]=='T') T++;
            else F++;
        }
        if(min(T,F)<=k) return true;
        
        for(int i=mid;i<s.size();i++){
            if(s[i]=='T') T++;
            else F++;
            
            if(s[i-mid]=='T') T--;
            else F--;
        
            if(min(T,F)<=k) {return true;break;}
            
        }
        
        return false;
    }
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n=answerKey.size();
        
        int lo=0;
        int hi=n;
        int ans=0;
        
        while(lo<=hi){
            
            int mid=lo+(hi-lo)/2;
     
            if(isPossible(mid,answerKey,k)){
                ans=mid;
                lo=mid+1;
            }
            else hi=mid-1;
        }
        
        return ans;
    }
};