class Solution {
public:
    string getSmallestString(int n, int k) {
        vector<int> vc(27,0);
        string s;
        for(int i=0;i<n;i++)
            s+='a';
        k -=n;
        int j=n-1;
        while(k>0){
            if(k-26>=0){
                s[j]='z';
                j--;
                k -=25;
            }
            else{
                // cout<<k<<" "<<char(k+'a')<<endl;
                s[j]=char(k+'a');
                break;
            }
        }
        return s;
    }
};