class Solution {
    int sumDigit(int n){
        int sm = 0;
        while(n){
            sm += n%10;
            n /= 10;
        }
        return sm;
    }
public:
    int countEven(int num) {
        int cnt = 0;
        for(int i=2; i<=num; i++){
            if(sumDigit(i)%2==0)
                cnt++;
        }
        return cnt;
    }
};