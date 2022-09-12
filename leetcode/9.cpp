class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        int _x = x;
        int lhs = 1;
        int rhs = 1;
        while (_x >= 10) {
            lhs *= 10;
            _x /= 10;
        }
        while (lhs / 10 >= rhs) {
            rhs *= 10;
            if ((x / lhs) % 10 != (x % rhs) / (rhs / 10)) {
                return false;
            }
            lhs /= 10;
        }
        return true;
    }
};