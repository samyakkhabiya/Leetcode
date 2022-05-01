class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i=s.size()-1;
        int j=t.size()-1;
        int cnt=0;
        string a="";
        string b="";
        while(i>=0){
            bool z=true;
            bool z2=true;
            while(i>=0 and cnt and s[i]!='#'){
                cnt--;
                i--;
                z=false;
            }
            while(i>=0 and s[i]=='#'){
                i--;
                cnt++;
                z2=false;
            }
            if(i>=0 and z2 and z){
                a+=s[i];
                i--;
            }
            // i--;
        }
        reverse(a.begin(),a.end());
        // cout<<a<<endl;
        cnt=0;
        i=t.size()-1;
        while(i>=0){
            bool z=true;
            bool z2=true;
            while(i>=0 and cnt and t[i]!='#'){
                cnt--;
                i--;
                z=false;
            }
            while(i>=0 and t[i]=='#'){
                i--;
                cnt++;
                z2=false;
            }
            if(i>=0 and z2 and z){
                b+=t[i];
                i--;
            }
        }
        reverse(b.begin(),b.end());
        // cout<<b<<endl;
        return a==b;
    }
};