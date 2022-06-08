class Solution {
public:
    
    bool ispali(string s){
        int i=0,j=s.size()-1;
        while(i<j){
            if(s[i]!=s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    
    int removePalindromeSub(string s) {
        if(ispali(s))
            return 1;
        return 2;
    }
};