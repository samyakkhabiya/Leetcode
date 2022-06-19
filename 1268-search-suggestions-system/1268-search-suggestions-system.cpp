class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string search) {
        sort(products.begin(),products.end());
        string sea;
        vector<vector<string>> ans;
        for(int z=0;z<search.size();z++){
            sea+=search[z];
            vector<string> temp;
            bool ch=true;
            int k=3;
            for(auto s:products){
                
                string f=s.substr(0,sea.size());
                if(f==sea){
                    temp.push_back(s);
                    k--;
                    // cout<<s<<" ";
                }
                if(k==0){
                    ch=false;
                    ans.push_back(temp);
                    break;
                }
            }
            if(ch)
                ans.push_back(temp);
        }
        return ans;
    }
};