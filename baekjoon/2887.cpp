#include<cstdio>
#include<vector>
#include<queue>
#include<utility>
#include<algorithm>
#include<functional>
#define ll long long
#define pii pair<int, int>
#define ppll pair<ll, pair<ll, ll>>
using namespace std;
int N;
ll xyz[100010][3];
int visited[100010];
bool cmpx(int a, int b) {
    return xyz[a][0] < xyz[b][0];
}
bool cmpy(int a, int b) {
    return xyz[a][1] < xyz[b][1];
}
bool cmpz(int a, int b) {
    return xyz[a][2] < xyz[b][2];
}
int main() {
    scanf("%d", &N);
    vector<int> sorts;
    vector<vector<pii>> graph(N + 1, vector<pii>());
    sorts.reserve(N);
    for (int i = 1; i <= N; i++) {
        scanf("%lld %lld %lld", &xyz[i][0], &xyz[i][1], &xyz[i][2]);
        sorts.push_back(i);
        visited[i] = 0;
    }

    ll mindiff = -1;
    ll mina, minb;
    // x
    sort(sorts.begin(), sorts.end(), cmpx);
    for (int i = 1; i < N; i++) {
        int idx = sorts[i];
        int prev = sorts[i - 1];
        ll diffx = abs(xyz[idx][0] - xyz[prev][0]);
        graph[idx].push_back(make_pair(diffx, prev));
        graph[prev].push_back(make_pair(diffx, idx));
        if (mindiff == -1 || diffx < mindiff) {
            mindiff = diffx;
            mina = idx;
            minb = prev;
        }
    }
    // y
    sort(sorts.begin(), sorts.end(), cmpy);
    for (int i = 1; i < N; i++) {
        int idx = sorts[i];
        int prev = sorts[i - 1];
        ll diffy = abs(xyz[idx][1] - xyz[prev][1]);
        graph[idx].push_back(make_pair(diffy, prev));
        graph[prev].push_back(make_pair(diffy, idx));
        if (mindiff == -1 || diffy < mindiff) {
            mindiff = diffy;
            mina = idx;
            minb = prev;
        }
    }
    // z
    sort(sorts.begin(), sorts.end(), cmpz);
    for (int i = 1; i < N; i++) {
        int idx = sorts[i];
        int prev = sorts[i - 1];
        ll diffz = abs(xyz[idx][2] - xyz[prev][2]);
        graph[idx].push_back(make_pair(diffz, prev));
        graph[prev].push_back(make_pair(diffz, idx));
        if (mindiff == -1 || diffz < mindiff) {
            mindiff = diffz;
            mina = idx;
            minb = prev;
        }
    }

    ll ans = 0;
    priority_queue<ppll, vector<ppll>, greater<ppll>> pq;
    pq.push(make_pair(mindiff, make_pair(mina, minb)));
    while (!pq.empty()) {
        ll diff = pq.top().first;
        ll a = pq.top().second.first;
        ll b = pq.top().second.second;
        pq.pop();
        if (visited[a] && visited[b]) {
            continue;
        }
        visited[a] = 1;
        visited[b] = 1;
        ans += diff;
        for (pii p : graph[a]) {
            if (visited[p.second]) {
                continue;
            }
            pq.push(make_pair(p.first, make_pair(a, p.second)));
        }
        for (pii p : graph[b]) {
            if (visited[p.second]) {
                continue;
            }
            pq.push(make_pair(p.first, make_pair(b, p.second)));
        }
    }
    printf("%lld\n", ans);
}
