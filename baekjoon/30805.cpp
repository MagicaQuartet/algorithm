#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
int N, M;
int A[101], B[101];
vector<int> ans;
struct cmp {
    bool operator()(pair<int, int> a, pair<int, int> b) {
        if (a.first == b.first) {
            return a.second > b.second;
        }
        return a.first < b.first;
    }
};
int main() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
        pq.push(make_pair(A[i], i));
    }
    scanf("%d", &M);
    for (int i = 0; i < M; i++) {
        scanf("%d", &B[i]);
    }
    int alhs = 0;
    int blhs = 0;
    while (!pq.empty()) {
        int n = pq.top().first;
        int idx = pq.top().second;
        pq.pop();
        if (idx < alhs) {
            continue;
        }
        for (int i = blhs; i < M; i++) {
            if (n == B[i]) {
                blhs = i + 1;
                alhs = idx;
                ans.push_back(n);
                break;
            }
        }
    }
    printf("%zu\n", ans.size());
    for (auto n : ans) {
        printf("%d ", n);
    }
    printf("\n");
}