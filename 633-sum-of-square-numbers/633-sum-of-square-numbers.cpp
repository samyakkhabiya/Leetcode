class Solution {
public:
    bool judgeSquareSum(int c) {
        long long a=0,b=sqrt(c);
        while(a<=b){
            long long x=a*a;
            long long y=b*b;
            if(x+y==c)
                return true;
            else if(x+y<c){
                a++;
            }
            else{
                b--;
            }
        }
        return false;
    }
};