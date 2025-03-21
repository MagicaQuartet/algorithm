#include<cstdio>
#include<cstring>
#include<vector>
#include<map>
using namespace std;
int num;
int cost[5][5] = {
    {-1, 2, 2, 2, 2},
    {-1, 1, 3, 4, 3},
    {-1, 3, 1, 3, 4},
    {-1, 4, 3, 1, 3},
    {-1, 3, 4, 3, 1}
};
int dp[22][100010];
vector<int> seq;
map<int, int> dp_idxs;
int next_idx = 0;
int get_index(int n) {
    map<int, int>::iterator it = dp_idxs.find(n);
    if (it == dp_idxs.end()) {
        dp_idxs[n] = next_idx++;
        return next_idx - 1;
    }
    return it->second;
}
int solve(int n, int seq_idx) {
    if (seq_idx == 0) {
        return n == 0 ? 0 : -1;
    }
    if (n / 10 == n % 10) {
        return -1;
    }
    int dp_idx = get_index(n);
    if (dp[dp_idx][seq_idx] != -1) {
        return dp[dp_idx][seq_idx];
    }
    int ans = -1;
    for (int i = 0; i <= 4; i++) {
        for (int j = 0; j <= 4; j++) {
            if (i != 0 && i == j) {
                continue;
            }
            if (i != seq[seq_idx - 1] && j != seq[seq_idx - 1]) {
                continue;
            }
            // case 1. move left
            if (j == n % 10) {
                int lhs = solve(10 * i + j, seq_idx - 1);
                if (lhs != -1 && cost[i][n / 10] != -1) {
                    if (ans == -1 || ans > lhs + cost[i][n / 10]) {
                        ans = lhs + cost[i][n / 10];
                    }
                }
            }
            // case 2. move right
            if (i == n / 10) {
                int rhs = solve(10 * i + j, seq_idx - 1);
                if (rhs != -1 && cost[j][n % 10] != -1) {
                    if (ans == -1 || ans > rhs + cost[j][n % 10]) {
                        ans = rhs + cost[j][n % 10];
                    }
                }
            }
        }
    }
    return dp[dp_idx][seq_idx] = ans;
}
int main() {
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;
    seq.push_back(0);
    while (1) {
        scanf("%d", &num);
        if (num == 0) {
            break;
        }
        seq.push_back(num);
    }
    int ans = -1;
    for (int i = 0; i <= 4; i++) {
        for (int j = 0; j <= 4; j++) {
            if (i != 0 && i == j) {
                continue;
            }
            if (i != seq.back() && j != seq.back()) {
                continue;
            }
            int _ans = solve(10 * i + j, seq.size() - 1);
            if (_ans != -1 && (ans == -1 || ans > _ans)) {
                ans = _ans;
            }
        }
    }
    printf("%d\n", ans);
}