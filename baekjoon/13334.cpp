#include<cstdio>
#include<vector>
#include<queue>
#define ll long long
#define MINPOS -1*100000001
#define MAXPOS 100000001
#define pli pair<ll, int>
using namespace std;
int n;
ll d;
ll start[100010];
struct cmp {
    bool operator()(pli a, pli b) {
        if (a.first == b.first) {
            return start[a.second] != MINPOS;
        }
        return a.first > b.first;
    }
};
int main() {
    scanf("%d", &n);
    priority_queue<pli, vector<pli>, cmp> unread;
    priority_queue<pli, vector<pli>, cmp> read;
    for (int i = 1; i <= n; i++) {
        ll h, o;
        scanf("%lld %lld", &h, &o);
        unread.push({ h, i });
        unread.push({ o, i });
        start[i] = MINPOS;
    }
    scanf("%lld", &d);

    int ans = 0;
    int _ans = 0;
    ll lhs = unread.top().first;
    start[unread.top().second] = lhs;
    read.push(unread.top());
    unread.pop();
    while (!unread.empty()) {
        ll pos = unread.top().first;
        int num = unread.top().second;
        unread.pop();
        while ((lhs + d < pos) && !read.empty()) {
            ll _lhs = read.top().first;
            ll _num = read.top().second;
            if (start[_num] != MAXPOS) {
                start[_num] = MAXPOS;
            }
            else {
                _ans--;
            }
            read.pop();
            lhs = read.top().first;
        }
        if (start[num] == MINPOS) {
            if (read.empty()) {
                lhs = pos;
            }
            read.push({ pos, num });
            start[num] = pos;
        }
        else if (start[num] != MAXPOS) {
            start[num] = MAXPOS;
            _ans++;
            if (ans < _ans) {
                ans = _ans;
            }
        }
    }
    printf("%d\n", ans);
}
