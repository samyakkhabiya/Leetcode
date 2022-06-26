class Solution {
public:
    int maxScore(vector<int>& card, int k) {
        int ssum=0,esum=0,fsum=0;
        int kc=k;
        int n=card.size();
        for(int i=0;i<k && i<card.size();i++)
            ssum+=card[i];
        for(int i=n-1;i>=0 && kc-- ;i--){
            fsum=max(fsum,ssum+esum);
            ssum-=card[--k];
            esum+=card[i];
        }
        fsum=max(fsum,ssum+esum);
        return fsum;
    }
};