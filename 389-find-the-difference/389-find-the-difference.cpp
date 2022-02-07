class Solution {
public:
    char findTheDifference(string s, string t) {
        int sum=0;
        for(int i=0;i<s.size();i++){
            sum+=t[i];
            sum-=s[i];
        }
        sum+=t[t.size()-1];
        return char(sum);
    }
};