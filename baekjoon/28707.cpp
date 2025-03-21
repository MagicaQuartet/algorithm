#include<cstdio>
#include<string>
#include<vector>
#include<map>
#include<queue>
#include<utility>
#include<algorithm>
#define pii pair<int, int>
#define psi pair<string, int>
using namespace std;
int N, M;
int A[10];
vector<pair<pii, int>> ops;
int next_node = 1;
map<string, int> nodes;
map<string, int> dp;
struct cmp {
    bool operator()(psi a, psi b) {
        return a.second > b.second;
    }
};
string to_str() {
    string s = "";
    for (int i = 0; i < N; i++) {
        s.push_back(A[i] < 10 ? A[i] + '0' : 'A');
    }
    return s;
}
// 1-based
string swap_pos(string s, int p1, int p2) {
    string ret(s.begin(), s.end());
    ret[p1 - 1] = s[p2 - 1];
    ret[p2 - 1] = s[p1 - 1];
    return ret;
}
int get_node(string s) {
    map<string, int>::iterator it = nodes.find(s);
    if (it == nodes.end()) {
        nodes[s] = next_node++;
        return next_node - 1;
    }
    return it->second;
}
int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", A + i);
    }
    scanf("%d", &M);
    for (int i = 0; i < M; i++) {
        int p, q, c;
        scanf("%d %d %d", &p, &q, &c);
        ops.push_back(make_pair(make_pair(p, q), c));
    }

    string start = to_str();
    sort(A, A + N);
    string end = to_str();
    priority_queue<psi, vector<psi>, cmp> pq;
    pq.push(make_pair(start, 0));
    while (!pq.empty()) {
        string node_str = pq.top().first;
        int dist = pq.top().second;
        pq.pop();
        map<string, int>::iterator dp_it = dp.find(node_str);
        if (dp_it != dp.end() && dp_it->second <= dist) {
            continue;
        }
        dp[node_str] = dist;
        for (pair<pii, int> op : ops) {
            int p1 = op.first.first;
            int p2 = op.first.second;
            int cost = op.second;
            string next_node_str = swap_pos(node_str, p1, p2);
            pq.push(make_pair(next_node_str, dist + cost));
        }
    }

    map<string, int>::iterator ans = dp.find(end);
    printf("%d\n", ans == dp.end() ? -1 : ans->second);
}
