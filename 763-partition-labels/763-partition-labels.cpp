class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> vc(26,0);
        for(int i=0;i<s.size();i++){
            vc[s[i]-'a'] =i;
        }
        int ans=0;
        int last=0;
        vector<int> fans;
        int ma=INT_MIN;
        for(int i=0;i<s.size();i++){
            ma=max(ma,vc[s[i]-'a']);
            if(ma==i){
                // if(fans.size()==0)
                //     fans.push_back(i+1);
                // else
                //     fans.push_back(i-fans[fans.size()-1]+1);
                if(fans.size()==0){
                    fans.push_back(i+1);
                    last=i;
                }
                else{
                    fans.push_back(i-last);
                    last=i;
                }
            }
        }
        return fans;
    }
};