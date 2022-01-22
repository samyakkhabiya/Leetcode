class Solution {
public:
    int numberOfArrays(vector<int>& diff, int lower, int upper) {
        long long int minDiff=0, maxDiff=0, val=0, start, end;
        for(int d : diff)
        {
            val+=d;
            minDiff = min(minDiff, val);
            maxDiff = max(maxDiff, val);
            
        }

        int cnt=0;
        for(int i=lower; i<=upper; i++)
        {
            start = i+minDiff;
            end = i+maxDiff;
            if(start>=lower and end<=upper)
                cnt++;
        }
        return cnt;
    }
};