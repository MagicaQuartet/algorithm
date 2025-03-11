#include<cstdio>
#include<cstring>
#define Q 9999991
#define ll long long
using namespace std;
int T, N, M;
int dp[126][126];
int get_dp(int x, int y) {
    if (x == -1 || y == -1) {
        return 0;
    }
    if (dp[x][y] != -1) {
        return dp[x][y];
    }
    if (x > y) {
        return dp[x][y] = get_dp(y, x);
    }
    int ret = (get_dp(x - 1, y) + get_dp(x, y - 1)) % Q;
    for (int i = 0; i <= x - 1; i++) {
        for (int j = 0; j <= y - 1; j++) {
            ret = (ret + ((ll)get_dp(i, j) * get_dp(x - 1 - i, y - 1 - j))) % Q;
        }
    }
    return dp[x][y] = ret;
}
int main() {
    scanf("%d", &T);
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 1;
    dp[1][0] = 1;
    dp[0][1] = 1;
    while (T--) {
        scanf("%d %d", &N, &M);
        printf("%d\n", get_dp(M, N));
    }
}
