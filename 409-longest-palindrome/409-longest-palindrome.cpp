class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> ump;
        int sum=0;
        int m=INT_MAX;
        bool f=false;
        for(auto i:s)
            ump[i]++;
        for(auto i:ump){
            if(i.second%2==0)
                sum+=i.second;
            else{
                sum+=i.second-1;
                f=true;
            }
        }
        if(f)
            sum+=1;
        return sum;
    }
};