class Solution {
public:
    string convertToTitle(int n) {
        string ans;
        char temp;
        while(n>0){
            n-=1;
            temp = 'A' + (n%26);
            ans=temp+ans;
            n /=26;
        }
        return ans;
    }
};