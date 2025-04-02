#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
#define MAX 30000
#define A 1<<0
#define B 1<<1
#define C 1<<2
#define D 1<<3
#define ALL (A|B|C|D)
using namespace std;
int T, N, W;
int enemy[20010];
int dp[10010][4];
int solve(int idx, int offset, int last_mode) {
    int mode = 1 << offset;
    if (idx == N) {
        if (!(mode & last_mode)) {
            return MAX;
        }
        if (mode & D) {
            return 0;
        }
        if (mode & (B | C)) {
            return 1;
        }
        if (mode & A) {
            return (last_mode == ALL && enemy[idx] + enemy[idx + N] <= W) ? 1 : 2;
        }
        return MAX;
    }
    if (dp[idx][offset] != -1) {
        return dp[idx][offset];
    }
    int ret = MAX;
    switch (mode) {
    case A:
        ret = (enemy[idx] + enemy[idx + N] <= W ? 1 : 2) + solve(idx + 1, 0, last_mode);
        if (enemy[idx] + enemy[idx + 1] <= W && enemy[idx + N] + enemy[idx + N + 1] <= W) {
            ret = min(ret, 2 + solve(idx + 1, 3, last_mode));
        }
        if (enemy[idx] + enemy[idx + 1] <= W) {
            ret = min(ret, 2 + solve(idx + 1, 2, last_mode));
        }
        if (enemy[idx + N] + enemy[idx + N + 1] <= W) {
            ret = min(ret, 2 + solve(idx + 1, 1, last_mode));
        }
        break;
    case B:
        ret = 1 + solve(idx + 1, 0, last_mode);
        if (enemy[idx] + enemy[idx + 1] <= W) {
            ret = min(ret, 1 + solve(idx + 1, 2, last_mode));
        }
        break;
    case C:
        ret = 1 + solve(idx + 1, 0, last_mode);
        if (enemy[idx + N] + enemy[idx + N + 1] <= W) {
            ret = min(ret, 1 + solve(idx + 1, 1, last_mode));
        }
        break;
    case D:
        ret = solve(idx + 1, 0, last_mode);
        break;
    }
    return dp[idx][offset] = ret;
}
int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &N, &W);
        for (int i = 1; i <= 2 * N; i++) {
            scanf("%d", enemy + i);
        }
        memset(dp, -1, sizeof(dp));
        int ans = solve(1, 0, ALL);
        if (N >= 3) {
            if (enemy[1] + enemy[N] <= W && enemy[N + 1] + enemy[2 * N] <= W) {
                memset(dp, -1, sizeof(dp));
                ans = min(ans, solve(1, 3, A));
            }
            if (enemy[N + 1] + enemy[2 * N] <= W) {
                memset(dp, -1, sizeof(dp));
                ans = min(ans, solve(1, 1, A | C));
            }
            if (enemy[1] + enemy[N] <= W) {
                memset(dp, -1, sizeof(dp));
                ans = min(ans, solve(1, 2, A | B));
            }
        }
        printf("%d\n", ans);
    }
}
