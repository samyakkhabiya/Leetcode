class Solution {
public:
    string decodeCiphertext(string encodedText, int n) {
        int m=encodedText.length()/n;
        string s="";
        for(int j=0;j<m;j++){
            for(int i=0;i+j<m && i<n;i++){
                s+= encodedText[i*m+i+j];
            }
        }
        while(s.size() && s.back()==' ') s.pop_back();
        return s;
    }
};