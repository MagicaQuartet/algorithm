class Solution {
public:
    int reverse(int x) {
        if (x == 0x80000000) {
            return 0;
        }
        int _x = x;
        if (_x < 0) {
            _x = -x;
        }
        int ret = 0;
        while (_x) {
            if (ret > 0x7fffffff / 10) {
                ret = 0;
                break;
            }
            ret *= 10;
            ret += (_x % 10);
            _x /= 10;
        }
        return x >= 0 ? ret : -ret;
    }
};