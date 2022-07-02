class Solution {
public:
    int mod=1e9 + 7;
    int maxArea(int h, int w, vector<int>& ho, vector<int>& v) {
        sort(ho.begin(),ho.end());
        sort(v.begin(),v.end());
        long maxa=max(ho[0],h-ho.back());
        long maxb=max(v[0],w-v.back());
        for(int i=1;i<ho.size();i++){
            maxa=max(maxa,(long)ho[i]-ho[i-1]);
        }
        for(int i=1;i<v.size();i++){
            maxb=max(maxb,(long)v[i]-v[i-1]);
        }
        return ((maxa%mod) * (maxb%mod))%mod;
    }
};