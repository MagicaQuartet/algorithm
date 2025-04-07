#include<iostream>
#include<string>
#include<vector>
#define ll long long
#define Q 1000003
#define vvll vector<vector<ll>>
using namespace std;
int N, S, E;
ll T;
vvll mul(vvll& a, vvll& b) {
    vvll ret(5 * N, vector<ll>(5 * N, 0));
    for (int i = 0; i < 5 * N; i++) {
        for (int j = 0; j < 5 * N; j++) {
            for (int k = 0; k < 5 * N; k++) {
                ret[i][j] = (ret[i][j] + a[i][k] * b[k][j]) % Q;
            }
        }
    }
    return ret;
}
vvll solve(vvll& orig, ll t) {
    if (t == 1) {
        return orig;
    }
    vvll _ret = solve(orig, t / 2);
    vvll ret = mul(_ret, _ret);
    if (t % 2) {
        ret = mul(ret, orig);
    }
    return ret;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N >> S >> E >> T;
    vvll graph(5 * N, vector<ll>(5 * N, 0));
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < N; j++) {
            int dist = s[j] - '0';
            if (dist > 1) {
                graph[5 * i][5 * i + 1] = 1;
                for (int d = 2; d < dist; d++) {
                    graph[5 * i + d - 1][5 * i + d] = 1;
                }
                graph[5 * i + dist - 1][5 * j] = 1;
            }
            else {
                graph[5 * i][5 * j] = dist;
            }
        }
    }
    vvll ans = solve(graph, T);
    cout << ans[5 * (S - 1)][5 * (E - 1)] << "\n";
}
