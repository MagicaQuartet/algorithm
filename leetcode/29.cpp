class Solution {
public:
    int divide(int dividend, int divisor) {
        int ddsign = dividend > 0 ? 1 : -1;
        int dssign = divisor > 0 ? 1 : -1;
        long long ldd = (long long)dividend * ddsign;
        long long lds = (long long)divisor * dssign;
        long long ans = 0;
        vector<long long> exp;
        exp.push_back(1);
        for (int i = 1;;i++) {
            long long elem = exp[i - 1] * lds;
            if (elem > ldd || elem < -ldd) {
                break;
            }
            exp.push_back(elem);
            if (divisor == 1 || divisor == -1) {
                break;
            }
        }
        for (int i = exp.size() - 1; i >= 1; i--) {
            if (ldd < lds) {
                break;
            }
            ans += (ldd / exp[i]) * exp[i - 1];
            ldd -= (ldd / exp[i]) * exp[i];
        }
        if (ans >= ((long long)1 << 31) && ddsign * dssign == 1) {
            ans = ((long long)1 << 31) - 1;
        }
        return ans * ddsign * dssign;
    }
};