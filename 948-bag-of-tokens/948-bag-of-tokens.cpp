class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int i=0,j=tokens.size(),score=0;
        while(i<j){
            if(power>=tokens[i]){
                power-=tokens[i];
                score++;
                i++;
            }
            else{
                if(score){
                    power+=tokens[--j];
                    // j--;
                    score--;
                }
                else
                    break;
            }
        }
        for(int k=j;k<tokens.size();k++){
            if(power>=tokens[k]){
                score++;
                power-=tokens[k];
            }
        }
        return score;
        
    }
};