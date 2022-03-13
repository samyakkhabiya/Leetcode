class Solution {
public:
    bool isValid(string S) {
        stack<char>s;
    for(int l=0;l<S.size();l++){
        if(S[l]=='(' || S[l]=='[' || S[l]=='{')
        {
            s.push(S[l]);
        }
        else{
            if(s.size()==0){
                return 0;
            }
        if(S[l]==')' && s.top()!='(' ){
            return 0;
        }   
          else  if(S[l]==']' && s.top()!='[' ){
            return 0;
        } 
           else if(S[l]=='}' && s.top()!='{' ){
            return 0;
        }
            s.pop();
        }
        
    }
    if(s.size()==0){
return 1;
}
return 0;
    }
};