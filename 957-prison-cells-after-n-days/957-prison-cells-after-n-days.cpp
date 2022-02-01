class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int n) {
        // int n=cells.size();
        vector<string>v;
        string las;
        
        for(int i=0;i<cells.size();i++)las+=to_string(cells[i]);
        
        unordered_map<string,int>mp;
        
        while(!mp.count(las)){
            
            mp[las]=v.size();
            v.push_back(las);
            
            string nlas;
            for(int i=0;i<cells.size();i++){
                if(i==0 or i==cells.size()-1){
                    nlas+='0';
                }else{
                    if(las[i-1] ==las[i+1]){
                        nlas+='1';
                    }else{
                        nlas+='0';
                    }
                }
            }
            las=nlas;
        }
        int idx=mp[las];
        
        if(n<idx){
           las=v[n];
        }
       else las=v[idx+((n-idx)%(v.size()-idx))];
        
        vector<int>output;
        for(int i=0;i<las.length();i++){
            if(las[i]=='1'){
                output.push_back(1);
            }else{
                output.push_back(0);
            }
        }
        
        return output;
    }
};