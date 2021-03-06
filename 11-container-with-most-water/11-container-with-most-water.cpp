class Solution {
public:
    int maxArea(vector<int>& h) {
        int ans=0;
      int strt=0,end=h.size()-1;
        while(strt<end){
          
          ans=max(ans,min(h[strt],h[end])*(end-strt));
          
          if(h[strt]<h[end])
            strt++;
          
          else
            end--;
        }
      return ans;
      
    }
};