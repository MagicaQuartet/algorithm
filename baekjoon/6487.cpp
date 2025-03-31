#include<cstdio>
#include<utility>
#include<algorithm>
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
void find_point(pii p1, pii p2, pii p3, pii p4) {
    // NOTE: 항상 한 점에서만 만날 것으로 기대함
    double dx1 = p2.first - p1.first;
    double dy1 = p2.second - p1.second;
    double dx2 = p4.first - p3.first;
    double dy2 = p4.second - p3.second;
    double x, y;
    if (dx1 == 0) {
        // case 1: line 1이 y축에 평행
        x = p1.first;
        y = -p3.first * dy2 / dx2 + p3.second;
    }
    else if (dx2 == 0) {
        // case 2: line 2가 y축에 평행
        x = p3.first;
        y = -p1.first * dy1 / dx1 + p1.second;
    }
    else {
        x = (dy1 * p1.first / dx1 - dy2 * p3.first / dx2 - p1.second + p3.second) / (dy1 / dx1 - dy2 / dx2);
        y = (dx1 * p1.second / dy1 - dx2 * p3.second / dy2 - p1.first + p3.first) / (dx1 / dy1 - dx2 / dy2);
    }
    printf("POINT %.2f %.2f\n", x, y);
}
int main() {
    int N;
    int x1, y1, x2, y2, x3, y3, x4, y4;
    scanf("%d", &N);
    while (N--) {
        scanf("%d %d %d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);
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
            // 평행 겹침
            printf("LINE\n");
        }
        else if (ccw1 == 0 || ccw2 == 0) {
            // 네 점 중 하나에서 만남
            pii point;
            if (c1 == 0) {
                point = p3;
            }
            else if (c2 == 0) {
                point = p4;
            }
            else if (c3 == 0) {
                point = p1;
            }
            else {
                point = p2;
            }
            printf("POINT %d.00 %d.00\n", point.first, point.second);
        }
        else if (ccw1 < 0 && ccw2 < 0) {
            // 선분이 어떤 한 점에서 만남
            find_point(p1, p2, p3, p4);
        }
        else {
            // 일단 선분끼리는 만나지 않음
            int dx1 = p2.first - p1.first;
            int dy1 = p2.second - p1.second;
            int dx2 = p4.first - p3.first;
            int dy2 = p4.second - p3.second;
            if (dx1 == 0 && dx2 == 0) {
                if (p1.first == p3.first) {
                    // 직선을 그으면 동일한 y축에 평행한 직선
                    printf("LINE\n");
                }
                else {
                    // 겹치지 않는 y축에 평행한 직선
                    printf("NONE\n");
                }
            }
            else if (dx1 * dy2 == dx2 * dy1) {
                // 기울기가 같고 겹치지 않는 직선
                printf("NONE\n");
            }
            else {
                // 직선을 그으면 어디선가는 만난다
                find_point(p1, p2, p3, p4);
            }
        }
    }
}