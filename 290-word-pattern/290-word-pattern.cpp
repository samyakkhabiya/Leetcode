class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> vc(26);
        vector<bool> vis(26,false);
        int j=0;
        s+=' ';
        string temp="";
        unordered_map<string,int> ump;
        int z=count(s.begin(),s.end(),' ');
        // cout<<z<<endl;
        if(pattern.size()!=z)
            return false;
        for(int i=0;i<s.size();i++){
            // if(j==pattern.size()){
            //     return true;
            // }
            
            
            
            if(s[i]==' '){
                cout<<temp<<" ";
                int k=pattern[j]-'a';
                if(vis[k]==false){
                    if(ump.count(temp))
                        return false;
                    ump[temp]++;
                    vc[k]=temp;
                    vis[k]=true;
                }
                else{
                    if(vc[k]!=temp)
                        return false;
                }
                j++;
                temp="";
                i++;
            }
            temp+=s[i];
            // if(j>pattern.size())
            //     return false;
        }
        // cout<<j;
        // cout<<temp;
        // int k=pattern[j]-'a';
        //         if(vis[k]==false){
        //             vc[k]=temp;
        //             vis[k]=true;
        //         }
        //         else{
        //             if(vc[k]!=temp)
        //                 return false;
        //         }
        return true;
    }
};