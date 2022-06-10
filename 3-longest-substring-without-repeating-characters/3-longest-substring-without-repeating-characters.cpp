class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0,j=0,n=s.size();
        int ma=INT_MIN;
        unordered_map<int,int> ump;
        while(i<n and j<n){
            if(i==j)
                ump.clear();
            if(ump.count(s[j])){
                ma=max(ma,j-i);
                if(ump[s[i]]>1)
                    ump[s[i]]--;
                else
                    ump.erase(s[i]);
                i++;
                continue;
            }
            ump[s[j]]++;
            j++;
        }
        ma=max(ma,j-i);
        return ma;
    }
};