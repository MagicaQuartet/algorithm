#include<cstdio>
#include<cstring>
#include<vector>
#define ll long long
using namespace std;
ll N;
ll len_cnt[11][10];
int get_len(ll n) {
    int len = 1;
    while (n >= 10) {
        len++;
        n /= 10;
    }
    return len;
}
ll pow(ll num, int cnt) {
    ll ret = 1;
    while (cnt--) {
        ret *= num;
    }
    return ret;
}
ll get_cnt(int len, int num) {
    if (len == 0) {
        return len_cnt[len][num] = 0;
    }
    if (len == 1) {
        return len_cnt[len][num] = 1;
    }
    if (len_cnt[len][num] != -1) {
        return len_cnt[len][num];
    }
    return len_cnt[len][num] = pow(10, len - 1) + 10 * get_cnt(len - 1, num);
}
void solve(vector<ll>& ans, ll n, int len) {
    if (len == 0) {
        return;
    }
    ll unit = pow(10, len - 1);
    // 1. 맨 앞 글자
    int head = n / unit;
    ans[head] += n - unit * head + 1;
    // 1-1. 맨 앞 글자 이후의 숫자
    solve(ans, n - unit * head, len - 1);
    // 2. 자릿 수는 같은데 맨 앞 숫자가 더 작은 숫자
    for (int i = head - 1; i >= 0; i--) {
        ans[i] += unit;
        // 2-1. 맨 앞 글자 이후의 숫자
        for (int i = 0; i < 10; i++) {
            ans[i] += get_cnt(len - 1, i);
        }
    }
    // 잘못 더해졌을 0 횟수 차감
    ans[0] -= unit;
}
int main() {
    scanf("%lld", &N);
    memset(len_cnt, -1, sizeof(len_cnt));
    vector<ll> ans(10, 0);
    solve(ans, N, get_len(N));
    for (int i = 0; i < 10; i++) {
        printf("%lld ", ans[i]);
    }
    printf("\n");
}
