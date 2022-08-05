class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int ump[2001]={0};
        bool mp[2001]={false};
        for(int i=0;i<arr.size();i++){
            if(arr[i]<0){
                ump[arr[i]+2000]++;
            }
            else
                ump[arr[i]]++;
        }
        for(int i=0;i<2001;i++){
            if(mp[ump[i]]==true)
                return false;
            if(ump[i]!=0)
                mp[ump[i]]=true;
        }
        return true;
    }
};