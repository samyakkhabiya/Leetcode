class Solution {
public:
    
    bool check(string& s, int i, int j){
        while(i<j){
            if(s[i]!=s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    
    bool validPalindrome(string s) {
        int i=0,j=s.size()-1;
        bool temp=true;
        while(i<j){
            if(s[i]!=s[j] && temp){
                temp=false;
                bool c1=check(s,i+1,j);
                bool c2=check(s,i,j-1);
                if(c1 || c2){
                    if(c1==true)
                        i++;
                    else 
                        j--;
                }
                else{
                    return false;
                }
            }
            else{
                i++;
                j--;
            }
        }
        return true;
    }
};