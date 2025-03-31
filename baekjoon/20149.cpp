#include<cstdio>
#include<utility>
#include<algorithm>
#define pii pair<ll, ll>
#define ll long long
using namespace std;
int ccw(pii p1, pii p2, pii p3) {
    ll c1 = (p1.first * p2.second + p2.first * p3.second + p3.first * p1.second) - (p2.first * p1.second + p3.first * p2.second + p1.first * p3.second);
    if (c1 == 0) {
        return 0;
    }
    return c1 > 0 ? 1 : -1;
}
// NOTE: 두 ccw가 모두 0이어도 일직선 상에 존재하는 선분이 아닐 수 있다. 네 점 중 겹치는 점이 있다면 기울기가 달라도 그렇게 될 수 있다. 그런 경우인지 확인하는 함수.
bool check_common(pii p1, pii p2, pii p3, pii p4) {
    double dx1 = p2.first - p1.first;
    double dy1 = p2.second - p1.second;
    double dx2 = p4.first - p3.first;
    double dy2 = p4.second - p3.second;
    if (p1 != p3 && p1 != p4 && p2 != p3 && p2 != p4) {
        return false;
    }
    pii point;
    if (p1 == p3 || p1 == p4) {
        point = p1;
    }
    else {
        point = p2;
    }
    if ((dx1 == 0 && dx2 == 0) || (dy1 / dx1 == dy2 / dx2)) {
        return false;
    }
    printf("1\n%lld %lld\n", point.first, point.second);
    return true;
}
void find_point(pii p1, pii p2, pii p3, pii p4) {
    // NOTE: 항상 한 점에서만 만날 것으로 기대함
    double dx1 = p2.first - p1.first;
    double dy1 = p2.second - p1.second;
    double dx2 = p4.first - p3.first;
    double dy2 = p4.second - p3.second;
    double x, y;
    if (dx1 == 0) {
        x = p1.first;
        y = (p1.first - p3.first) * dy2 / dx2 + p3.second;
    }
    else if (dx2 == 0) {
        x = p3.first;
        y = (p3.first - p1.first) * dy1 / dx1 + p1.second;
    }
    else if (dy1 == 0) {
        x = (p1.second - p3.second) * dx2 / dy2 + p3.first;
        y = p1.second;
    }
    else if (dy2 == 0) {
        x = (p3.second - p1.second) * dx1 / dy1 + p1.first;
        y = p3.second;
    }
    else {
        x = (dy1 * p1.first / dx1 - dy2 * p3.first / dx2 - p1.second + p3.second) / (dy1 / dx1 - dy2 / dx2);
        y = (dx1 * p1.second / dy1 - dx2 * p3.second / dy2 - p1.first + p3.first) / (dx1 / dy1 - dx2 / dy2);
    }
    printf("1\n%.9f %.9f\n", x, y);
}
int main() {
    ll x1, y1, x2, y2, x3, y3, x4, y4;
    scanf("%lld %lld %lld %lld %lld %lld %lld %lld", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);
    pii p1 = make_pair(x1, y1);
    pii p2 = make_pair(x2, y2);
    pii p3 = make_pair(x3, y3);
    pii p4 = make_pair(x4, y4);
    int c1 = ccw(p1, p2, p3);
    int c2 = ccw(p1, p2, p4);
    int c3 = ccw(p3, p4, p1);
    int c4 = ccw(p3, p4, p2);
    int ccw1 = c1 * c2;
    int ccw2 = c3 * c4;
    if (ccw1 == 0 && ccw2 == 0) {
        // 네 점 중 하나에서 만나거나
        if (check_common(p1, p2, p3, p4)) {
            return 0;
        }
        // 평행이며 일직선 상에 있음
        pii minp1 = min(p1, p2);
        pii maxp2 = max(p1, p2);
        pii minp3 = min(p3, p4);
        pii maxp4 = max(p3, p4);
        if (maxp2 == minp3) {
            printf("1\n%lld %lld\n", maxp2.first, maxp2.second);
        }
        else if (maxp4 == minp1) {
            printf("1\n%lld %lld\n", maxp4.first, maxp4.second);
        }
        else if (minp3 < maxp2 && minp1 < maxp4) {
            printf("1\n");
        }
        else {
            printf("0\n");
        }
    }
    else if (ccw1 <= 0 && ccw2 <= 0) {
        // 선분이 어떤 한 점에서 만남
        find_point(p1, p2, p3, p4);
    }
    else {
        // 선분끼리 만나지 않음
        printf("0\n");
    }
}
