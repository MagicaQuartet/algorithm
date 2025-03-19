#include<cstdio>
#define ll long long
using namespace std;
int n;
ll k;
ll concat(ll prev, int add) {
    int mul;
    if (add < 10) {
        mul = 10;
    }
    else if (add < 100) {
        mul = 100;
    }
    else if (add < 1000) {
        mul = 1000;
    }
    else if (add < 10000) {
        mul = 10000;
    }
    else if (add < 100000) {
        mul = 100000;
    }
    else {
        mul = 1000000;
    }
    return (prev * mul + add) % k;
}
int main() {
    scanf("%d %lld", &n, &k);
    ll num = 0;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        num = concat(num, i);
        if (num == 0) {
            ans++;
        }
    }
    printf("%d\n", ans);
}
