class Solution {
public:
    
    bool solve(int arr[]){
        for(int i=0;i<26;i++){
            if(arr[i]!=0)
                return false;
        }
        return true;
    }
    
    bool checkInclusion(string s1, string s2) {
        int count[26]={0};
        // set<char> se;
        if(s1.size()>s2.size())
            return false;
        int n=s1.size();
        
        for(int i=0;i<n;i++){
            count[s1[i]-'a']++;
            count[s2[i]-'a']--;
        }
        if(solve(count))
            return true;
        for(int i=n;i<s2.size();i++){
            count[s2[i]-'a']--;
            count[s2[i-n]-'a']++;
            if(solve(count))
                return true;
        }
        
        return false;
    }
};