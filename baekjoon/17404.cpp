#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAX 1000010
using namespace std;
int N;
int dp[1010][3][3];
int cost[1010][3];
int solve(int n, int mode, int start) {
    if (n <= 0) {
        return 0;
    }
    if (n == 1 && mode == start) {
        return MAX;
    }
    if (dp[n][mode][start] != -1) {
        return dp[n][mode][start];
    }
    int ret1 = solve(n - 1, (mode + 1) % 3, start);
    int ret2 = solve(n - 1, (mode + 2) % 3, start);
    return dp[n][mode][start] = min(ret1, ret2) + cost[n][mode];
}
int main() {
    scanf("%d", &N);
    memset(dp, -1, sizeof(dp));
    for (int i = 1; i <= N; i++) {
        scanf("%d %d %d", &cost[i][0], &cost[i][1], &cost[i][2]);
    }
    int ret1 = solve(N, 0, 0);
    int ret2 = solve(N, 1, 1);
    int ret3 = solve(N, 2, 2);
    printf("%d\n", min(ret1, min(ret2, ret3)));
}