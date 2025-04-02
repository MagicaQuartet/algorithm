#include<cstdio>
#include<cstring>
#define ll long long
using namespace std;
ll A, B;
ll cnt[60];
ll get_cnt(int idx) {
    if (cnt[idx] != -1) {
        return cnt[idx];
    }
    if (idx <= 0) {
        return cnt[idx] = 1;
    }
    return cnt[idx] = ((ll)1 << idx) + 2*get_cnt(idx-1);
}
ll solve(ll a) {
    if (a <= 0) {
        return 0;
    }
    if (a == 1) {
        return 1;
    }
    ll offset = 0;
    while ((ll)1 << (offset+1) <= a) {
        offset++;
    }
    ll head = (ll)1 << offset;
    return (a-head+1) + solve(a-head) + get_cnt(offset-1);
}
int main() {
    scanf("%lld %lld", &A, &B);
    memset(cnt, -1, sizeof(cnt));
    printf("%lld\n", solve(B) - solve(A-1));
}