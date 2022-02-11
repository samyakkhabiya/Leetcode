class Solution {
public:
    bool isvo(char x){
        if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u')
            return true;
        return false;
    }
    
    int maxVowels(string s, int k) {
        int count=0,ans=0;
        for(int i=0;i<k;i++){
            if(isvo(s[i]))
                count++;
        }
        ans=max(ans,count);
        for(int i=k;i<s.size();i++){
            if(isvo(s[i]))
                count++;
            if(isvo(s[i-k]))
                count--;
            ans=max(ans,count);
        }
        return ans;
    }
};