#include<cstdio>
#include<cstring>
#include<vector>
#define ll long long
#define vll vector<ll>
#define vvll vector<vll>
#define Q 1000000007
using namespace std;
ll D;
vvll mul(vvll a, vvll b) {
    vvll ret(8, vll(8, 0));
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            ll num = 0;
            for (int k = 0; k < 8; k++) {
                num = (num + (a[i][k] * b[k][j]) % Q) % Q;
            }
            ret[i][j] = num;
        }
    }
    return ret;
}
vvll solve(ll n) {
    if (n == 1) {
        return {
            {0, 1, 1, 0, 0, 0, 0, 0},
            {1, 0, 1, 1, 0, 0, 0, 0},
            {1, 1, 0, 1, 1, 0, 0, 0},
            {0, 1, 1, 0, 1, 1, 0, 0},
            {0, 0, 1, 1, 0, 1, 1, 0},
            {0, 0, 0, 1, 1, 0, 0, 1},
            {0, 0, 0, 0, 1, 0, 0, 1},
            {0, 0, 0, 0, 0, 1, 1, 0},
        };
    }
    vvll ret = solve(n / 2);
    vvll retmul = mul(ret, ret);
    if (n % 2) {
        retmul = mul(retmul, solve(1));
    }
    return retmul;
}
int main() {
    scanf("%lld", &D);
    printf("%lld\n", solve(D)[0][0]);
}
