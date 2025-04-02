#include<cstdio>
#include<cstring>
#include<vector>
#define ll long long
#define vll vector<ll>
#define vvll vector<vll>
#define Q 1000000007
using namespace std;
int n, m;
ll D;
vvll orig_graph;
vvll mul(vvll a, vvll b) {
    vvll ret(n, vll(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ll num = 0;
            for (int k = 0; k < n; k++) {
                num = (num + (a[i][k] * b[k][j]) % Q) % Q;
            }
            ret[i][j] = num;
        }
    }
    return ret;
}
vvll solve(ll n) {
    if (n == 1) {
        return orig_graph;
    }
    vvll ret = solve(n / 2);
    vvll retmul = mul(ret, ret);
    if (n % 2) {
        retmul = mul(retmul, solve(1));
    }
    return retmul;
}
int main() {
    scanf("%d %d", &n, &m);
    orig_graph = vvll(n, vll(n, 0));
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        orig_graph[a - 1][b - 1] = orig_graph[b - 1][a - 1] = 1;
    }
    scanf("%lld", &D);
    printf("%lld\n", solve(D)[0][0]);
}
