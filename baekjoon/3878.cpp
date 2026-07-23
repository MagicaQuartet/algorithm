#include<cstdio>
#include<utility>
#include<vector>
#include<queue>
#include<algorithm>
#define ll long long
#define pll pair<ll, ll>
using namespace std;
struct pllcmp {
    bool operator() (pll a, pll b) {
        return a.second != b.second ? a.second > b.second : a.first > b.first;
    }
};
int ccw(pll p1, pll p2, pll p3) {
    ll c = (p1.first * p2.second + p2.first * p3.second + p3.first * p1.second) - (p2.first * p1.second + p3.first * p2.second + p1.first * p3.second);
    if (c == 0) {
        return 0;
    }
    return c > 0 ? 1 : -1;
}
bool intersect(pll p1, pll p2, pll p3, pll p4) {
    int c1 = ccw(p1, p2, p3) * ccw(p1, p2, p4);
    int c2 = ccw(p3, p4, p1) * ccw(p3, p4, p2);
    if (c1 == 0 && c2 == 0) {
        pll minb = min(p1, p2);
        pll maxb = max(p1, p2);
        pll minw = min(p3, p4);
        pll maxw = max(p3, p4);
        return minb <= maxw && minw <= maxb;
    }
    return c1 <= 0 && c2 <= 0;
}
bool check_intersect(vector<pll>& black, vector<pll>& white) {
    if (black.size() <= 1 || white.size() <= 1) {
        // inner 검사에서 검증될 것이다
        return true;
    }
    for (int blhs = 0; blhs < black.size(); blhs++) {
        for (int brhs = blhs + 1; brhs < black.size(); brhs++) {
            for (int wlhs = 0; wlhs < white.size(); wlhs++) {
                for (int wrhs = wlhs + 1; wrhs < white.size(); wrhs++) {
                    if (intersect(black[blhs], black[brhs], white[wlhs], white[wrhs])) {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}
bool check_inner(vector<pll>& black, vector<pll>& white) {
    pll outerb = make_pair(black[0].first, -1);
    for (int wlhs = 0; wlhs < white.size(); wlhs++) {
        for (int wrhs = wlhs + 1; wrhs < white.size(); wrhs++) {
            if (intersect(outerb, black[0], white[wlhs], white[wrhs])) {
                return false;
            }
        }
    }
    pll outerw = make_pair(white[0].first, -1);
    for (int blhs = 0; blhs < black.size(); blhs++) {
        for (int brhs = blhs + 1; brhs < black.size(); brhs++) {
            if (intersect(outerw, white[0], black[blhs], black[brhs])) {
                return false;
            }
        }
    }
    return true;
}
int main() {
    int T, n, m;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        vector<pll> black, white;
        black.reserve(n);
        white.reserve(m);
        for (int i = 0; i < n; i++) {
            int x, y;
            scanf("%d %d", &x, &y);
            black.push_back(make_pair(x, y));
        }
        for (int i = 0; i < m; i++) {
            int x, y;
            scanf("%d %d", &x, &y);
            white.push_back(make_pair(x, y));
        }
        if (n == 0 || m == 0) {
            printf("YES\n");
            continue;
        }
        // 각 그룹에서 볼록 껍질만 골라낸다
        vector<pll> black_convex, white_convex;
        priority_queue<pll, vector<pll>, pllcmp> bpq;
        priority_queue<pll, vector<pll>, pllcmp> wpq;
        if (n == 1) {
            black_convex.push_back(black[0]);
        }


        bool cond_intersect = true;
        if (black.size() > 1 && white.size() > 1) {

        }
        bool cond_inner = true;
        if (black.size() > 1 || white.size() > 1) {

        }
        printf("%s\n", cond_intersect && cond_inner ? "YES" : "NO");
    }
}