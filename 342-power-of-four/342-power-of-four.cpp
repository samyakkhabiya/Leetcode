class Solution {
public:
    bool isPowerOfFour(int num) {
        if (num <= 0) return false;
        if (num & num - 1) return false;
        return num % 3 == 1;
    }
};