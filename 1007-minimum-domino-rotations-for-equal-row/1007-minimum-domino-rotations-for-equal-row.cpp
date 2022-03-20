class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        vector<int> vc(7,0);
        for(int i=0;i<tops.size();i++){
            vc[tops[i]] +=1;
            vc[bottoms[i]] +=1;
        }
        int count=0;
        int n=tops.size();
        int no=-1;
        for(int i=1;i<=6;i++){
            if(vc[i]>=n){
                no=i;
                break;
            }
        }
        if(no==-1)
            return no;
        for(int i=0;i<n;i++){
            if(tops[i]!=no && bottoms[i]!=no){
                return -1;
            }
            if(tops[i]!=no && bottoms[i]==no){
                count++;
            }
        }
        int count2=0;
        for(int i=0;i<n;i++){
            if(tops[i]!=no && bottoms[i]!=no){
                break;
            }
            if(tops[i]==no && bottoms[i]!=no){
                count2++;
            }
        }
        return min(count,count2);
    }
};