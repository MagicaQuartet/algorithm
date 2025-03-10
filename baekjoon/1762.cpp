#include<cstdio>
#include<vector>
#include<set>
#include<utility>
using namespace std;
int N, M;
int main() {
    scanf("%d %d", &N, &M);
    vector<set<int>> graph = vector<set<int>>(N + 1);
    vector<pair<int, int>> e = vector<pair<int, int>>(M + 1);
    for (int i = 0; i < M; i++) {
        int p, q, tmp;
        scanf("%d %d", &p, &q);
        if (p > q) {
            tmp = p;
            p = q;
            q = tmp;
        }
        graph[p].insert(q);
        e.push_back(make_pair(p, q));
    }
    int ans = 0;
    for (auto pr : e) {
        int p = pr.first;
        int q = pr.second;
        int tmp;
        if (graph[p].size() > graph[q].size()) {
            tmp = p;
            p = q;
            q = tmp;
        }
        for (auto x : graph[p]) {
            if (graph[q].find(x) != graph[q].end()) {
                ans++;
            }
        }
    }
    printf("%d\n", ans);
}
