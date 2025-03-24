#include<cstdio>
#include<vector>
using namespace std;
int N, R, Q;
int cnt[100010], visited[100010];
int get_cnt(vector<vector<int>>& graph, int n) {
    visited[n] = 1;
    int ans = 0;
    for (auto child : graph[n]) {
        if (visited[child]) {
            continue;
        }
        ans += get_cnt(graph, child);
    }
    return cnt[n] = ans + 1;
}
int main() {
    scanf("%d %d %d", &N, &R, &Q);
    vector<vector<int>> graph(N + 1, vector<int>());
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        cnt[u] = cnt[v] = 0;
        visited[u] = visited[v] = 0;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    get_cnt(graph, R);
    for (int i = 0; i < Q; i++) {
        int q;
        scanf("%d", &q);
        printf("%d\n", cnt[q]);
    }
}