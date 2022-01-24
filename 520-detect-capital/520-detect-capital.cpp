class Solution {
public:
    bool detectCapitalUse(string s) {
        bool iscap=false,islow=false,isfirst=false;
            if(isupper(s[0])){
                isfirst=true;
                iscap=true;
            }
            else
                islow = true;
        
        if(iscap && isfirst){
                for(int i=1;i<s.size();i++){
                    if(isupper(s[i])){
                        isfirst=false;
                    }
                    else{
                        iscap=false;
                    }
                }
        }
        else if(islow){
            for(int i=1;i<s.size();i++){
                    if(isupper(s[i])){
                        islow=false;
                    }
                    
                }
        }
        return islow || iscap || isfirst;
        
    }
};