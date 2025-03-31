#include<cstdio>
#include<utility>
#define pii pair<int, int>
#define ll long long
using namespace std;
int ccw(pii p1, pii p2, pii p3) {
    ll c1 = ((ll)p1.first * p2.second + p2.first * p3.second + p3.first * p1.second) - (p2.first * p1.second + p3.first * p2.second + p1.first * p3.second);
    if (c1 == 0) {
        return 0;
    }
    return c1 > 0 ? 1 : -1;
}
int main() {
    int x1, y1, x2, y2, x3, y3, x4, y4;
    scanf("%d %d %d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);
    pii p1 = make_pair(x1, y1);
    pii p2 = make_pair(x2, y2);
    pii p3 = make_pair(x3, y3);
    pii p4 = make_pair(x4, y4);
    printf("%d\n", ccw(p1, p2, p3) * ccw(p1, p2, p4) < 0 ? 1 : 0);
}