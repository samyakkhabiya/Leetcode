class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n=seats.size();
        int left[n];
        int right[n];
        memset(left,0,sizeof(left));
        memset(right,0,sizeof(right));
        int lmax=0,rmax=n;
        bool t=true;
        for(int i=0;i<n;i++){
            if(seats[i]==1){
                left[i]==0;
                lmax=i;
                t=false;
            }
            else{
                if(t)
                    left[i]=INT_MAX;
                else
                    left[i]=i-lmax;
            }
        }
        t=true;
        for(int i=n-1;i>=0;i--){
            if(seats[i]==1){
                right[i]==0;
                rmax=i;
                t=false;
            }
            else{
                if(t)
                    right[i]=INT_MAX;
                else
                    right[i]=rmax-i;
            }
        }
        int ans,fans=INT_MIN;
        for(int i=0;i<n;i++){
            ans=min(left[i],right[i]);
            fans=max(fans,ans);
        }
        return fans;
    }
};