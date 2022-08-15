class Solution {
private:
    bool i, x, c;
public:
    void reset(bool _i, bool _x, bool _c) {
        i = _i;
        x = _x;
        c = _c;
    }
    
    int romanToInt(string s) {
        i = false;
        x = false;
        c = false;
        int sum = 0;
        for (auto num: s) {
            switch (num) {
                case 'I':
                    sum += 1;
                    reset(true, false, false);
                    break;
                case 'V':
                    sum += 5;
                    if (i) {
                        sum -= 2;
                    }
                    reset(false, false, false);
                    break;
                case 'X':
                    sum += 10;
                    if (i) {
                        sum -= 2;
                    }
                    reset(false, true, false);
                    break;
                case 'L':
                    sum += 50;
                    if (x) {
                        sum -= 20;
                    }
                    reset(false, false, false);
                    break;
                case 'C':
                    sum += 100;
                    if (x) {
                        sum -= 20;
                    }
                    reset(false, false, true);
                    break;
                case 'D':
                    sum += 500;
                    if (c) {
                        sum -= 200;
                    }
                    reset(false, false, false);
                    break;
                case 'M':
                    sum += 1000;
                    if (c) {
                        sum -= 200;
                    }
                    reset(false, false, false);
                    break;
            }
        }
        return sum;
    }
};